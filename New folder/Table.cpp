#include "Table.h"

void Table::resize(){
    Row** newTable = new Row*[m_capacity * INCREASE_STEP];
    for(int i = 0; i < m_numberOfRows; ++i){
        newTable[i] = m_table[i];
    }

    delete[] m_table;
    m_table = newTable;
    m_capacity *= INCREASE_STEP;
}

void Table::copy(const Table& other){
    m_table = new Row*[other.m_capacity];
    for(int i = 0; i < m_numberOfRows; ++i){
        m_table[i] = other.m_table[i];
    }
    m_numberOfRows = other.m_numberOfRows;
    m_capacity = other.m_capacity;
}

void Table::erase(){
    for(int i = 0; i < m_numberOfRows; ++i){
        delete m_table[i];
    }
    delete[] m_table;
}

Table::Table(){
    m_table = new Row*[INITIAL_CAPACITY];
    m_numberOfRows = 0;
    m_capacity = INITIAL_CAPACITY;
}

Table::~Table(){
    erase();
}

Table::Table(const Table& other){
    copy(other);
}

Table::Table(const Table&& other){
    m_table = std::move(other.m_table);
    m_capacity = other.m_capacity;
    m_numberOfRows = other.m_numberOfRows;
}

Table& Table::operator=(const Table& other){
    if(&other != this){
        erase();
        copy(other);
    }

    return *this;
}

Table& Table::operator=(const Table&& other){
    if(&other != this){
        m_table = std::move(other.m_table);
        m_numberOfRows = other.m_numberOfRows;
        m_capacity = other.m_capacity;
    }
    return *this;
}   

void Table::addRow(Row *rowToAdd){
    if(m_numberOfRows == m_capacity){
        resize();
    }
    m_table[m_numberOfRows++] = rowToAdd;
}

void Table::writeTableInFile(const std::string& fileName){
    for(int i = 0; i < m_numberOfRows; ++i){
        m_table[i]->writeRowToFile(fileName);
    }
}
