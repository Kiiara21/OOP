#pragma once
#include <iostream>
#include "Cell.h"
#include "Utils.h"
#include "IPrintable.h"

class StringCell : public Cell, public IPrintable {

private:

    std::string m_data;

public:

    StringCell() : m_data("") {}

    StringCell(const std::string data);

    Cell* clone() override final;

    std::string getValueAsString() const override final { return m_data; }

    void print() const override final;

    void serializeCell(std::ofstream& os) override final;

    friend std::istream& operator>>(std::istream& in, StringCell& cell);

};