#include "table.h"

void Table::copy(const Table& other){
    m_table = new (std::nothrow) Cell* [other.m_rows];
    for(int i = 0; i < other.m_rows; ++i){
        m_table[i] = new (std::nothrow) Cell [other.m_cols];
    }

    for(int i = 0; i < other.m_rows; ++i){
        for(int j = 0; j < other.m_cols; ++j){
            m_table[i][j] = other.m_table[i][j];
        }
    }

    m_rows = other.m_rows;
    m_cols = other.m_cols;
}

void Table::erase(){
    for(int i = 0; i < m_rows; ++i){
        delete[] m_table[i];
    }

    delete[] m_table;
}   

Table::Table(){
    m_rows = INITIAL_ROWS;
    m_cols = INITIAL_COLS;

    m_table = new (std::nothrow) Cell<int>* [m_rows];
    for(int i = 0; i < m_rows; ++i){
        m_table[i] = new (std::nothrow) Cell [m_cols];
    }
}

Table::Table(const Table& other){
    copy(other);
}

Table& Table::operator=(const Table& other){
    if(&other != this){
        erase();
        copy(other);
    }
    return *this;
}

Table::~Table(){
    erase();
}

// std::ostream& operator << (std::ostream& out, const Table& table){
//     out << table.m_rows;
//     out << table.m_cols;

//     for(int i = 0; i < table.m_rows; ++i){
//         for(int j = 0; j < table.m_cols; ++j){
//             out << table.m_table[i][j];
//         }
//     }
// }

// std::istream& operator >> (std::istream& in, Table& table){
//     in >> table.m_rows;
//     in >> table.m_cols;

//     for(int i = 0; i < table.m_rows; ++i){
//         for(int j = 0; j < table.m_cols; ++j){
//             in >> table.m_table[i][j];
//         }
//     }
// }