#include <iostream>

int MAX_GAS = 100;
int MAX_POWER = 150;

class Car {

private:
    int m_power;
    int  m_gas;
    int m_distance;

public:

    Car(){
        m_power = 90;
        m_gas = 0;
        m_distance = 0;
    }

    Car(int power, int gas, int distance) : m_power(power), m_gas(gas), m_distance(distance) {}

    int getPower() const { return m_power; }
    int getGas() const { return m_gas; }
    int getDistance() const { return m_distance; }

    void update(){
        if(m_power <= MAX_POWER - 15){
            m_power += 15;
        } else std::cout << "You are maxing out!";
    }

    void fill(){
        if(m_gas < MAX_GAS){
            m_gas = MAX_GAS;
        } else std::cout << "Тhe tank is alreаdy full!";
        std::cout << "Full...";
    }

    void drive(){
        if(m_gas == 0){
            std::cout << "Beep! Dont have Gas!";
            return;
        }
        m_gas -= m_distance * (m_power / (0.15 * m_gas));
    }
};

int main(){
    Car myCar(90, 50, 2);

    std::cout << myCar.getGas() << std::endl;
    // myCar.fill();
    myCar.drive();
    std::cout << myCar.getGas();
    return 0;
}