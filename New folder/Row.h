#pragma once
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "EmptyCell.h"
#include "ValidateData.h"
#include"Utils.h"
#include <vector>
#include <cassert>
#include <iomanip>

class Row {
    
private:   

    static unsigned int s_counter;
    unsigned int m_rowId;

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
    
    void addAtPosition(int index, Cell* newCell);

    const std::vector<Cell*>& getCells() { return m_row; };
    std::vector<std::string> getRowElements(const std::string& fileName);
    const size_t getMaxCellSize();

    void setElements(std::vector<std::string> rowElement);
    
    // void erase(int index); to do

    void serializeRow(std::ofstream& os);

    Cell* operator[](size_t index);
    const Cell* operator[](size_t index) const;

    size_t getSize() const { return m_row.size(); }

};
