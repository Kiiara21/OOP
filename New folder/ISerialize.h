#pragma once
#include <fstream>

class ISerialize{
public:

    virtual void serialize(std::ofstream& os) = 0;

    virtual void deserialize(std::ifstream &is) = 0;
       
};