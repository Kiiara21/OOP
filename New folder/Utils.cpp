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
    if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')) || isInteger(str))
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
    return (str[0] == '+' || !(hasSign(str)));
}
bool Utils::isNegative(const std::string& str){
    return str[0] == '-';
}

bool Utils::isFormula(const std::string& str){
    return str[0] == '=';
}

bool Utils::isNumber(const char& ch){
    return (ch >= '0' && ch <= '9');
}

bool Utils::isArithmeticOperation(const char& ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

bool Utils::hasOnlyLiterals(const std::string& str){
    for(const char& ch : str){
        if(!isNumber(ch) && !isArithmeticOperation(ch) && ch != '='){
            return false;
        }
    }
    return true;
}

bool Utils::hasReferencesOfCells(const std::string& str){
    for(const char& ch : str){
        if(ch == 'R'){
            return true;
        }    
    }
    return false;
}

bool Utils::containsOnlyDoubleNumbers(const std::string& str){
    unsigned int dotCounter = 0;
    for(const char& ch : str){
        if(ch == '.'){
            dotCounter++;
        }
    }

    return dotCounter == 2;
}

bool Utils::containsIntegerAndDoubleNumbers(const std::string& str){
    unsigned int dotCounter = 0, dotPosition;
    unsigned int signPosition;

    for(int i = 0; i < str.size(); ++i){
        if(isArithmeticOperation(str[i])){
            signPosition = i;
            break;
        }
    }

    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '.'){
            dotCounter++;
            dotPosition = i;
        }
    }
    return (dotCounter == 1 && (dotPosition > signPosition));
}

bool Utils::containsDoubleAndIntegerNumbers(const std::string& str){
    unsigned int dotCounter = 0, dotPosition;
    unsigned int signPosition;

    for(int i = 0; i < str.size(); ++i){
        if(isArithmeticOperation(str[i])){
            signPosition = i;
            break;
        }
    }

    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '.'){
            dotCounter++;
            dotPosition = i;
        }
    }
    return (dotCounter == 1 && (dotPosition < signPosition));
}

Cell* Utils::convertedValue(const std::string& str){
    size_t strSize = str.size();
    char operation;
    int i = 1;

    if(containsOnlyDoubleNumbers(str)){
        double firstNumber;
        double secondNumber;
        double result;

        while(!isArithmeticOperation(str[i])){
            i++;
        }
        operation = str[i];
        firstNumber = std::stod(str.substr(1, i - 1));
        secondNumber = std::stod(str.substr(i + 1, str.size() - i));
        
        if (operation == '+') {
            result = firstNumber + secondNumber;
        } else if (operation == '-') {
            result = firstNumber - secondNumber;
        } else if (operation == '*') {
            result = firstNumber * secondNumber;
        } else if (operation == '/') {
            result = firstNumber / secondNumber;
        }
        else result = pow(firstNumber, secondNumber);

        i = 1;
        Cell* doubleCell = new DoubleCell(result);
        return doubleCell;
    }

    else if(containsIntegerAndDoubleNumbers(str)){
        int firstNumber;
        double secondNumber;
        double result;

        while(!isArithmeticOperation(str[i])){
            i++;
        }
        operation = str[i];
        firstNumber = std::stoi(str.substr(1, i - 1));
        secondNumber = std::stod(str.substr(i + 1, str.size() - i));
        if (operation == '+') {
            result = firstNumber + secondNumber;
        } else if (operation == '-') {
            result = firstNumber - secondNumber;
        } else if (operation == '*') {
            result = firstNumber * secondNumber;
        } else if (operation == '/') {
            result = firstNumber / secondNumber;
        }
        else result = pow(firstNumber, secondNumber);
        i = 1;

        Cell* doubleCell = new DoubleCell(result);
        return doubleCell;
    }

    else if(containsDoubleAndIntegerNumbers(str)){
        double firstNumber;
        int secondNumber;
        double result;

        while(!isArithmeticOperation(str[i])){
            i++;
        }
        operation = str[i];
        firstNumber = std::stod(str.substr(1, i - 1));
        secondNumber = std::stoi(str.substr(i + 1, str.size() - i));

        if (operation == '+') {
            result = firstNumber + secondNumber;
        } else if (operation == '-') {
            result = firstNumber - secondNumber;
        } else if (operation == '*') {
            result = firstNumber * secondNumber;
        } else if (operation == '/') {
            result = firstNumber / secondNumber;
        }
        else result = pow(firstNumber, secondNumber);
        i = 1;

        Cell* doubleCell = new DoubleCell(result);
        return doubleCell;
    }

    else {
        int firstNumber;
        int secondNumber;
        int result;

        while(!isArithmeticOperation(str[i])){
            i++;
        }
        operation = str[i];
        firstNumber = std::stoi(str.substr(1, i - 1));
        secondNumber = std::stoi(str.substr(i + 1, str.size() - i));

        if (operation == '+') {
            result = firstNumber + secondNumber;
        } else if (operation == '-') {
            result = firstNumber - secondNumber;
        } else if (operation == '*') {
            result = firstNumber * secondNumber;
        } else if (operation == '/') {
            result = firstNumber / secondNumber;
        }
        else result = pow(firstNumber, secondNumber);
        i = 1;

        Cell* intCell = new IntCell(result);
        return intCell;
    }
}


bool Utils::hasDevisionByZero(const std::string& str){
    double secondNumber;
    int i = 1;
    while(!isArithmeticOperation(str[i])){
        i++;
    }
    char operation = str[i];
    secondNumber = std::stod(str.substr(i + 1, str.size() - i));
    return (secondNumber == 0 && operation == '/');
}
