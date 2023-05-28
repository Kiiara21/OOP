#include "Table.h"

void Table::addRow(Row* row) {
    m_table.push_back(row);
}

void Table::addEmptyRow(int numberOfCells) {
    Row* emptyRow = new Row;
    try {
        for (size_t i = 0; i < numberOfCells; ++i) {
            emptyRow->addEmptyCell();
        }
        m_table.push_back(emptyRow);
    } 
    catch (const std::exception& e) {
        std::cout << "\nError adding empty row: " << e.what() << std::endl;
        delete emptyRow;
    }
}

void Table::printTable() const {
    if (m_table.empty()) {
        std::cout << "Table is empty." << std::endl;
        return;
    }
    std::vector<int> columnWidths(m_table[0]->getSize(), 0);

    for (const Row* row : m_table) {
        for (size_t col = 0; col < row->getSize(); col++) {
            if (row->operator[](col)->getValueAsString().length() > columnWidths[col]) {
                columnWidths[col] = row->operator[](col)->getValueAsString().length();
            }
        }
    }   
    std::cout << getSize();

    for (const Row* row : m_table) {
        for (size_t col = 0; col < row->getSize(); col++) {
            std::cout << row->operator[](col)->getValueAsString() << " | ";
        }
        std::cout << std::endl;
    }
}

void Table::serializeTable(std::ofstream& os) {
    convertFormulasInTable();
    try {
        for (size_t i = 0; i < m_table.size(); ++i) {
            m_table[i]->serializeRow(os);
        }
        std::cout << "\nSerializing table successful!\n\n";
    } catch (const std::exception& e) {
        std::cout << "Error serializing table: " << e.what() << std::endl;
    }
}

void Table::deserializeTable(std::ifstream& is) {
    clear();
    std::string line;
    try {
        while (std::getline(is, line, '\n')) {
            std::vector<std::string> rowValues;
            std::stringstream ss(line);
            std::string value;

            while (std::getline(ss, value, ',')) {
                rowValues.push_back(value);
            }

            Row* row = new Row;
            row->setElements(rowValues);
            addRow(row);
        }
        std::cout << "\nDeserializing table successful!\n\n";
    } catch (const std::exception& e) {
        std::cout << "Error deserializing table: " << e.what() << std::endl;
    }
}

Row* Table::operator[](size_t index){
    try {
        if (index >= m_table.size()) {
            throw std::out_of_range("\nInvalid index");
        }
        return m_table[index];
    } catch (const std::out_of_range& e) {
        std::cout << "\nError: " << e.what() << std::endl;
        return nullptr;
    }
}

const Row* Table::operator[](size_t index) const{
    try {
        if (index >= m_table.size()) {
            throw std::out_of_range("\nInvalid index");
        }
        return m_table[index];
    } catch (const std::out_of_range& e) {
        std::cout << "\nError: " << e.what() << std::endl;
        return nullptr;
    }
}

Cell* Table::makeCellFromFormula(std::string referenceRowIndex, std::string referenceColumnIndex){
    Cell* cellInFormula = nullptr;
    if(std::stoi(referenceRowIndex) > getSize() - 1 || std::stoi(referenceColumnIndex) > m_table.operator[](std::stoi(referenceRowIndex))->getSize() - 1){
        cellInFormula = new EmptyCell(); 
    }
    else cellInFormula = m_table.operator[](std::stoi(referenceRowIndex))->operator[](std::stoi(referenceColumnIndex));
    return cellInFormula;
}

void Table::convertFormulasInTable() {
    try {
        for (size_t i = 0; i < getSize(); ++i) {
            for (int j = 0; j < m_table[i]->getSize(); ++j) {
                std::string currCell = m_table[i]->operator[](j)->getValueAsString();
                if (Utils::isFormula(currCell) && Utils::hasReferencesOfCells(currCell)) {
                    std::string firstReferenceRowIndex, firstReferenceColumnIndex;
                    std::string secondReferenceRowIndex, secondReferenceColumnIndex;

                    Utils::getIndexOfCellInReferences(currCell, firstReferenceRowIndex, firstReferenceColumnIndex, secondReferenceRowIndex, secondReferenceColumnIndex);

                    const char operation = Utils::getOperation(currCell);

                    Cell* firstCellInFormula = makeCellFromFormula(firstReferenceRowIndex, firstReferenceColumnIndex);
                    Cell* secondCellInFormula = makeCellFromFormula(secondReferenceRowIndex, secondReferenceColumnIndex);

                    std::string literalsFormula = "=" + Utils::translateCell(firstCellInFormula->getValueAsString()) + operation + Utils::translateCell(secondCellInFormula->getValueAsString());
                    Cell* convertedCell = Utils::convertedValue(literalsFormula);
                    m_table[i]->addAtPosition(j, convertedCell);
                }
                else if (Utils::isFormula(currCell) && Utils::hasOnlyLiterals(currCell)) {
                    Cell* convertedCell = Utils::convertedValue(currCell);
                    m_table[i]->addAtPosition(j, convertedCell);
                }
            }
        }
    } 
    catch (const std::exception& e) {
        std::cout << "Error converting formulas: " << e.what() << std::endl;
    }
}

void Table::clear(){
    for(Row* row : m_table){
        delete row;
    }
    m_table.clear();
}