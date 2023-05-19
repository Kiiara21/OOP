#include "ValidateData.h"

bool Validate::isNumber(const char& ch){
    return (ch >= '0' && ch <= '9');
}

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
        if(!isNumber(number[i]) && number[i] != '.'){
            return false;
        }
    }
    return true;
}

bool Validate::isValidString(const std::string& str){
    return (inNumberHasOnlyOneDot(str) && inValidNumberHasOnlyNumbers(str));
}