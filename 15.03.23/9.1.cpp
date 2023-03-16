#include <iostream>

class Time {

private:
    int m_hour;
    int m_minutes;

    bool isCorrectHour(int hour){
        return hour >= 0 && hour <= 24;
    }

    bool isCorrectMinutes(int minutes){
        return minutes >= 0 && minutes <= 59;
    }

public:

    Time(){
        m_hour = 0;
        m_minutes = 0;
    }

    Time(int hour, int minutes) {
        m_hour = hour;
        m_minutes = minutes;
    }

    void setHour(int hour){
        if(isCorrectHour(hour))
            m_hour = hour;
    }

    void setMinutes(int minutes){
        if(isCorrectMinutes(minutes))
            m_minutes = minutes;
    }

    int getHour () const { return m_hour; }
    int getMinutes() const { return m_minutes; }

    int getMinutesAfterMidnight(){
        return m_hour * 60 + m_minutes;
    }

    bool operator <(const Time& other){
        if(m_hour < other.m_hour){
            return true;
        }
        if(m_hour == other.m_hour){
            if(m_minutes < other.m_minutes){
                return true;
            }
            return false;
        }
        else return false;
    }

    Time operator+(const Time& other){
        Time result;
        int hour, minutes;
        hour = m_hour + other.m_hour;
        minutes = m_minutes + other.m_minutes;
        while(minutes >= 60){
            hour += 1;        
            minutes -= 60;    
        }
        result.setHour(hour);
        result.setMinutes(minutes);
        return result;
    }

    Time operator-(const Time& other){
        Time result;
        result.setHour(abs(m_hour - other.m_hour));
        result.setMinutes(abs(m_minutes - other.m_minutes));
        return result;
    }

    Time operator*(const int number){
        Time result;
        result.setHour(m_hour * number);
        result.setMinutes(m_minutes * number);
        return result;
    }


    void print() const {
        std::cout << m_hour << ":" << m_minutes;
    }

    
};

int main(){
    Time t1(1, 45);
    Time t2(3, 20);

    Time t;
    t = t1 - t2;
    t = t * 2;
    t.print();
    return 0;
}