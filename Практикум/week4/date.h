#include <iostream>
#include <cassert>

class Date {

private:

    int m_day;
    int m_month;
    int m_year;

    bool isLeapYear(int year);
    bool validation(int day, int month, int year);

public:

    Date(unsigned int day, unsigned int month, unsigned int year);

    unsigned int day() const { return m_day; }
    unsigned int month() const { return m_month; }
    unsigned int year() const { return m_year; }

    bool operator==(const Date& rhs) const;
    bool operator<(const Date& rhs) const;
    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};