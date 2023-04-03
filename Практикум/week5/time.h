#pragma once
#include <fstream>

class Time{

private:
    unsigned int m_hour;
    unsigned int m_minutes;

public:
    Time();
    Time(unsigned int hour, unsigned int minutes);
    
    unsigned int getHours() const;
    unsigned int getMinutes() const;


    Time operator+(const Time& other);
    Time operator+(const int hourToAdd);
    friend Time operator + (const int hours, const Time& other);
    
    Time& operator++();
    Time operator++(int);


    bool operator<(const Time& other);

    friend std::ostream& operator<<(std::ostream& out, const Time& time);

};