#include "DoubleCell.h"

DoubleCell::DoubleCell(const double data) : Cell(), m_data(data){}

Cell* DoubleCell::clone(){
    return new DoubleCell(m_data);
}

void DoubleCell::print() const{
    std::cout << m_data;
}

void DoubleCell::writeToFile(const std::string& fileName){
    std::ofstream file(fileName, std::ios::app);
    if(!file.is_open()){
        std::cout << "catch ex";
        return;
    }
    file << m_data << "|";
}