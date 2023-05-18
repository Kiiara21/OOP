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

void Row::add(Cell* cell) {
    m_row.push_back(cell);
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


bool isInteger(const std::string& str) {
    if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
        return false;

    char* endPtr = nullptr;
    strtol(str.c_str(), &endPtr, 10);

    return (*endPtr == '\0');
}

bool isDouble(const std::string& str) {
    if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
        return false;

    char* endPtr = nullptr;
    strtod(str.c_str(), &endPtr);

    return (*endPtr == '\0');
}

bool isEmptyString(const std::string& str){
    return str.empty();
}


void deserializeRow(const std::string& fileName, Row& row) {
    row.erase();
    std::ifstream inputFile(fileName, std::ios::binary);
    if (inputFile.is_open()) {
        
        std::vector<std::string> words;
        std::string line;

        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string word;

            while (std::getline(ss, word, ',')) {
                words.push_back(word);
            }
        }

        inputFile.close();

        for (const auto& word : words) {
            if (word != "\n"){
                if (isEmptyString(word)){
                    Cell* cell = new Cell(); 
                    row.add(cell);
                    // std::cout << "\nadding empty cell... ---> " << word;
                }
                else if(isInteger(word)){
                    Cell* cell = new IntCell(std::stoi(word)); 
                    row.add(cell);
                    // std::cout << "\nadding int cell... ---> " << word;
                }
                else if (isDouble(word)){
                    Cell* cell = new DoubleCell(std::stod(word)); 
                    row.add(cell);
                    // std::cout << "\nadding double cell... ---> " << word;
                }
                else {
                    Cell* cell = new StringCell(word); 
                    row.add(cell);
                    // std::cout << "\nadding string cell... ---> " << word;
                }
                // todo if word is a formula
            }
        }
    }
    else {
        std::cout << "Failed to open the file for reading." << std::endl;
    }
}
