#include "Table.h"


void Table::addRow(Row* row) {
    m_table.push_back(row);
}

void Table::printTable() const {
    size_t maxCellSizeOnRow = 0;

    for (int i = 0 ; i < getSize(); ++i){
        size_t currMaxSize = m_table[i]->getMaxCellSize();
        if(currMaxSize > maxCellSizeOnRow){
            maxCellSizeOnRow = currMaxSize;
        }
    }   

    size_t offset = maxCellSizeOnRow;
    
    for (const Row* row : m_table) {
        row->printRow(offset);
    }
    std::cout << std::endl;
}

void Table::serializeTable(std::ofstream& os) {
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
        std::cout << "\nAdding row in table...\n" << std::endl;
        addRow(row);
        std::cout << getSize() << "\n";
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

void Table::clear(){
    for(Row* row : m_table){
        delete row;
    }
    m_table.clear();
}