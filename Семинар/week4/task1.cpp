#include <iostream>
#include <cstring>
#include <cassert>

const size_t MAX = 100;

class Athlete{

private:
    char m_name[MAX];
    int m_stamina;
    int m_speed;
    int m_power;
    bool m_traurma;
    char m_team[MAX];

public:

    Athlete(){
        strcpy(m_name, "N/A");
        m_stamina = 1;
        m_speed = 1;
        m_power = 1;
        m_traurma = false;
        strcpy(m_team, "N/A");
    }

    Athlete(char* name, int stamina, int speed, int power, bool traurma, char* team){
        assert(name != nullptr);
        strcpy(m_name, name);

        m_stamina = stamina;
        m_speed = speed;
        m_power = power;
        m_traurma = traurma;

        assert(team != nullptr);
        strcpy(m_team, team);
    }

    ~Athlete(){

    }

    const char* getName() const { return m_name; }
    int getStamina() const { return m_stamina; }
    int getSpeed() const { return m_speed; }
    bool getTraurma() const { return m_traurma; }
    const char* getTeam() const { return m_team; }

    void changeTeam(char* newTeam){
        strcpy(m_team, newTeam);
    }

    void training() const{
        if(!m_traurma){
            std::cout << "Go training!";
        }
        else std::cout << "Just chilling right now!";
    }

    void print() const {
        assert(m_name != nullptr);
        assert(m_team != nullptr);

        std::cout << m_name << " " << m_stamina << " " << m_power << " " << m_speed << " " << m_team << " " << m_traurma;
    }

};

int main(){
    return 0;
}