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

bool Utils::isLetter(const char& ch){
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool Utils::isWord(const std::string& str){ // a word has only letters and \ and "
    for(int i = 0; i < str.size(); ++i){
        if(!(isLetter(str[i])) && str[i] != '\\' && str[i] != '\"' && str[i] != ' '){
            return false;
        }
    }
    return true;
}

bool Utils::isErrorString(const std::string& str){
    return str == "ERROR";
}

bool Utils::isArithmeticOperation(const char& ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
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

bool Utils::hasOnlyLiterals(const std::string& str){
    for(const char& ch : str){
        if(!isNumber(ch) && !isArithmeticOperation(ch) && ch != '='){
            return false;
        }
    }
    return true;
}

bool Utils::hasReferencesOfCells(const std::string& str){
    for(int i = 1; i < str.size(); ++i){
        if(str[i] == 'R'){
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

std::string Utils::tanslateCell(const std::string& cellValue){
    if(isWord(cellValue) || isEmptyString(cellValue) || isErrorString(cellValue)) return "0";
    else return cellValue;
}

Cell* Utils::convertedValue(const std::string& str){
    size_t strSize = str.size();
    double firstNumber, secondNumber, result = 0;

    unsigned int operationPosition = getOperationPosition(str);
    char operation = getOperation(str);

    firstNumber = std::stod(str.substr(1, operationPosition - 1));  
    secondNumber = std::stod(str.substr(operationPosition + 1, strSize - operationPosition));

    if (operation == '+') {
        result = firstNumber + secondNumber;
    } else if (operation == '-') {
        result = firstNumber - secondNumber;
    } else if (operation == '*') {
        result = firstNumber * secondNumber;
    } else if (operation == '/') {
        if (secondNumber == 0){
            Cell* errorCell = new StringCell("ERROR");
            result = 0.0;
            return errorCell;
        }
        else {
            result = firstNumber / secondNumber;
        }
    }
    else result = pow(firstNumber, secondNumber);
    if (std::isinf(result)) {
        result = 0;
    }
    Cell* doubleCell = new DoubleCell(result);
    return doubleCell;
}

void Utils::removeRandL(const std::string& str, std::string& rowIndex, std::string& colIndex){

    size_t rPosition = str.find('R');
    size_t cPosition = str.find('C');

    if(rPosition != std::string::npos && cPosition != std::string::npos && rPosition < cPosition){
        rowIndex = str.substr(rPosition + 1, cPosition - rPosition - 1);
        colIndex = str.substr(cPosition + 1);
    }
}

const char& Utils::getOperation(const std::string& str){
    return str[getOperationPosition(str)];
}

const unsigned int Utils::getOperationPosition(const std::string& str){
    int operationPosition;
    if(str[1] == '+' || str[1] == '-'){
        operationPosition = 2;
    }
    else operationPosition = 1;
    
    while(!isArithmeticOperation(str[operationPosition])){
        operationPosition++;
    }
    return operationPosition;
}

void Utils::getIndexOfCellInReferences(const std::string& str, std::string& firstCellRow, std::string& firstCellColumn,
                                                                std::string& secondCellRow, std::string& secondCellColumn){
    
    const unsigned int operationPosition = getOperationPosition(str);

    std::string firstReference, secondReference;

    if(operationPosition != std::string::npos){
        firstReference = str.substr(1, operationPosition - 1);
        secondReference = str.substr(operationPosition + 1);
    }
    else {
        firstReference = "";
        secondReference = "";
    }

    removeRandL(firstReference, firstCellRow, firstCellColumn);
    removeRandL(secondReference, secondCellRow, secondCellColumn);
}

 
