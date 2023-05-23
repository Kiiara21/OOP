#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Cell {

public:

    Cell() = default;

    virtual Cell* clone() = 0;

    virtual std::string getValueAsString() const = 0;

    virtual void serializeCell(std::ofstream& os) = 0;

    virtual ~Cell() = default;
    
};