#pragma once
#include "Cell.h"

class StringCell : public Cell {

private:

    string m_data;

public:

    StringCell() : m_data("") {}

    StringCell(const string data);

    virtual Cell* clone() override final;

    virtual std::string getValueAsString() const override final { return m_data; }

    void print() const override final;

    void serializeCell(const std::string& fileName) override final;

    friend std::istream& operator>>(std::istream& in, StringCell& cell);

};
