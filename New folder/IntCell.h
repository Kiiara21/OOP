#pragma once
#include "Cell.h"

class IntCell : public Cell {

private:

    int m_data;

public:

    IntCell() : Cell(), m_data(0) {}

    IntCell(const int data);

    virtual Cell* clone() override final;

    virtual std::string getValueAsString() const override final {return std::to_string(m_data); }

    void print() const override final;

    void serializeCell(std::ofstream& os) override final;

    friend std::istream& operator>>(std::istream& in, IntCell& cell);

};