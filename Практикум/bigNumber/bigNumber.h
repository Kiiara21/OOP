
#pragma once

#include <iostream>
#include <cstring>
#include <cassert>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

class BigNumber {

private:

    char* m_number;

    void erase();
    void copy(const BigNumber& other);

    bool isPositive(char* number) const;
    bool isNegative(char* number) const;

public:

    BigNumber();
    BigNumber(const BigNumber& other);
    BigNumber& operator=(const BigNumber& other);
    ~BigNumber();

    BigNumber(const char* number);
    BigNumber(long long int number);

    size_t getLength() const;

    bool operator == (const BigNumber& other) const;
    bool operator != (const BigNumber& other) const;
    bool operator < (const BigNumber& other) const;
    bool operator > (const BigNumber& other) const;

    BigNumber& operator += (const BigNumber& other);
    BigNumber operator + (const BigNumber& other) const;
    BigNumber& operator -= (const BigNumber& other);
    BigNumber operator - (const BigNumber& other) const;
    BigNumber& operator *= (const BigNumber& other);
    BigNumber operator * (const BigNumber& other) const;

    BigNumber& operator ++ ();
    BigNumber operator ++ (int);

    BigNumber& operator -- ();
    BigNumber operator -- (int);

    BigNumber& operator - ();

    BigNumber& operator /= (const BigNumber& other);
    BigNumber operator / (const BigNumber& other) const;
    BigNumber& operator %= (const BigNumber& other);
    BigNumber operator % (const BigNumber& other) const;

    friend std::ostream& operator<<(std::ostream& out, const BigNumber& number);
    friend std::istream& operator>>(std::istream& in, BigNumber& number);

};