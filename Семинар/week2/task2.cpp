#include <iostream>
#include <fstream>
#include <cstring>
#include "debug_new.h"

const size_t MAX_SIZE = 100;

size_t getSizeOfFile(std::ifstream& file){
    size_t currPos = file.tellg(); // save curr pos 
    file.seekg(0, std::ios::end); // move filePtr to the end
    size_t size = file.tellg(); // get curr pos (end of file)
    file.seekg(currPos); // move back to curr pos
    return size;
}

bool isUpperLetter(const char c){
    return (c >= 'A' && c <= 'Z');
}

bool isDownLetter(const char c){
    return (c >= 'a' && c <= 'z');
}

bool isLetter(const char c){
    return (isUpperLetter(c) || isDownLetter(c));
}

bool strCmp(char* first, char* second){
    size_t size = strlen(first);

    for(int i = 0; i < size; ++i){
        if(first[i] != second[i]){
            return false;
        }
    }

    return true;
}

void view(char* fileContent, size_t size){
    for(int i = 0; i < size; ++i){
        if(!isLetter(fileContent[i])){
            std::cout << ".";
        }
        else std::cout << fileContent[i];
    }
}

void change(char* fileContent, size_t size, int index, char ch){
    for(int i = 0; i < size; ++i){
        if(i == index){
            fileContent[i] = ch;
        }
    }
}

void remove(char* fileContent, size_t& size){
    fileContent[size--] = '\0';
    // size--; 
}

void add(char* fileContent, size_t& size, char ch){
    fileContent[size] = ch;
    size++;
}

void save(char* fileContent, size_t size){
    std::ofstream file("myData.dat", std::ios::binary);
    if(!file.is_open()){
        std::cout << "Error!";
        return;
    }
    file.write(fileContent, size);
    file.close();
}

void saveAs(std::ofstream& fileToSaveAt, const char* fileContent, size_t size){
    fileToSaveAt.write(fileContent, size);
}

void functionCall(char* fileContent, size_t size){
    char command[MAX_SIZE];

    do{
        std::cout << "\nEnter command (view/change/remove/add/save/saveAs/exit): ";
        std::cin >> command;
        if(strCmp(command, "view")){
            view(fileContent, size);   
        }

        else if(strCmp(command, "change")){
            int index;
            char ch;
            std::cout << "\nEnter index: ";
            std::cin >> index;
            std::cout << "\nEnter char to change with: ";
            std::cin >> ch;

            change(fileContent, size, index, ch);
        }

        else if(strCmp(command, "remove")){
            remove(fileContent, size);
        }

        else if(strCmp(command, "add")){
            char ch2;
            std::cout << "\nEnter char to add: ";
            std::cin >> ch2;
            add(fileContent, size, ch2);
        }

        else if(strCmp(command, "save")){
            save(fileContent, size);
        }

        else if(strCmp(command, "saveAs")){
            std::ofstream fileToSaveAt("myData2.dat", std::ios::binary);
            if(!fileToSaveAt.is_open()){
                std::cout << "Error!";
                return;
            }
            saveAs(fileToSaveAt, fileContent, size);
            fileToSaveAt.close();
        }
    } while (!strCmp(command, "exit"));
    
}

int main(){

    int x = 25409;
    std::ofstream file("myData.dat", std::ios::binary);
    file.write((const char*)&x, sizeof(x));
    file.close();

    std::ifstream ifile("myData.dat", std::ios::binary);
    if(!ifile.is_open()){
        std::cout << "Error!";
        return -1;
    }

    size_t sizeOfFile = getSizeOfFile(ifile);
    
    char* fileContent = new (std::nothrow) char(sizeOfFile);
    ifile.read(fileContent, sizeOfFile);

    functionCall(fileContent, sizeOfFile);

    delete[] fileContent;
    ifile.close();

    checkMemoryLeaks();
    return 0;
}