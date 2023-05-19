#include "Row.h"

void Row::copy(const Row& other) {
    size_t otherSize = other.m_row.size();
    m_row.reserve(otherSize);
    for (Cell* cell : other.m_row) {
        m_row.push_back(cell->clone());
    }
}

void Row::erase() {
    for (Cell* cell : m_row) {
        delete cell;
    }
    m_row.clear();
}

Row::Row(const Row& other) {
    copy(other);
}

Row& Row::operator=(const Row& other) {
    if (&other != this) {
        erase();
        copy(other);
    }
    return *this;
}

Row::Row() {
    
}

Row::~Row() {
    erase();
}

void Row::add(Cell* cell) {
    m_row.push_back(cell);
}

void Row::addEmptyCell() {
    add(new Cell());
}

void Row::addIntCell(const int& data) {
    add(new IntCell(data));
}

void Row::addStringCell(const std::string& data) {
    add(new StringCell(data));
}

void Row::addDoubleCell(const double& data) {
    add(new DoubleCell(data));
}

void Row::printRow() const {
    for (const Cell* cell : m_row) {
        cell->print();
        std::cout << " | ";
    }
    std::cout << std::endl;
}

void Row::serializeRow(const std::string& fileName){
    std::ofstream file(fileName, std::ios::app);
    if(!file.is_open()){
        std::cout << "catch ex";
        return;
    }
    for(int i = 0; i < m_row.size(); ++i){
        m_row[i]->serializeCell(fileName);
    }
    file << "\n";
}

std::vector<std::string> rowElements(const std::string& fileName, Row& row){
    row.erase();
    std::vector<std::string> words;
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        
        std::string line;

        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string word;

            while (std::getline(ss, word, ',')) {
                std::cout << word << std::endl;
                words.push_back(word);
            }
        }

        inputFile.close();
        
    }   
    else {
        std::cout << "Failed to open the file for reading." << std::endl;
    }

    return words;
} // todo fix it

void deserializeRow(const std::string& fileName, Row& row) {
    
    std::vector<std::string> words = rowElements(fileName, row);

    // std::cout << words.size() << std::endl;

    for (int i = 0; i < words.size(); ++i) {
        if (words[i] != "\n"){
            if (Utils::isEmptyString(words[i])){
                Cell* cell = new Cell(); 
                row.add(cell);
                std::cout << "\nadding empty cell... ---> " << words[i];
            }
            else if(Utils::isInteger(words[i])){
                if (Utils::hasSign(words[i]) && Utils::isNegative(words[i])){
                    Cell* cell = new IntCell(0 - std::stoi(words[i])); 
                    row.add(cell);
                    std::cout << "\nadding negative int cell... ---> " << words[i];
                }
                else {
                    Cell* cell = new IntCell(std::stoi(words[i])); 
                    row.add(cell);
                    std::cout << "\nadding int cell... ---> " << words[i];
                }
            }
            else if (Utils::isDouble(words[i])){
                if (Utils::hasSign(words[i]) && Utils::isNegative(words[i])){
                    Cell* cell = new DoubleCell(0 - std::stod(words[i])); 
                    row.add(cell);
                    std::cout << "\nadding negative double cell... ---> " << words[i];
                }
                else {
                    Cell* cell = new DoubleCell(std::stod(words[i])); 
                    row.add(cell);
                    std::cout << "\nadding double cell... ---> " <<words[i];
                }
            }
            else {
                if (Utils::isEmptyString(words[i]) || Utils::isInteger(words[i]) || Utils::isDouble(words[i])){
                    Cell* cell = new StringCell(words[i]); 
                    row.add(cell);
                    std::cout << "\nadding string cell... ---> " << words[i];
                }
                else std::cout << "\nUnvalid data in column " << i;
            }
            // todo if word is a formula
        }
    }

}
