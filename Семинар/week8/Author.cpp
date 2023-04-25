#include "Author.h"

Author::Author(){
    m_name = "";
    m_lastName = "";
    m_age = 0;
    m_email = "";
}

Author::Author(const string name, const string lastName, const int age, const string email){
    m_name = name;
    m_lastName = lastName;
    m_age = age;
    m_email = email;
}

string Author::getName() const {
    return m_name;
}

string Author::getLastName() const {
    return m_lastName;
}

int Author::getAge() const{ 
    return m_age;
}

string Author::getEmail() const {
    return m_email;
}

std::ostream& operator << (std::ostream& out, const Author& author){
    out << author.m_name << "\n" << author.m_lastName << "\n" << author.m_age << "\n" << author.m_email << "\n\n";
    return out;
}

std::istream& operator >> (std::istream& in, Author& author){
    in >> author.m_name;
    in >> author.m_lastName;
    in >> author.m_age;
    in >> author.m_email;
    return in;
}