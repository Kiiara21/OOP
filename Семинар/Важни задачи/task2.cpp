#include <iostream>
#include <fstream>
#include <cstring>

struct Student{
    char* firstName;
    char* secondName;
    char* email;
    int FN; // fix it
};

size_t getFileSize(std::ifstream &f){

	size_t currentPos = f.tellg();
	f.seekg(0, std::ios::end);
	size_t size = f.tellg();
	
	f.seekg(currentPos);
	return size;

}

char* makeRow(char* fileContent){
    int i = 0, j = 0;
    while(fileContent[i] != '\n'){
        i++;
    }

    char* row = new char[i + 1];
    i = 0;
    while(fileContent[i] != '\n'){
        row[j] = fileContent[i];
        j++;
        i++;
    }
    row[i] = '\0';
    return row;
}

size_t getNumberOfStudents(char* fileContent, size_t sizeOfFile){
    size_t rows = 0;

    for(int i = 0; i < sizeOfFile; ++i){
        if(fileContent[i] == '\n'){
            rows++;
        }
    }

    return rows + 1;
}

int main(){
    char fileName[100];
    // std::cin.getline(fileName, 100);

    std::ifstream file("students.csv");
    if(!file.is_open()){
        return -1;
    }

    size_t sizeOfFile = getFileSize(file);
    Student* arrayOfStudents = new Student[sizeOfFile / sizeof(Student)];

    char arr[sizeOfFile];

    file.read((char*)&arr, sizeOfFile);

    size_t numberOfStudents = getNumberOfStudents(arr, sizeOfFile);

    int currIndex = 0;
    
    for(int i = 0; i < numberOfStudents; ++i){
        char *currRow = makeRow(arr);
        std::cout << currRow << "\n";
        delete[] currRow;
    }
    

    delete[] arrayOfStudents;
    file.close();   
    return 0;
}