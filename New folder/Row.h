#pragma once
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include <vector>
#include <cassert>

class Row {
    
private:

    std::vector<Cell*> m_row;

    void copy(const Row& other);
    void erase();
    void add(Cell* cell);

public:

    Row();
    Row(const Row& other);
    Row& operator=(const Row& other);
    ~Row();

    void addEmptyCell();

    void addIntCell(const int& data);

    void addStringCell(const std::string& data);

    void addDoubleCell(const double& data);

    const std::vector<Cell*>& getCells() { return m_row; };
    friend std::vector<std::string> rowElements(const std::string& fileName, Row& row);

    void printRow() const;

    void serializeRow(const std::string& fileName);

    friend void deserializeRow(const std::string& fileName, Row& row);

    Cell* operator[](size_t index);
    const Cell* operator[](size_t index) const;

    size_t getSize() const { return m_row.size(); }

};
