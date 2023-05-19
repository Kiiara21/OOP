#include "StringCell.h"

StringCell::StringCell(const string data) : Cell(), m_data(data) {}

Cell* StringCell::clone(){
    return new StringCell(m_data);
}

void StringCell::print() const{
    std::cout << m_data;
}

void StringCell::serializeCell(const std::string& fileName){
    std::ofstream file(fileName, std::ios::app);
    if(!file.is_open()){
        std::cout << "catch ex";
        return;
    }
    if(Utils::isEmptyString(m_data) || Utils::isInteger(m_data) || Utils::isDouble(m_data)){
        file << m_data << ",";
    }
    std::cout << "Invalid string data!";
}

std::istream& operator>>(std::istream& in, StringCell& cell){
    in >> cell.m_data;
    return in;
}
