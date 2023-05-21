#include "Table.h"


void Table::addRow(Row* row) {
    m_table.push_back(row);
}

void Table::printTable() const {
    for (const Row* row : m_table) {
        row->printRow();
    }
    std::cout << std::endl;
}

void Table::serializeTable(const std::string& fileName) {
    std::ofstream outputFile(fileName, std::ios::binary);
    if (outputFile.is_open()) {
        for(int i = 0; i < m_table.size(); ++i){
            m_table[i]->serializeRow(fileName);
        }
        outputFile.close();
    }
    else {
        std::cout << "Failed to open the file for writing" << std::endl;
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
    assert(index < m_table.size());
    return m_table[index];
}

const Row* Table::operator[](size_t index) const{
    assert(index < m_table.size());
    return m_table[index];
}

void Table::clear(){
    for(Row* row : m_table){
        delete row;
    }
    m_table.clear();
}