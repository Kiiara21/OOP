#pragma once
#include "Cell.h"

class DoubleCell : public Cell {

private:

    double m_data;

public:

    DoubleCell() : Cell(), m_data(0.0) {}

    DoubleCell(const double data);

    virtual Cell* clone() override final;

    virtual std::string getValueAsString() const override final {return std::to_string(m_data); }

    void print() const override final;

    void serializeCell(std::ofstream &os) override final;

    friend std::istream& operator>>(std::istream& in, DoubleCell& cell);

};