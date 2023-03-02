#include <iostream>

const int MAX = 1024;

char toLower(char ch){
    return ch - ('A' - 'a');
}

char toUpper(char ch){
    return ch + ('A' - 'a');
}

void toLowerCase(char* str){
    for(int i = 0; str[i] != '\0'; ++i){
        str[i] = toLower(str[i]);
    }
}

void toUpperCase(char* str){
    for(int i = 0; str[i] != '\0'; ++i){
        str[i] = toUpper(str[i]);
    }
}

void transform(char* str, void (*function) (char*)){
    function(str);
}

int main(){

    char str[MAX];
    std::cin.getline(str, MAX);

    // transform(str, toLowerCase);
    transform(str, toUpperCase);


    std::cout << str;
    return 0;
}