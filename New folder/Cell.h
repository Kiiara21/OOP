#pragma once
#include <iostream>
#include <fstream>
#include <string>
using std::string;

class Cell {

protected:

    string emptyString;

public:

    Cell();

    virtual Cell* clone();

    virtual void print() const;

    virtual void writeToFile(const std::string& fileName);
    
    virtual ~Cell() = default;
};
