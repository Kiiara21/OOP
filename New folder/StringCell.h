#pragma once
#include "Cell.h"
#include "Utils.h"

class StringCell : public Cell {

private:

    std::string m_data;

public:

    StringCell() : Cell(), m_data("") {}

    StringCell(const std::string data);

    Cell* clone() override final;

    std::string getValueAsString() const override final { return m_data; }

    void print() const override final;

    void serializeCell(std::ofstream& os) override final;

    friend std::istream& operator>>(std::istream& in, StringCell& cell);

};