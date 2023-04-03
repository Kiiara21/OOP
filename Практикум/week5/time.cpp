#include "time.h"

Time::Time() : m_hour(0), m_minutes(0) {}

Time::Time(unsigned int hour, unsigned int minutes) : m_hour(hour), m_minutes(minutes)  {}

unsigned int Time::getHours() const{ return m_hour; }

unsigned int Time::getMinutes() const{ return m_minutes; }

Time Time::operator+(const Time& other){
    return Time(m_hour + other.m_hour, m_minutes + other.m_minutes);
}

Time Time::operator+(const int hourToAdd){
    Time toAdd(hourToAdd, 0);
    return *this + toAdd;
}

Time operator + (const int hours, const Time& other){
    return Time(other.m_hour + hours, other.m_minutes);
}


Time& Time::operator++(){
    ++m_hour;
    return *this;
}

Time Time::operator++(int){
    Time old = *this;
    ++(*this);
    return old;
}


bool Time::operator<(const Time& other){
    return m_hour < other.m_hour;
}

std::ostream& operator<<(std::ostream& out, const Time& time){
    out << time.m_hour << ":" << time.m_minutes;
    return out;
}
