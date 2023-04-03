#include <iostream>
#include <cstring>
#include <cassert>

struct Procesor{
    int frequency{0};
    int cores{0};
    int memory{0};
};

class Laptop {

private:
    char* m_brand;
    char* m_model;
    double m_price;
    double m_size;
    Procesor m_procesor;
    int m_ram;
    int m_batteryCapacity;

    void copy(const Laptop& other);
    void erase();

public:
    Laptop();
    Laptop(const Laptop& other);
    Laptop& operator=(const Laptop& other);
    ~Laptop();

    Laptop(const char* brand, const char* model, double price, double size, Procesor procesor, int ram, int batteryCapacity);
    
    const char* getBrand() const;
    const char* getModel() const;
    double getPrice() const;
    double getSize() const;
    int getRam() const;
    int getBatteryCapacity() const;

    void print() const;
    void printProcesor() const;

    void updateProcesor(Procesor& newProcesor);
    void updateRam(int newRam);
};

Laptop::Laptop() : Laptop("", "", 0, 0, Procesor{}, 0, 0){}

Laptop::Laptop(const Laptop& other){
    copy(other);
}

Laptop::Laptop(const char* brand, const char* model, double price, double size, Procesor procesor, int ram, int batteryCapacity){
    assert(brand != nullptr);
    assert(model != nullptr);

    m_brand = new (std::nothrow) char [strlen(brand) + 1];
    if(!m_brand){
        std::cout << "Memory porblem!";
        return;
    }
    strcpy(m_brand, brand);
    
    m_model = new (std::nothrow) char [strlen(model) + 1];
    if(!m_model){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_model, model);

    m_price = price;
    m_size = size;
    m_procesor = procesor;
    m_ram = ram;
    m_batteryCapacity = batteryCapacity;
}

Laptop& Laptop::operator=(const Laptop& other){
    if(&other != this){
        erase();
        copy(other);
    }
    return *this;
}

Laptop::~Laptop(){
    erase();
}

void Laptop::copy(const Laptop& other){
    m_brand = new (std::nothrow) char [strlen(other.m_brand) + 1];
    if(!m_brand){
        std::cout << "Memory porblem!";
        return;
    }
    strcpy(m_brand, other.m_brand);

    m_model = new (std::nothrow) char [strlen(other.m_model) + 1];
    if(!m_model){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_model, other.m_model);
    
    m_price = other.m_price;
    m_size = other.m_size;
    m_procesor = other.m_procesor;
    m_ram = other.m_ram;
    m_batteryCapacity = other.m_batteryCapacity;
}

void Laptop::erase(){
    delete[] m_brand;
    delete[] m_model;
}

const char* Laptop::getBrand() const{
    return m_brand;
}

const char* Laptop::getModel() const{
    return m_model;
}

double Laptop::getPrice() const{
    return m_price;
}

double Laptop::getSize() const{
    return m_size;
}

int Laptop::getRam() const{
    return m_ram;
}

int Laptop::getBatteryCapacity() const{
    return m_batteryCapacity;
}

void Laptop::updateProcesor(Procesor& newProcesor){
    assert(newProcesor.cores > 0);
    assert(newProcesor.frequency > 0);
    assert(newProcesor.memory > 0);

    if(m_procesor.cores < newProcesor.cores || m_procesor.memory < newProcesor.memory){
        std::cout << "\nUpdating processor...";
        m_procesor = newProcesor;
    } else std::cout << "\nThe old processor is better!";
}

void Laptop::updateRam(int newRam){
    assert(newRam > 0);

    if(m_ram < newRam){
        std::cout << "\nUpdating RAM...";
        m_ram = newRam;
    } else std::cout << "\nThe old RAM is better!";
}

void Laptop::printProcesor() const{
    std::cout << "\nProcesor: " << m_procesor.cores << " " << m_procesor.frequency << " " << m_procesor.memory << std::endl;
}

void Laptop::print() const { 
    printProcesor();
    std::cout << getBrand() << " " << getModel() << " " << getPrice() << " " << getSize() << " " << getRam() << " " << getBatteryCapacity() << std::endl; 
}

int main(){
    Procesor p1, p2;
    p1.cores = 5;
    p1.frequency = 128;
    p1.memory = 64;

    p2.cores = 4;
    p2.frequency = 128;
    p2.memory = 32;
    
    Laptop laptop("Lenovo", "Yoga", 100, 13.5, p1, 128, 6000);
    laptop.print();
    laptop.updateProcesor(p2);
    laptop.print();

    laptop.print();
    laptop.updateRam(64);
    laptop.print();

    return 0;
}