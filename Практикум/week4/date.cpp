#include "date.h"

bool Date::isLeapYear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool Date::validation(int day, int month, int year){
    if(year <= 0 || month <= 0 || day <= 0){
        return false;
    }
    if(month == 2){
        if(isLeapYear(year)){
            return day <= 29;
        }
        return day <= 28;
    }
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return (day <= 31);
    }

    return day <= 30;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year){
    assert(validation(day, month, year));
    m_day = day;
    m_month = month;
    m_year = year;
} 

bool Date::operator==(const Date& rhs) const {
    return (m_day == rhs.m_day && m_month == rhs.m_month && m_year == rhs.m_year);
}

bool Date::operator<(const Date& rhs) const {
    if (m_year < rhs.m_year){
        return true;
    }
    if(m_year > rhs.m_year){
        return false;
    }
    if(m_month < rhs.m_month){
        return true;
    }
    if(m_month > rhs.m_month){
        return false;
    }
    if(m_day < rhs.m_day){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Date& date){
    out << date.m_day << "." << date.m_month << "." << date.m_year << "\n";
    return out;
}
