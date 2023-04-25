#pragma once
#include <string>
#include <iostream>
using std::string;

class Author {

private:
    
    string m_name;
    string m_lastName;
    int m_age;
    string m_email;

public:

    Author();
    Author(const string name, const string lastName, const int age, const string email);

    string getName() const;
    string getLastName() const;
    int getAge() const;
    string getEmail() const;

    friend std::ostream& operator << (std::ostream& out, const Author& author);
    friend std::istream& operator >> (std::istream& in, Author& author);

};