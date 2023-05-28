#pragma once
#include <vector>
#include <sstream>
#include <iomanip>
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "EmptyCell.h"
#include "ValidateData.h"
#include "Utils.h"

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
    void addAtPosition(size_t index, Cell* newCell);

    void setElements(std::vector<std::string> rowElement);
    
    void serializeRow(std::ofstream& os);

    Cell* operator[](size_t index);
    const Cell* operator[](size_t index) const;

    size_t getSize() const { return m_row.size(); }
    unsigned int getId() { return m_rowId; }
};
