#pragma once
#include <fstream>
#include <iostream>
#include "cell.h"

const size_t INITIAL_ROWS = 2;
const size_t INITIAL_COLS = 2;

class Table {

private:

    Cell** m_table;
    unsigned int m_rows, m_cols;

    void copy(const Table& other);
    void erase();

public:

    Table();
    Table(const Table& other);
    Table& operator=(const Table& other);
    ~Table();

    friend std::ostream& operator << (std::ostream& out, const Table& table);
    friend std::istream& operator >> (std::istream& in, Table& table);

}; 
