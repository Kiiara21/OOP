#include "Table.h"


void Table::addRow(Row* row) {
    m_table.push_back(row);
}

void Table::addEmptyRow(int numberOfCells){
    Row* emptyRow = new Row;
    for(int i = 0; i < numberOfCells; ++i){
        emptyRow->addEmptyCell();
    }

    m_table.push_back(emptyRow);
}


void Table::printTable() const {

    std::vector<int> columnWidths(m_table[0]->getSize(), 0);

    for (const Row* row : m_table) {
        for (size_t col = 0; col < row->getSize(); col++) {
            if (row->operator[](col)->getValueAsString().length() > columnWidths[col]) {
                columnWidths[col] = row->operator[](col)->getValueAsString().length();
            }
        }
    }

    for (const Row* row : m_table) {
        for (size_t col = 0; col < row->getSize(); col++) {
            std::cout << std::setw(columnWidths[col]) << std::right << row->operator[](col)->getValueAsString() << " | ";
        }
        std::cout << std::endl;
    }
}

void Table::serializeTable(std::ofstream& os) {
    convertFormulasInTable();
    for(int i = 0; i < m_table.size(); ++i){
        m_table[i]->serializeRow(os);
    }
    std::cout << "\nSerialising table successful!\n\n";
}

void Table::deserializeTable(std::ifstream &is) {

    std::cout << "\nDeserializing table ... \n\n";
    
    std::string line;
    
    while (std::getline(is, line)) {
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

    std::cout << "\nDeserialising table successful!\n\n";
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

void Table::convertFormulasInTable(){
    for(int i = 0; i < getSize(); ++i){
        m_table[i]->convertFormulasInRow();
    }
}

void Table::clear(){
    for(Row* row : m_table){
        delete row;
    }
    m_table.clear();
}