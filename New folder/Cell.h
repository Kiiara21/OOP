#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::string;

class Cell {

protected:

    string m_emptyString;

public:

    Cell();

    Cell(string emptyString) : m_emptyString(emptyString){}

    virtual Cell* clone();

    virtual void print() const;

    virtual std::string getValueAsString() const {return m_emptyString; }

    virtual void serializeCell(const std::string& fileName);

    friend std::istream& operator>>(std::istream& in, Cell& cell);

    virtual ~Cell() = default;
};
