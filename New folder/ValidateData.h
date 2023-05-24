#pragma once
#include <string>
#include "Utils.h"

class Validate {

public:

    static bool inNumberHasOnlyOneDot(const std::string& number);
    static bool inValidNumberHasOnlyNumbers(const std::string& number);
    static bool isValidData(const std::string& str);
    static bool isLetter(const char& ch);
    static bool isWord(const std::string& str);
};