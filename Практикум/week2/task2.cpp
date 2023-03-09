#include <iostream>
#include <cstring>
#include <fstream>

class Shisha{

private:    
    double m_price;
    char* m_type; // marka 
    char* m_taste; 

public: 

    Shisha() : m_price(0){
        setTaste("");
        setType("");
    };

    Shisha(double price, const char* type, const char* taste) : m_price(price), m_type(nullptr), m_taste(nullptr) {
        setType(type);
        setTaste(taste);
    }

    ~Shisha(){
        delete[] m_type;
        delete[] m_taste;
    }
    
    void print(){
        std::cout << "Price: " << m_price << "\nType: " << m_type << "\nTaste: " << m_taste << std::endl;
    }
    
    void setPrice(double price){
        m_price = price;
    }

    void setType(const char* type){   
        m_type = new (std::nothrow) char[(strlen(type) + 1)];
        if(!m_type){
            std::cout << "Memory problem!";
            return;
        }
        strcpy(m_type, type);
    }

    void setTaste(const char* taste){
        m_taste = new (std::nothrow) char[(strlen(taste) + 1)];
        if(!m_taste){
            std::cout << "Memory problem!";
            return;
        }
        strcpy(m_taste, taste);
    }

    double getPrice() const { return m_price; }
    char* getType() const { return m_type; }
    char* getTaste() const { return m_taste; }

    friend std::ofstream& operator<<(std::ofstream& file, const Shisha& object){
        file << object.getPrice() << " " << object.getType() << " " << object.getTaste();
        return file;
    }

    friend std::ifstream& operator>>(std::ifstream& file, Shisha& object){
        file >> object.m_price >> object.m_type >> object.m_taste;
        return file;
    }

};


int main(){

    Shisha s(11.9, "bla", "blabla");

    s.print();
    return 0;
}