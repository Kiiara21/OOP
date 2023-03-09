#include <iostream>
#include <fstream>
#include <cstring>

struct Student{
    char* firstName;
    char* secondName;
    char* email;
    int FN; // fix it
};

// fix it
bool validFileName(char* fileName){
    size_t fileSize = strlen(fileName) - 1;

    if(fileName[fileSize] == 'd' &&
       fileName[fileSize - 1] == 'a' && 
       fileName[fileSize - 2] == 't')
    {
        return true;
    }

    return false;
}

void printStudent(const Student& student){
    std::cout << student.firstName << " " << student.secondName << " " << student.email << " " << student.FN << "\n";
}

Student createStudent(const char* const& firstName, const char* const& secondName, const char* const& email, const int& FN){
    Student newStudent;

    size_t firstNameSize = strlen(firstName);
    newStudent.firstName = new char[firstNameSize + 1];
    strcpy(newStudent.firstName, firstName);

    size_t secondNameSize = strlen(secondName);
    newStudent.secondName = new char[secondNameSize + 1];
    strcpy(newStudent.secondName, secondName);

    size_t emailSize = strlen(email);
    newStudent.email = new char[emailSize + 1];
    strcpy(newStudent.email, email);

    newStudent.FN = FN;

    return newStudent;
}

void saveStudentToFile(std::ofstream& fileToSave, const Student& studentToSave){

    size_t firstNameSize = strlen(studentToSave.firstName);
    size_t secondNameSize = strlen(studentToSave.secondName);
    size_t emailSize = strlen(studentToSave.email);

    fileToSave.write((const char*)& firstNameSize, sizeof(firstNameSize)); // write the size of first name
    fileToSave.write(studentToSave.firstName, firstNameSize); // write first name

    fileToSave.write((const char*)& secondNameSize, sizeof(secondNameSize)); // write the size of second name
    fileToSave.write(studentToSave.secondName, secondNameSize); // write second name

    fileToSave.write((const char*)& emailSize, sizeof(emailSize)); // write the size of email
    fileToSave.write(studentToSave.email, emailSize); // write email

    fileToSave.write((const char*)& studentToSave.FN, sizeof(studentToSave.FN)); // write FN
}

Student readStudentFromFile(std::ifstream& fileToRead){
    Student resultStudent;
    size_t firstNameSize;
    size_t secondNameSize;
    size_t emailSize;
    size_t FNSize;

    fileToRead.read((char*)& firstNameSize, sizeof(firstNameSize)); // read the size of first name
    resultStudent.firstName = new char[firstNameSize + 1];
    fileToRead.read(resultStudent.firstName, firstNameSize); // read first name
    resultStudent.firstName[firstNameSize] = '\0';

    fileToRead.read((char*)& secondNameSize, sizeof(secondNameSize)); // read the size of second name
    resultStudent.secondName = new char[secondNameSize + 1];
    fileToRead.read(resultStudent.secondName, secondNameSize); // read second name
    resultStudent.secondName[secondNameSize] = '\0';

    fileToRead.read((char*)& emailSize, sizeof(emailSize)); // read the size of email
    resultStudent.email = new char[emailSize + 1];
    fileToRead.read(resultStudent.email, emailSize); // read email
    resultStudent.email[emailSize] = '\0';

    fileToRead.read((char*)&resultStudent.FN, sizeof(resultStudent.FN)); // read FN

    return resultStudent;
}

void deallocateStudent(Student& student){
    delete[] student.firstName;
    delete[] student.secondName;
    delete[] student.email;
    student.FN = 0;
}

// void createFileWithStudents(){
//     Student firstStudent = createStudent("Ivan", "Ivanov", "IvanIvanov@abv.bg", 12345);
//     Student secondStudent = createStudent("Peter", "Petrov", "PeterPetrov@abv.bg", 56789);

//     std::ofstream outputFile("students.dat", std::ios::binary);

//     if(!outputFile.is_open()){
//         std::cout << "Error!";
//         return;
//     }

//     saveStudentToFile(outputFile, firstStudent);
//     saveStudentToFile(outputFile, secondStudent);

//     deallocateStudent(firstStudent);
//     deallocateStudent(secondStudent);

//     outputFile.close();
// }

int main(){

    // createFileWithStudents();

    char fileName[100];
    std::cin.getline(fileName, 100);
    
    // fix it
    // do {
    //     std::cout << "Enter valid file name (.dat): ";
    //     std::cin.getline(fileName, 100);

    // } while (!validFileName(fileName));
    
    std::ifstream inputFile(fileName);   

    if (!inputFile.is_open())
	{
		std::cout << "Don't exist file with that name!" << std::endl;
		return -1;
	}

    Student firstStudent = readStudentFromFile(inputFile);
    Student secondStudent = readStudentFromFile(inputFile);

    printStudent(firstStudent);
    printStudent(secondStudent);

    deallocateStudent(firstStudent);
    deallocateStudent(secondStudent);

    inputFile.close();
    return 0;
}