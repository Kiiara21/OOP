#pragma once
#include "Cell.h"

class StringCell : public Cell {

private:

    string m_data;

public:

    StringCell(const string data);

    virtual Cell* clone() override final;

    void print() const override final;

    void writeToFile(const std::string& fileName) override final;
};
