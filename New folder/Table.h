#pragma once
#include "Row.h"

class Table {

private:

    std::vector<Row*> m_table;

    Cell* makeCellFromFormula(std::string referenceRowIndex, std::string referenceColumnIndex);
    void convertFormulasInTable();

public:

    void addRow(Row* row);
    void addEmptyRow(int numberOfCells);

    void printTable() const;

    size_t getSize() const { return m_table.size(); }

    Row* operator[](size_t index);
    const Row* operator[](size_t index) const;

    void serializeTable(std::ofstream& os);
    void deserializeTable(std::ifstream &is);

    void clear();
};