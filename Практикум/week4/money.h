#include <iostream>
#include <cassert>

enum Currency { BGN, USD, EUR };

struct ConvertionRate {
    double exchangeRate;
    Currency oldCurrency;
    Currency newCurrency;

};

class Money{

private:
    double m_moneySum;
    Currency m_currency;

public:

    Money();
    Money(double startingMoney, Currency currency) : m_moneySum(startingMoney), m_currency(currency) {}
    
    double getMoney() const { return m_moneySum; }
    Currency getCurrency() const { return m_currency; }
    Money softConvert(const ConvertionRate& convertion) const;
    void hardConvert(const ConvertionRate& newCurrency); 

    int operator+(int a);
    int operator+=(int a);
    int operator-(int a);
    int operator-=(int a);
    Money operator+(const Money& other) const;
    Money& operator+=(const Money& other);
    Money operator-(const Money& other) const;
    Money& operator-=(const Money& other);
    Money& operator-();
    bool operator==(const Money& other);
    bool operator!=(const Money& other);
    bool operator<(const Money& other);
    bool operator<=(const Money& other);
    bool operator>(const Money& other);
    bool operator>=(const Money& other);
    friend std::ostream& operator<<(std::ostream& out, const Money& money);

};
