#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Utils{

public:

    static size_t countLinesInFile(const std::string& fileName);

    static bool isInteger(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isEmptyString(const std::string& str);

    static bool hasSign(const std::string& str);
    static bool isPositive(const std::string& str);
    static bool isNegative(const std::string& str);

};