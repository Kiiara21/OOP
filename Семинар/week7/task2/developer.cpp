#include "developer.h"

void Developer::init(int id, string firstName, string secondName, Position position){
    m_id = id;
    m_firstName = firstName;
    m_lastName = secondName;
    m_position = position;
}

void Developer::deleteMemory(){}

void Developer::writeInFile(std::ostream& out){
    out << *this;
}
void Developer::readFromFile(std::istream& in){
    in >> *this;
}

std::ostream& operator<<(std::ostream& out, const Developer& dev){
    out << dev.m_id << " " << dev.m_firstName << " " << dev.m_lastName << " ";
    
    switch (dev.m_position){
    case Position::JUNIOR_DEV:
        out << "JUNIOR_DEV\n";
        break;
    case Position::DEV:
        out << "DEV\n";
        break;
    case Position::SENIOR_DEV:
        out << "SENIOR_DEV\n";
        break;
    case Position::QA:
        out << "QA\n";
        break;
    case Position::MANAGER:
        out << "MANAGER\n";
        break;
    default:
        out << "Invalid position!\n";
        break;
    }

    return out;
}

std::istream& operator>>(std::istream& in, Developer& dev){
    in >> dev.m_id;
    in >> dev.m_firstName;
    in >> dev.m_lastName;
    string line;
    in >> line;
    if(line == "QA"){
        dev.m_position = Position::QA;
    }
    else if(line == "JUNIOR_DEV"){
        dev.m_position = Position::JUNIOR_DEV;
    }
    else if(line == "DEV"){
        dev.m_position = Position::DEV;
    }
    else if(line == "SENIOR_DEV"){
        dev.m_position = Position::SENIOR_DEV;
    }
    else if(line == "MANAGER"){
        dev.m_position = Position::MANAGER;
    }

    return in;
}
