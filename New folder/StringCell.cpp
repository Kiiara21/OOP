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
    file << m_data << ",";
}

std::istream& operator>>(std::istream& in, StringCell& cell){
    in >> cell.m_data;
    return in;
}
