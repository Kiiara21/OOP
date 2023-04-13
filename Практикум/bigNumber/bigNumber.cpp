#include "bigNumber.h"

void BigNumber::erase(){
    delete[] m_number;
}

void BigNumber::copy(const BigNumber& other){
    m_number = new (std::nothrow) char [strlen(other.m_number) + 1];
    if(!m_number){
        std::cout << "Memory problem!";
        return;
    }

    strcpy(m_number, other.m_number);
}

bool BigNumber::isPositive(char* number) const {
    return number[0] != '-';
}

bool BigNumber::isNegative(char* number) const {
    return !isPositive(number);
}

BigNumber::BigNumber(){
    m_number = new (std::nothrow) char [1];
    if(!m_number){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_number, "0");
}

BigNumber::BigNumber(const BigNumber& other){
    copy(other);
}

BigNumber& BigNumber::operator=(const BigNumber& other){
    if(&other != this){
        erase();
        copy(other);
    }
    return *this;
}

BigNumber::~BigNumber(){
    erase();
}

BigNumber::BigNumber(const char* number){
    m_number = new (std::nothrow) char [strlen(number) + 1];
    if(!m_number){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_number, number);
}


size_t BigNumber::getLength() const{
    return strlen(m_number);
}

// BigNumber::BigNumber(long long int number)

bool BigNumber::operator == (const BigNumber& other) const {
    size_t numberLength = strlen(m_number);
    size_t otherNumberLength = strlen(other.m_number);
    if(numberLength != otherNumberLength){
        return false;
    }
    for(int i = 0; i < numberLength; ++i){
        if(m_number[i] != other.m_number[i]){
            return false;
        }
    }
    return true;
}

bool BigNumber::operator != (const BigNumber& other) const {
    return !(*this == other);
}

bool BigNumber::operator < (const BigNumber& other) const { 
    size_t numberLength = strlen(m_number);
    size_t otherNumberLength = strlen(other.m_number);

    if(isNegative(m_number) && isPositive(other.m_number)){
        return true;
    }
    if(isPositive(m_number) && isNegative(other.m_number)){
        return false;
    }
    if(numberLength < otherNumberLength){
        return true;
    }
    if(numberLength > otherNumberLength){
        return false;
    }

    for(int i = 0; i < numberLength; ++i){
        if(m_number[i] > other.m_number[i]){
            return false;
        }
    }

    return true;

}

bool BigNumber::operator > (const BigNumber& other) const{
    if(*this < other || *this == other){
        return false;
    }

    return true;
} 


BigNumber& BigNumber::operator += (const BigNumber& other){
    int i, new_val, carry = 0, number[100];
    int size = getLength();
    for(int i = 0; i < size; ++i){
        new_val = (m_number[i] - '0') + (other.m_number[i] - '0') + carry;
        std::cout << (new_val % 10);
        number[i] = new_val % 10;
        std::cout << "m_number[i] = " << number[i] << "\n";
        if (new_val >= 10)
            carry = new_val / 10;
        else
            carry = 0;
    }    

    for(int i = 0; i < size; ++i){
        m_number[i] = number[i] + '0';
    }

    return *this;
}


// BigNumber BigNumber::operator + (const BigNumber& other) const;
// BigNumber& BigNumber::operator -= (const BigNumber& other);
// BigNumber BigNumber::operator - (const BigNumber& other) const;
// BigNumber& BigNumber::operator *= (const BigNumber& other);
// BigNumber BigNumber::operator * (const BigNumber& other) const;

// BigNumber& BigNumber::operator ++ ();
// BigNumber BigNumber::operator ++ (int);

// BigNumber& BigNumber::operator -- ();
// BigNumber BigNumber::operator -- (int);

// BigNumber& BigNumber::operator - ();

// BigNumber& BigNumber::operator /= (const BigNumber& other);
// BigNumber BigNumber::operator / (const BigNumber& other) const;
// BigNumber& BigNumber::operator %= (const BigNumber& other);
// BigNumber BigNumber::operator % (const BigNumber& other) const;

std::ostream& operator<<(std::ostream& out, const BigNumber& number){
    for(int i = 0; i < number.m_number[i] != '\0'; ++i){
        out << number.m_number[i];
    }
    size_t numberLength = strlen(number.m_number);

    out << "\nNumber length: " << numberLength << "\n";
    return out;
}

// std::istream& operator>>(std::istream& in, BigNumber& number){
//     std::cout << "Enter big number: ";
//     in >> number.m_number;   
// }
