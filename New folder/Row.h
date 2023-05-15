#pragma once
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"

class Row {

private:

    static const size_t INITIAL_CAPACITY = 2;
    static const size_t INCREASE_STEP = 2;

    Cell** m_row;
    size_t m_size;
    size_t m_capacity;

    void resize();

    void copy(const Row& other);

    void erase();

    void add(Cell* cell);

public:
    Row();
    
    Row(const Row& other);

    Row& operator=(const Row& other);

    ~Row();

    void AddEmptyCell();

    void addIntCell(const int data);

    void addStringCell(const string data);

    void addDoubleCell(const double data);

    void printRow() const;

    void writeRowToFile(const std::string& fileName);
};
