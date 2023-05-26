#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include "cmath"
#include "DoubleCell.h"
#include "IntCell.h"
#include "StringCell.h"

class Utils{

public:

    static bool isArithmeticOperation(const char& ch);  
    static bool isNumber(const char& ch);
    static size_t countLinesInFile(const std::string& fileName);
    static bool isWord(const std::string& str);
    static bool isLetter(const char& ch);
    static bool isErrorString(const std::string& str);

    static bool isInteger(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isEmptyString(const std::string& str);
    static bool isFormula(const std::string& str);
    
    static bool hasSign(const std::string& str);
    static bool isPositive(const std::string& str);
    static bool isNegative(const std::string& str);

    static bool hasOnlyLiterals(const std::string& str);
    static bool hasReferencesOfCells(const std::string& str);

    static Cell* convertedValue(const std::string& str);
    static void removeRandC(const std::string& str, std::string& rowIndex, std::string& colIndex);
    static void getIndexOfCellInReferences (const std::string& str, std::string& firstCellRow, std::string& firstCellColumn,
                                                                    std::string& secondCellRow, std::string& secondCellColumn);
    static std::string translateCell(const std::string& cellValue);

    static const char& getOperation(const std::string& str);
    static const unsigned int getOperationPosition(const std::string& str);

};