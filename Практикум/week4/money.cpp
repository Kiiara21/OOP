#include "money.h"
#include <iostream>
#include <cassert>

Money::Money(){
    m_moneySum = 0;
    m_currency = BGN;
}

// Money Money::softConvert(const ConvertionRate& convertion) const;

// void Money::hardConvert(const ConvertionRate& newCurrency);

int Money::operator+(int a){
    return m_moneySum + a;
} 

int Money::operator+=(int a){
    m_moneySum = m_moneySum + a;
    return m_moneySum;
}

int Money::operator-(int a){
    return m_moneySum - a;
} 

int Money::operator-=(int a){
    m_moneySum = m_moneySum - a;
    return m_moneySum;
}

Money Money::operator+(const Money& other) const{
    assert(m_currency != other.m_currency);
    Money result = *this;
    result += other;
    return result;
}

Money& Money::operator+=(const Money& other){
    m_moneySum += other.m_moneySum;
    return *this;
}

Money Money::operator-(const Money& other) const{
    assert(m_currency != other.m_currency);
    Money result = *this;
    result -= other;
    return result;
}

Money& Money::operator-=(const Money& other){
    m_moneySum += other.m_moneySum;
    return *this;
}

Money& Money::operator-(){
    m_moneySum = (-1)*m_moneySum;
    return *this;
}

bool Money::operator==(const Money& other){
    return (m_moneySum == other.m_moneySum && m_currency == other.m_currency);
}

bool Money::operator!=(const Money& other){
    return !(*this == other);
}

bool Money::operator<(const Money& other){
    if(m_currency == BGN && other.m_currency != BGN){
        return true;
    }
    if(m_currency == EUR && other.m_currency == BGN){
        return false;
    }
    if(m_currency == USD && other.m_currency != USD){
        return false;
    }
    else return m_moneySum < other.m_moneySum;
}

bool Money::operator<=(const Money& other){
    return (*this == other || *this < other);
}

bool Money::operator>(const Money& other){
    return !(*this <= other);
}

bool Money::operator>=(const Money& other){
    return (*this == other || *this > other);
}

std::ostream& operator<<(std::ostream& out, const Money& money) {
    switch (money.m_currency)
    {
    case 0:
        out << money.m_moneySum << " BGN\n";
        break;
    case 1:
        out << money.m_moneySum << " USD\n";
        break;
    case 2:
        out << money.m_moneySum << " EUR\n";
        break;
        
    default:
        break;
    }
        
    return out;
}
