#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Cell {

protected:

    std::string m_emptyString;

public:

    Cell();

    Cell(std::string emptyString) : m_emptyString(emptyString){}

    virtual Cell* clone();

    virtual void print() const;

    virtual std::string getValueAsString() const {return m_emptyString; }

    virtual void serializeCell(std::ofstream& os);

    friend std::istream& operator>>(std::istream& in, Cell& cell);

    virtual ~Cell() = default;
    
};