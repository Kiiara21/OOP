#pragma once
#include <vector>
#include <fstream>
#include "Cell.h"
using std::vector;

class Row {

private:

    vector <Cell> m_row;

public: 

    Row() = default;

    void addCell(const Cell& cellToAdd);
    // void removeCell(const unsigned int id);
     
    void printRow() const;

    size_t getSize() const { return m_row.size(); }

    friend std::ostream operator<<(std::ostream& out, const Row& row);

}; 

void Row::addCell(const Cell& cellToAdd){
    m_row.push_back(cellToAdd);
}

// void Row::removeCell(cosnt unsigned int id){
//     size_t size = getSize();
//     for(int i = 0; i < size; ++i){
//         if(i == id){
//             // naprawi m_row[i] prazna kletka
//         }
//     }
// }

void Row::printRow() const{
    size_t size = getSize();
    for(int i = 0; i < size; ++i){
        m_row[i].printData();
    }
}

std::ostream operator<<(std::ostream& out, const Row& row){
    size_t size = row.getSize();
    for(int i = 0; i < size; ++i){
        out << row.m_row[i];
    }
}