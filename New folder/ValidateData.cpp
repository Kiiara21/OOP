#include "ValidateData.h"


bool Validate::inNumberHasOnlyOneDot(const std::string& number){
    int dotCount = 0;
    for (char ch : number){
        if(ch == '.'){
            dotCount++;
            if(dotCount > 1){
                return false;
            }
        }
    }
    return true;
}

bool Validate::inValidNumberHasOnlyNumbers(const std::string& number){
    int i = Utils::hasSign(number) ? 1 : 0;

    for (; i < number.size(); ++i){ 
        if(!Utils::isNumber(number[i]) && number[i] != '.'){
            return false;
        }
    }
    return true;
}

bool Validate::isLetter(const char& ch){
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool Validate::isWord(const std::string& str){ // a word has only letters and \ and "
    for(int i = 0; i < str.size(); ++i){
        if(!(isLetter(str[i])) && str[i] != '\\' && str[i] != '\"'){
            return false;
        }
    }
    return true;
}

bool Validate::isValidData(const std::string& str){
    return ((inNumberHasOnlyOneDot(str) && inValidNumberHasOnlyNumbers(str)) || isWord(str) || Utils::isFormula(str));
}