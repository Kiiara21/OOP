#pragma once
#include "Row.h"

class Table {

private:

    std::vector<Row*> m_table;

public:

    void addRow(Row* row);

    void printTable() const;

    const std::vector<Row*>& getTable() const { return m_table; }

    void serializeTable(const std::string& fileName);

    void deserializeTable(const std::string& fileName);
};
