#include "StringCell.h"

StringCell::StringCell(const std::string data) : Cell(), m_data(data) {}

Cell* StringCell::clone(){
    return new StringCell(m_data);
}

void StringCell::print() const{
    std::cout << m_data;
}

void StringCell::serializeCell(std::ofstream& os){
    os << m_data << ",";
}

std::istream& operator>>(std::istream& in, StringCell& cell){
    std::getline(in, cell.m_data, ',');
    return in;
}
