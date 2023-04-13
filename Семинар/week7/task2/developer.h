#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "position.h"
using std::string;


struct Developer {
    int m_id;
    string m_firstName;
    string m_lastName;
    Position m_position;
public:

    void init(int id, string firstName, string secondName, Position position);
    void deleteMemory();

    void writeInFile(std::ostream& out);
    void readFromFile(std::istream& in);
    
    friend std::ostream& operator<<(std::ostream& out, const Developer& dev);
    friend std::istream& operator>>(std::istream& in, Developer& dev);

};