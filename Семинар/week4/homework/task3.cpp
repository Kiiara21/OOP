#include <iostream>
#include <cstring>
#include <cassert>

class Time {

private:

    int m_hours;
    int m_minutes;
    int m_seconds;

    bool validation(int hours, int minutes, int seconds){
        return (hours >= 0 && hours <= 24
                && minutes >= 0 && minutes < 60
                && seconds >= 0 && seconds < 60);
    }
public:

    Time(){
        m_hours = 0;
        m_minutes = 0;
        m_seconds = 0;
    }

    Time(int hours, int minutes, int seconds){
        if(validation(hours, minutes, seconds)){
            m_hours = hours;
            m_minutes = minutes;
            m_seconds = seconds;
        } else std::cout << "Not a valid time!";
    }

    void toMidnight(){
        std::cout << "To midnight have: " << 24 - m_hours << " hours, " << 60 - m_minutes << " minutes, " << 60 - m_seconds << " seconds\n";
    }

    void addOneSecond(){
        if(m_seconds + 1 == 60){
            if(m_minutes + 1 == 60){
                if(m_hours == 24){
                    m_hours = 1;
                    m_minutes = 0;
                    m_seconds = 0;
                } 
                else {
                    m_hours += 1;
                    m_minutes = 0;
                    m_seconds = 0;
                }
            } 
            else {
                m_minutes += 1;
                m_seconds = 0;
            }
        } else m_seconds += 1;
    }

    bool isTimeForDiner(){
        return (m_hours >= 20 && m_hours <= 22 && m_minutes >= 30 && m_minutes <= 59);
    }

    bool isTimeForParty(){
        return (m_hours >= 23 || m_hours < 6);
    }

    Time differenceBetween(const Time& other){

        if(other.m_minutes > m_minutes){
            m_minutes += 60;
            --m_hours;
        }

        if(other.m_seconds > m_seconds){
            m_seconds += 60;
            --m_minutes;
        }

        Time result(m_hours - other.m_hours, m_minutes - other.m_minutes, m_seconds - other.m_seconds);
        return result;
    }

    bool isLatterThan(Time& otherTime){
        if(m_hours > otherTime.m_hours){
            return true;
        }
        else if(m_hours == otherTime.m_hours){
            if(m_minutes > otherTime.m_minutes){
                return true;
            }
            else if(m_minutes == otherTime.m_minutes){
                if(m_seconds > otherTime.m_seconds){
                    return true;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    void print() const {
        std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl; 
    }
};

int main(){

    Time t1(12, 0, 0);
    Time t2(12, 0, 0);
    t1.addOneSecond();
    t1.print();
    t2.print();
    Time diffTime = t1.differenceBetween(t2);
    diffTime.print();
    t1.toMidnight();
    t2.toMidnight();
    std::cout << t1.isLatterThan(t2);
    std::cout << t1.isTimeForDiner();
    std::cout << t1.isTimeForParty();

    return 0;
}