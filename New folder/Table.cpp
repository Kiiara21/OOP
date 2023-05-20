#include "Table.h"
#include "Utils.h"

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
    std::cout << "\nSerialising table successful!";
}

void Table::deserializeTable(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    std::cout << "\nDeserializing table ... \n\n";
    if (inputFile.is_open()) {
        std::string line;
        
        while (std::getline(inputFile, line)) {
            std::vector<std::string> rowValues;
            std::stringstream ss(line);
            std::string value;
            
            while (std::getline(ss, value, ',')) {
                rowValues.push_back(value);
            }
            
            Row* row = new Row;
            row->setElements(rowValues);
            // std::cout << "\nnew row size: " << row->getSize() << std::endl;
            // for (const Cell* cell : row->getCells()) {
            //     if(Utils::isEmptyString(cell->getValueAsString())){
            //         std::cout << "\nemtpy\n";
            //     }
            //     std::cout << cell->getValueAsString();
            //     std::cout << " | ";
            // }
            std::cout << "\nAdding row in table...\n" << std::endl;
            addRow(row);
            std::cout << getSize() << "\n";
        }
        
        inputFile.close();
    } else {
        std::cout << "Failed to open the file for reading." << std::endl;
    }
    std::cout << "\nDeserialising table successful!";
}


Row* Table::operator[](size_t index){
    assert(index < m_table.size());
    return m_table[index];
}

const Row* Table::operator[](size_t index) const{
    assert(index < m_table.size());
    return m_table[index];
}
