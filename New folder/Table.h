#pragma once
#include "Row.h"

class Table{

private:

    Row** m_table;
    size_t m_numberOfRows;
    size_t m_capacity;
    
    static const size_t INITIAL_CAPACITY = 2;
    static const size_t INCREASE_STEP = 2;

    void resize();

    void copy(const Table& other);

    void erase();

public:

    Table();

    ~Table();

    Table(const Table& other);
    Table(const Table&& other);

    Table& operator=(const Table& other);
    Table& operator=(const Table&& other);
    
    void addRow(Row *rowToAdd);

    void writeTableInFile(const std::string& fileName);

    size_t getSize() const { return m_numberOfRows; }
    
};
