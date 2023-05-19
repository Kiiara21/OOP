#pragma once
#include <string>
#include "Utils.h"

class Validate {

public:

    static bool isNumber(const char& ch);
    static bool inNumberHasOnlyOneDot(const std::string& number);
    static bool inValidNumberHasOnlyNumbers(const std::string& number);
    static bool isValidString(const std::string& str);
};