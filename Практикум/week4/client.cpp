#include "client.h"

void Client::copy(const Client& other){
    setName(other.m_name);
    setEGN(other.m_EGN);
    m_money = other.m_money;
}

void Client::erase(){
    delete[] m_name;
    delete[] m_EGN;
}

Client::Client(const Client& other) : m_birthData(other.m_birthData){
    copy(other);
}

Client& Client::operator=(const Client& other){
    if(&other != this){
        erase();
        copy(other);
    }
    return *this;
}

Client::~Client(){
    erase();
}

Client::Client(const char* name, const char* identificationNumber, const Date& birthday, const Money& money) : m_birthData(birthday), m_money(money){
    setName(name);
    setEGN(identificationNumber);
}

void Client::setName(const char* name){
    assert(name != nullptr);
    delete[] m_name;

    m_name = new (std::nothrow) char[strlen(name) + 1];
    if(!m_name){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_name, name);
}

void Client::setEGN(const char* identificationNumber){
    assert(identificationNumber != nullptr);
    delete[] m_EGN;

    m_EGN = new (std::nothrow) char[10];
    if(!m_EGN){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_EGN, identificationNumber);
}

void Client::setBirthDate(const Date& birthday){
    m_birthData = birthday;
}

void Client::setMoney(const Money& money){
    m_money = money;
}

std::ostream& operator<<(std::ostream& out, const Client& client){
    out << client.m_name << " " << client.m_EGN << " " << client.m_birthData << " " << client.m_money;
    return out;
}

