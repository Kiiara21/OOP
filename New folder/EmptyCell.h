#pragma once
#include "Cell.h"

class EmptyCell : public Cell {

private:
    
    std::string m_emptyString;

public:

    EmptyCell() : m_emptyString("") {}

    EmptyCell(const std::string m_emptyString);

    virtual Cell* clone() override final;

    virtual std::string getValueAsString() const override final { return m_emptyString; }

    void print() const override final;

    void serializeCell(std::ofstream &os) override final;

    friend std::istream& operator>>(std::istream& in, EmptyCell& cell);
};