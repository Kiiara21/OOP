#include <string>

using std::string;

const int MAX_SPEED = 400;

class Car {

private:
    // data members
    string m_color;
    string m_fuel;
    int m_doors;
    int m_year;
    int m_horses;
    int m_speed; // moment speed
    double m_volumeOfEngine;

public:

    Car(); // default constructor  // m_speed = 0
    Car(string color, string fuel, int doors, int year, int horses, double volumeOfEngine, int speed); // constructor
    ~Car(); // destructor

    // setters
    void setColor(string color);
    void setFuel(string fuel);
    void setDoors(int doors);
    void setYear(int year);
    void setHorses(int horses);
    void setVolumeOfEngine(double volumeOfEngine);
    void setSpeed(int speed);

    // getters
    string getColor () const;
    string getFuel () const;
    int getDoors () const;
    int getYear () const;
    int getHorses () const;
    int getSpeed () const;
    double getVolumeOfEngine () const;

    // functionality
    void needForSpeed(); // increase m_speed with 10 if it is not equal to MAX_SPEED
    void breaking(); // push the brake => decrease m_speed with 10 if it is not equal to 0
    void setGasInjectionSystem(); // if the car is not on gas injection system
    void tuning(int additionalHorses); // add horses
    void changeColor(string newColor);              

};