#include <iostream>
#include <fstream>
#include <cstring>
#include "debug_new.h"

const size_t MAX_STR_SIZE = 100;

struct Student{
    char firstName[MAX_STR_SIZE];
    char secondName[MAX_STR_SIZE];
    char email[MAX_STR_SIZE];
    char FN[11];
};

bool isValidFileName(char* fileName){
    size_t size = strlen(fileName) - 1;

    if(fileName[size] == 'v' &&
       fileName[size - 1] == 's' && 
       fileName[size - 2] == 'c')
    {
        return true;
    }

    return false;
}

bool cmpStr(char* first, char* second){
    size_t len = strlen(first);
    
    for(int i = 0; i < len; ++i){
        if(first[i] != second[i]){
            return false;
        }
    }
    return true;
}

bool isValidFN(char* FN){
    return strlen(FN) == 10;
}

size_t getFileSize(std::ifstream& file){
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t size = file.tellg();
	file.seekg(currentPos);
	return size;
}

size_t getNumberOfWords(char* text, size_t sizeOfFile){
    size_t words = 1;

    for(int i = 0; i < sizeOfFile; ++i){
        if(text[i] == ',' || text[i] == '\n'){
            words++;
        }
    }
    return words;
}

size_t getNumberOfStudents(char* text, size_t sizeOfFile){
    size_t rows = 1;

    for(int i = 0; i < sizeOfFile; ++i){
        if(text[i] == '\n'){
            rows++;
        }
    }
    return rows;
}

void initStudent(Student &student, const char* firstName, const char* secondName, const char* FN, const char* email){
    strcpy(student.firstName, firstName);
    strcpy(student.secondName, secondName);
    strcpy(student.FN, FN);
    strcpy(student.email, email);
}

Student* allocateStudents(size_t numberOfStudents, char** arrayOfWords){
    Student* arrayOfStudents = new Student[numberOfStudents];
    for(int i = 0, j = 0; i < numberOfStudents; ++i, j+=4){
        initStudent(arrayOfStudents[i], arrayOfWords[j], arrayOfWords[j+1], arrayOfWords[j+2], arrayOfWords[j+3]);
    }
    return arrayOfStudents;
}

void printStudent(Student& student){
    std::cout << student.firstName << " " << student.secondName << " " << student.FN << " " << student.email << std::endl;
}

char** separate(char* text, size_t numberOfWords){
    char** temp = new char*[numberOfWords];
    for(int i = 0; i < numberOfWords; ++i){
        temp[i] = new char[50];
    }

    int j = 0, k = 0;

    for(int i = 0; text[i] != '\0'; ++i){    
        while(text[i] != ',' && text[i] != '\n' && text[i] != '\0'){
            temp[k][j] = text[i];
            i++;
            j++;
        }
        temp[k][j] = '\0';
        j = 0;
        k++;
    }
    return temp;
}

void printStudentWithFN(Student* arrayOfStudents, size_t numberOfStudents){
    char FN[11];
    std::cin >> FN;
    if(!isValidFN(FN)){
        std::cout << "Invaild FN!";
        return;
    }
    for(int i = 0; i < numberOfStudents; ++i){
        if(cmpStr(arrayOfStudents[i].FN, FN)){
            printStudent(arrayOfStudents[i]);
            return;
        }
    }
    std::cout << "Don`t have student with FN: " << FN << std::endl; 
}

void changeEmail(char* FN, char* newEmail, Student* arrayOfStudents, size_t numberOfStudents){
    for(int i = 0; i < numberOfStudents; ++i){
        if(cmpStr(arrayOfStudents[i].FN, FN)){
            strcpy(arrayOfStudents[i].email, newEmail);
            return;
        }
    }
    std::cout << "Don`t have student with FN: " << FN << std::endl; 
}

void saveToFile(const Student* students, size_t size){
    char fileToSaveName[MAX_STR_SIZE];
    std::cin >> fileToSaveName;
    std::ofstream fileToSave(fileToSaveName);
    if(!fileToSave.is_open()){
        std::cout << "Problem with creating the file!";
        return;
    }
    for(int i = 0; i < size; ++i){
        fileToSave << students[i].firstName << "," << students[i].secondName << "," << students[i].FN << "," << students[i].email << "\n";
    }
    fileToSave.close();
}

void editEmail(Student* arrayOfStudents, size_t numberOfStudents){
    char FN[11];
    std::cin >> FN;
    if(isValidFN(FN)){
        char newEmail[MAX_STR_SIZE];
        std::cin >> newEmail;
        changeEmail(FN, newEmail, arrayOfStudents, numberOfStudents);
    } else std::cout << "Invaild FN!";
}

void callFunction(Student* arrayOfStudents, size_t numberOfStudents, size_t& sizeOfFile){
    char option[10];
    
    do{
        std::cin >> option;

        if(cmpStr(option, "print")){
            printStudentWithFN(arrayOfStudents, numberOfStudents);
        }
        else if(cmpStr(option, "edit")){
            editEmail(arrayOfStudents, numberOfStudents);
        }

    } while(!cmpStr(option, "save"));

    saveToFile(arrayOfStudents, numberOfStudents);
}

void deallocateText(char** text, size_t size){
    for(int i = 0; i < size; ++i){
        delete[] text[i];
    }
    delete[] text;
}

int main(){

    char fileName[MAX_STR_SIZE];

    do {
        std::cout << "Enter valid file name (.csv): ";
        std::cin.getline(fileName, MAX_STR_SIZE);

    } while (!isValidFileName(fileName));
    
    std::cout << "Open file " << fileName << std::endl;

    std::ifstream students(fileName);   

    if (!students.is_open()){
		std::cout << "Don't exist file with that name!" << std::endl;
		return -1;
	}
    std::cout << "File successfully opened!\n";
    
    size_t sizeOfFile = getFileSize(students);
    char text[sizeOfFile];
    students.read(text, sizeOfFile);
    students.close();
    std::cout << "File successfully loaded!\n";

    size_t numberOfStudents = getNumberOfStudents(text, sizeOfFile);
    size_t numberOfWords = getNumberOfWords(text, sizeOfFile);    
    char** arrayOfWords = separate(text, numberOfWords);
    Student* arrayOfStudents = allocateStudents(numberOfStudents, arrayOfWords);

    callFunction(arrayOfStudents, numberOfStudents, sizeOfFile);

    deallocateText(arrayOfWords, numberOfWords);
    delete[] arrayOfStudents;
    checkMemoryLeaks();
    return 0;
}

