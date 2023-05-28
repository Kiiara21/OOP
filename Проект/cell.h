#pragma once
#include <string>
#include <fstream>

class Cell {

public:

    virtual Cell* clone() = 0;

    virtual std::string getValueAsString() const = 0;

    virtual void serializeCell(std::ofstream& os) = 0;

    virtual ~Cell() = default;
    
};