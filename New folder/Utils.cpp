#include "Utils.h"

size_t Utils::countLinesInFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        size_t lineCount = 0;
        std::string line;
        while (std::getline(inputFile, line)) {
            lineCount++;
        }
        inputFile.close();
        return lineCount;
    } else {
        std::cout << "Failed to open the file for readng" << std::endl;
        return 0; 
    }
}

bool Utils::isInteger(const std::string& str) {
    if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
        return false;

    char* endPtr = nullptr;
    strtol(str.c_str(), &endPtr, 10);

    return (*endPtr == '\0');
}

bool Utils::isDouble(const std::string& str) {
    if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
        return false;

    char* endPtr = nullptr;
    strtod(str.c_str(), &endPtr);

    return (*endPtr == '\0');
}

bool Utils::isEmptyString(const std::string& str){
    return str.empty();
}

bool Utils::hasSign(const std::string& str){
    return str[0] == '-' || str[0] == '+';
}


bool Utils::isPositive(const std::string& str){
    return str[0] == '+';
}
bool Utils::isNegative(const std::string& str){
    return str[0] == '-';
}

