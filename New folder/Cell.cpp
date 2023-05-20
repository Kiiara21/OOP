#include "Cell.h"

Cell::Cell(){
    m_emptyString = "";
}

Cell* Cell::clone(){
    return new Cell();
}

void Cell::print() const{
    // std::cout << "\nprinting empty cell...";
    std::cout << m_emptyString;
}

void Cell::serializeCell(const std::string& fileName) {
    std::ofstream file(fileName, std::ios::app);
    if(!file.is_open()){
        std::cout << "catch ex";
        return;
    }
    file << m_emptyString << ",";
}

std::istream& operator>>(std::istream& in, Cell& cell){
    in >> cell.m_emptyString;
    return in;
}

