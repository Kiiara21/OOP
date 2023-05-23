#pragma once
#include "Row.h"

class Table {

private:

    std::vector<Row*> m_table;

public:

    void addRow(Row* row);

    void printTable() const;

    const std::vector<Row*>& getTable() const { return m_table; }
    
    size_t getSize() const { return m_table.size(); }

    Row* operator[](size_t index);
    const Row* operator[](size_t index) const;


    void serializeTable(std::ofstream& os);

    void deserializeTable(std::ifstream &is);
    
    void clear();
};
