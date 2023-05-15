// #pragma once
// #include <vector>
// #include "Row.h"
// using std::vector;

// class Table {

// private:

//     vector <Row> m_rows;

// public: 

//     Table() = default;

//     void addCell(const int rowToAddIn, const Cell& cellToAdd);
//     void removeCell(const int rowToAddIn, const unsigned int id);
     
//     void printTable() const;

//     size_t getSize() const { return m_rows.size(); }
// }; 

// void Table::addCell(const int rowToAddIn, const Cell& cellToAdd){
//     size_t size = getSize();
//     for(int i = 0; i < size; ++i){
//         if(i == rowToAddIn){
//             m_rows[i].addCell(cellToAdd);
//         }
//     }
// }

// void Table::removeCell(const int rowToRemoveFrom, const unsigned int id){
//     size_t size = getSize();
//     for(int i = 0; i < size; ++i){
//         if(i == rowToAddIn){
//             m_rows[i].removeCell(id);
//         }
//     }
// }


// void Table::printTable() const{
//     size_t size = getSize();
//     for(int i = 0; i < size; ++i){
//         m_rows[i].printRow();
//     }
// }

