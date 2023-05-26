#include "Row.h"

unsigned int Row::s_counter = 1;

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
    m_rowId = s_counter++;
}

Row::~Row() {
    erase();
}

void Row::add(Cell* cell) {
    std::string value = cell->getValueAsString();
    if (Validate::isValidData(value)) {
        m_row.push_back(cell);
    } else {
        throw std::invalid_argument("row " + std::to_string(m_rowId) + ", col " + std::to_string(getSize()) + " " + cell->getValueAsString() + " is unknown data type!"); 
    }
}

void Row::addEmptyCell() {
    try {
        add(new EmptyCell());
    } catch (const std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }
}

void Row::addIntCell(const int& data) {
    try {
        add(new IntCell(data));
    } catch (const std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }
}

void Row::addDoubleCell(const double& data) {
    try {
        add(new DoubleCell(data));
    } catch (const std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }
}

void Row::addStringCell(const std::string& data) {
    try {
        add(new StringCell(data));
    } catch (const std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }
}

void Row::addAtPosition(size_t index, Cell* newCell) {
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

void Row::serializeRow(std::ofstream& os){
    for(Cell* cell : m_row){
        cell->serializeCell(os);
    }
    os << "\n";
}

void Row::setElements(std::vector<std::string> rowElements) {
    for (const std::string& value : rowElements) {
        try {
            if (Utils::isEmptyString(value)) {
                addEmptyCell();
            } else if (Utils::isInteger(value)) {
                addIntCell(std::stoi(value));
            } else if (Utils::isDouble(value)) {
                addDoubleCell(std::stod(value));
            } else {
                addStringCell(value);
            }
        } catch (const std::exception& e) {
            std::cout << "\nError: " << e.what() << std::endl;
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
