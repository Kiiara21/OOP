#include "IntCell.h"

IntCell::IntCell(const int data) : Cell(), m_data(data){}

Cell* IntCell::clone(){
    return new IntCell(m_data);
}

void IntCell::print() const{
    std::cout << m_data;
}

void IntCell::serializeCell(const std::string& fileName){
    std::ofstream file(fileName, std::ios::app);
    if(!file.is_open()){
        std::cout << "catch ex";
        return;
    }
    file << m_data << ",";
}

std::istream& operator>>(std::istream& in, IntCell& cell){
    in >> cell.m_data;
    return in;
}
