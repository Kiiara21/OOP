#pragma once
#include <string>
#include <fstream>

using std::string;

class Computer {

private:

    static int s_counter;
    unsigned int m_id;

    string m_brand;
    string m_procesor;
    string m_video;
    string m_hardDrive;
    string m_weight;
    string m_batteryLife;
    string m_price;
    string m_quantity;

public:     

    Computer (string brand, string procesor, string video, string hardDrive, string weight, string batteryLife, string price, string m_quantity);
    string getBrand () const { return m_brand; }
    string getProcesor () const { return m_procesor; }
    string getVideo () const { return m_video; }
    string getHardDrive () const { return m_hardDrive; }
    string getWeight () const { return m_weight; }
    string getBatteryLife () const { return m_batteryLife; }
    string getPrice () const { return m_price; }
    string getQuantity () const { return m_quantity; }

    friend std::ostream& operator<< (std::ostream& out, const Computer& comp);
    friend std::istream& operator>> (std::istream& in, Computer& comp);

};

int Computer::s_counter = 1;

Computer::Computer (string brand, string procesor, string video, string hardDrive, string weight, string batteryLife, string price, string quantity){
    m_brand = brand;
    m_procesor = procesor;
    m_video = video;
    m_hardDrive = hardDrive;
    m_weight = weight;
    m_batteryLife = batteryLife;
    m_price = price;
    m_quantity = quantity;
    m_id = s_counter++;
}


std::ostream& operator<< (std::ostream& out, const Computer& comp){
    out << comp.m_brand << " i t.n...";
    return out;
}

std::istream& operator>> (std::istream& in, Computer& comp){
    in >> comp.m_brand;
    return in;
}

