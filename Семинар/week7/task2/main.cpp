#include "developer.h"

int main(){
    Developer dev;
    srand(time(0));
    int randomNumber = rand() % 9000 + 1000;
    
    dev.init(randomNumber, "Blabla", "BLABLA", Position::QA);

    std::ofstream file("fileToRead.txt");
    if(file.is_open()){
       dev.writeInFile(file);
    }
    file.close();

    Developer dev2; 

    std::ifstream fileToRead("fileToRead.txt");
    dev2.readFromFile(fileToRead);
    fileToRead.close();

    std::ofstream fileToWrite("fileToWrite.txt", std::ios::app);
    if(fileToWrite.is_open()){
       dev2.writeInFile(fileToWrite);
    }
    fileToWrite.close();
}   