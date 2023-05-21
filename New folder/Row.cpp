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
    std::string value = cell->getValueAsString();
    if (Validate::isValidData(value)) {
        m_row.push_back(cell);
    } else {
        throw std::invalid_argument("Invalid data!"); // Throw an exception with an error message
    }
}

void Row::addEmptyCell() {
    try {
        add(new Cell());
        std::cout << "\nadding empty cell... ---> ";
    } catch (const std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }
}

void Row::addIntCell(const int& data) {
    try {
        if (Utils::hasSign(std::to_string(data)) && Utils::isNegative(std::to_string(data))) {
            add(new IntCell(data));
            std::cout << "\nadding negative int cell... ---> " << data;
        } else {
            add(new IntCell(data));
            std::cout << "\nadding int cell... ---> " << data;
        }
    } catch (const std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }
}


void Row::addDoubleCell(const double& data) {
    try {
        if (Utils::hasSign(std::to_string(data)) && Utils::isNegative(std::to_string(data))) {
            add(new DoubleCell(data));
            std::cout << "\nadding negative double cell... ---> " << data;
        } else {
            add(new DoubleCell(data));
            std::cout << "\nadding double cell... ---> " << data;
        }
    } catch (const std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }
}

void Row::addStringCell(const std::string& data) {
    try {
        add(new StringCell(data));
        std::cout << "\nadding string cell... ---> " << data;
    } catch (const std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }
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

std::vector<std::string> Row::getRowElements(const std::string& fileName) {
    std::vector<std::string> words;
    std::ifstream inputFile(fileName);
    
    if (inputFile.is_open()) {
        std::string line;
        if (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string word;
            
            while (std::getline(ss, word, ',')) {
                std::cout << word << std::endl;
                words.push_back(word);
            }
        }
        
        inputFile.close();
    } else {
        std::cout << "Failed to open the file for reading." << std::endl;
    }
    
    return words;
}

void Row::setElements(std::vector<std::string> rowElements){
    for (const std::string& value : rowElements){
        if(Utils::isEmptyString(value)){
            addEmptyCell();
        }
        else if(Utils::isInteger(value)){
            addIntCell(std::stoi(value));
        }
        else if(Utils::isDouble(value)){
            addDoubleCell(std::stod(value));
        }
        else {
            addStringCell(value);
        }
    }
}

Cell* Row::operator[](size_t index){
    assert(index < m_row.size());
    return m_row[index];
}

const Cell* Row::operator[](size_t index) const{
    assert(index < m_row.size());
    return m_row[index];
}
