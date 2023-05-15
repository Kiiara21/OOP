#pragma once
#include "Cell.h"

class IntCell : public Cell {

private:

    int m_data;

public:

    IntCell(const int data);

    virtual Cell* clone() override final;

    void print() const override final;

    void writeToFile(const std::string& fileName) override final;
};
