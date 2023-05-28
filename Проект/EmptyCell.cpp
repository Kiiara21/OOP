#include "EmptyCell.h"

Cell* EmptyCell::clone(){
    return new EmptyCell();
}

EmptyCell::EmptyCell(const std::string emptyString){
    m_emptyString = emptyString;
}


void EmptyCell::print() const{
    std::cout << m_emptyString;
}

void EmptyCell::serializeCell(std::ofstream &os) {
    os << m_emptyString << ",";
}

std::istream& operator>>(std::istream& in, EmptyCell& cell){
    in >> cell.m_emptyString;
    return in;
}
