#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "cmath"
#include "DoubleCell.h"
#include "IntCell.h"
#include "StringCell.h"

class Utils{

public:

    static bool isArithmeticOperation(const char& ch);  
    static bool isNumber(const char& ch);
    static size_t countLinesInFile(const std::string& fileName);

    static bool isInteger(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isEmptyString(const std::string& str);
    static bool isFormula(const std::string& str);

    static bool hasSign(const std::string& str);
    static bool isPositive(const std::string& str);
    static bool isNegative(const std::string& str);

    static bool hasOnlyLiterals(const std::string& str);
    static bool hasReferencesOfCells(const std::string& str);

    static double calculateResult(double firstNumber, double secondNumber, char operation);
    static Cell* convertedValue(const std::string& str);

    static bool containsOnlyDoubleNumbers(const std::string& str);
    static bool containsIntegerAndDoubleNumbers(const std::string& str);
    static bool containsDoubleAndIntegerNumbers(const std::string& str);

    static bool hasDevisionByZero(const std::string& str);

};