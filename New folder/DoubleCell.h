#pragma once
#include "Cell.h"

class DoubleCell : public Cell {

private:

    double m_data;

public:

    DoubleCell(const double data);

    virtual Cell* clone() override final;

    void print() const override final;

    void writeToFile(const std::string& fileName) override final;
};