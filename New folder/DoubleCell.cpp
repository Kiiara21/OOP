#include "DoubleCell.h"

DoubleCell::DoubleCell(const double data) : Cell(), m_data(data){}

Cell* DoubleCell::clone(){
    return new DoubleCell(m_data);
}

void DoubleCell::print() const{
    std::cout << m_data;
}

void DoubleCell::serializeCell(std::ofstream& os){
    os << m_data << ",";
}

std::istream& operator>>(std::istream& in, DoubleCell& cell){
    in >> cell.m_data;
    return in;
}
