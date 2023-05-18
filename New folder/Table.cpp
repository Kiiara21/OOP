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
}


size_t countLinesInFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        size_t lineCount = 0;
        std::string line;
        while (std::getline(inputFile, line)) {
            lineCount++;
        }
        inputFile.close();
        return lineCount;
    } else {
        std::cout << "Failed to open the file for readng" << std::endl;
        return 0; 
    }
}

void Table::deserializeTable(const std::string& fileName) {
    size_t numberOfRows = countLinesInFile(fileName);
    std::cout << numberOfRows << "\n";
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
    std::cout << m_table.size();
        for(int i = 0; i < numberOfRows; ++i){
            Row* row = new Row; 
            deserializeRow(fileName, *row);
            addRow(row);
        }
        inputFile.close();
    }
    else {
        std::cout << "Failed to open the file for reading" << std::endl;
    }
}