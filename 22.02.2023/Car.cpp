#include <iostream>
#include "Car.h"

Car::Car(){
    m_color = "";
    m_fuel = "";
    m_doors = 5;
    m_year = 2000;
    m_horses = 75;
    m_volumeOfEngine = 1.6;
    m_speed = 0;
} 

Car::Car(string color, string fuel, int doors, int year, int horses, double volumeOfEngine, int speed){
    setColor(color);
    setFuel(fuel);
    setDoors(doors);
    setYear(year);
    setHorses(horses);
    setVolumeOfEngine(volumeOfEngine);
    setSpeed(speed);
}

Car::~Car(){
    // do nothing
}

// =========================================================== //

void Car::setColor(string color){
    m_color = color;
}

void Car::setFuel(string fuel){
    m_fuel = fuel;
}

void Car::setDoors(int doors){
    m_doors = doors;
}

void Car::setYear(int year){
    m_year = year;
}

void Car::setHorses(int horses){
    m_horses = horses;
}

void Car::setVolumeOfEngine(double volumeOfEngine){
    m_volumeOfEngine = volumeOfEngine;
}

void Car::setSpeed(int speed){
    m_speed = speed;
}

// =========================================================== //

string Car::getColor () const{ return m_color; }

string Car::getFuel () const{ return m_fuel; }

int Car::getDoors () const{ return m_doors; }

int Car::getYear () const{ return m_year; }

int Car::getHorses () const{ return m_horses; }

int Car::getSpeed () const{ return m_speed; }

double Car::getVolumeOfEngine () const{ return m_volumeOfEngine; }

// =========================================================== //

void Car::needForSpeed(){
    int newSpeed = m_speed + 10;
    if(newSpeed < MAX_SPEED){
        setSpeed(newSpeed);
    }
} // increase m_speed with 10 if it is not equal to MAX_SPEED

void Car::breaking(){
    int newSpeed = m_speed - 10;
    if(newSpeed < 0){
        newSpeed = 0;
    }
    setSpeed(newSpeed);

} // push the brake => decrease m_speed with 10 if it is not equal to 0

void Car::setGasInjectionSystem(){
    if(m_fuel != "gas"){
        setFuel("gas");
    }
} // if the car is not on gas injection system

void Car::tuning(int additionalHorses){
    setHorses(m_horses + additionalHorses);
} // add horses

void Car::changeColor(string newColor){
    setColor(newColor);
}



int main(){

    Car car("Black", "Petrol", 5, 2002, 150, 1.8, 0);
    std::cout << car.getColor() << std::endl;
    std::cout << car.getFuel() << std::endl;
    std::cout << car.getDoors() << std::endl;
    std::cout << car.getYear() << std::endl;
    std::cout << car.getHorses() << std::endl;
    std::cout << car.getVolumeOfEngine() << std::endl;
    std::cout << car.getSpeed() << std::endl;
    car.changeColor("Pink");
    std::cout << car.getColor() << std::endl;
    car.needForSpeed();
    std::cout << car.getSpeed() << std::endl;
    car.needForSpeed();
    std::cout << car.getSpeed() << std::endl;
    car.needForSpeed();
    std::cout << car.getSpeed() << std::endl;
    car.needForSpeed();
    std::cout << car.getSpeed() << std::endl;
    car.breaking();
    std::cout << car.getSpeed() << std::endl;
    car.breaking();
    std::cout << car.getSpeed() << std::endl;
    car.setGasInjectionSystem();
    std::cout << car.getFuel() << std::endl;
    car.tuning(46);
    std::cout << car.getHorses() << std::endl;


    return 0;
}