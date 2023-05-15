#include "Cell.h"

Cell::Cell(){
    emptyString = "";
}

Cell* Cell::clone(){
    return new Cell();
}

void Cell::print() const{
    std::cout << emptyString;
}

void Cell::writeToFile(const std::string& fileName) {
    std::ofstream file(fileName, std::ios::app);
    if(!file.is_open()){
        std::cout << "catch ex";
        return;
    }
    file << emptyString << "|";
}