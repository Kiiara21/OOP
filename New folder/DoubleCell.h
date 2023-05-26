#pragma once
#include <regex>
#include "Cell.h"
#include "IPrintable.h"

class DoubleCell : public Cell, public IPrintable {

private:

    double m_data;

public:

    DoubleCell() : m_data(0.0) {}

    DoubleCell(const double data);

    virtual Cell* clone() override final;

    virtual std::string getValueAsString() const override final;

    void print() const override final;

    void serializeCell(std::ofstream &os) override final;

    friend std::istream& operator>>(std::istream& in, DoubleCell& cell);

};