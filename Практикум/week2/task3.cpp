#include <iostream>
#include <cstring>
#include <fstream>

class Alcohol{

private:    
    double m_price;
    char* m_name; // marka

public: 

    Alcohol() : m_price(0){
        setName("");
    };

    Alcohol(double price, const char* name) : m_price(price), m_name(nullptr) {
        setName(name);
    }

    ~Alcohol(){
        delete[] m_name;
    }
    
    void print(){
        std::cout << "Price: " << m_price << "\nName: " << m_name << std::endl;
    }
    
    void setPrice(double price){
        m_price = price;
    }

    void setName(const char* name){
        m_name = new (std::nothrow) char[(strlen(name) + 1)];
        if(!m_name){
            std::cout << "Memory problem!";
            return;
        }
        strcpy(m_name, name);
    }

    double getPrice() const { return m_price; }
    char* getName() const { return m_name; }

    friend std::ofstream& operator<<(std::ofstream& file, const Alcohol& object){
        file << object.getPrice() << " " << object.getName();
        return file;
    }

    friend std::ifstream& operator>>(std::ifstream& file, Alcohol& object){
        file >> object.m_price >> object.m_name;
        return file;
    }

};



int main(){

    Alcohol s(11.9, "bla");

    s.print();
    return 0;
}