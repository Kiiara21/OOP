#include "DoubleCell.h"

DoubleCell::DoubleCell(const double data) : m_data(data){}

Cell* DoubleCell::clone(){
    return new DoubleCell(m_data);
}

void DoubleCell::print() const{
    std::cout << m_data;
}

std::string DoubleCell::getValueAsString() const {
    std::string strValue = std::to_string(m_data);
    std::regex regexPattern("(\\.[0-9]*[1-9])?0*$");
    std::string trimmedValue = std::regex_replace(strValue, regexPattern, "$1");
    return trimmedValue;
}

void DoubleCell::serializeCell(std::ofstream& os){
    os << m_data << ",";
}

std::istream& operator>>(std::istream& in, DoubleCell& cell){
    in >> cell.m_data;
    return in;
}
