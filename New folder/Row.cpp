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

void Row::addAtPosition(int index, Cell* newCell) {
    try {
        if (index > getSize()) {
            throw std::out_of_range("Invalid index");
        }

        m_row.erase(m_row.begin() + index);
        m_row.insert(m_row.begin() + index, newCell);
    } 
    catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}
 
void Row::printRow(size_t offset) const {
    for (const Cell* cell : m_row) {
        // std::cout << "curr cell size:" << cell->getValueAsString().size();
        int temp = (offset - cell->getValueAsString().size()) / 2;
        // offset = cell->getValueAsString().size() / 2 - offset;

        for(int i = 0; i < temp; ++i){
            std::cout << " ";
        }
        std::cout << "|";
        for(int i = 0; i < temp; ++i){
            std::cout << " ";
        }
        cell->print();
    }
    std::cout << std::endl;
}

void Row::serializeRow(std::ofstream& os){
    for(int i = 0; i < m_row.size(); ++i){
        m_row[i]->serializeCell(os);
    }
    os << "\n";
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

const size_t Row::getMaxCellSize(){
    size_t maxCellSize = 0;
    for(Cell* cell : m_row){
        size_t currCellSize = cell->getValueAsString().size();
        std::cout << currCellSize << "\n"; 
        if(currCellSize > maxCellSize){
            maxCellSize = currCellSize;
        }
    }
    return maxCellSize;
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

Cell* Row::operator[](size_t index) {
    try {
        if (index >= m_row.size()) {
            throw std::out_of_range("\nInvalid index");
        }
        return m_row[index];
    } catch (const std::out_of_range& e) {
        std::cout << "\nError: " << e.what() << std::endl;
        return nullptr;
    }
}

const Cell* Row::operator[](size_t index) const{
    try {
        if (index >= m_row.size()) {
            throw std::out_of_range("\nInvalid index");
        }
        return m_row[index];
    } catch (const std::out_of_range& e) {
        std::cout << "\nError: " << e.what() << std::endl;
        return nullptr;
    }
}
