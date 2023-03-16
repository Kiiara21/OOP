#include <iostream>

int MAX_GAS = 100;
int MAX_POWER = 150;

class Car {

private:
    int m_power = 90;
    int  m_gas = 0;
    int m_distance = 0;

public:

    void setPower(int power){
        m_power = power;
    }
    void setGas(int gas){
        m_gas = gas;
    }
    void setDistance(int distance){
        m_distance = distance;
    }

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
    }

    void drive(){
        if(m_gas == 0){
            std::cout << "Don`t have gas!";
            return;
        }
        m_gas -= m_distance * (m_power / (0.15 * m_gas));
    }
};

int main(){
    Car myCar;
    myCar.setPower(90);
    myCar.setGas(50);
    myCar.setDistance(2);

    std::cout << "Power: " << myCar.getPower() << std::endl;
    std::cout << "Gas: " << myCar.getGas() << std::endl;
    myCar.fill();
    std::cout << "Gas after filling: " << myCar.getGas() << std::endl;
    myCar.drive();
    std::cout << "Gas after driving " << myCar.getDistance() << " km: " << myCar.getGas();
    
    return 0;
}