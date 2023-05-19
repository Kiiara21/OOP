#pragma once
#include <string>
using std::string;

class Serialize { 

public:

    virtual void serialize(const std::string& fileName) = 0;

};