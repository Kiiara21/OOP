#include <iostream>
#include <cstring>
#include <fstream>

class Baloon{

private:
    double m_price;
    char* m_color;

public:
    Baloon(){
        m_price = 0;
        m_color = nullptr;
    }

    Baloon(double price, const char* color) : m_color(nullptr) {
        setPrice(price);
        setColor(color);
    }

    ~Baloon(){
        delete[] m_color;
    }    

    void print() const{
        std::cout << "Price: " << m_price << "\nColor: " << m_color << "\n";
    }

    void setPrice(double price){
        m_price = price;
    }

    void setColor(const char* color){
        m_color = new (std::nothrow) char[strlen(color) + 1];
        if(!m_color){
            std::cout << "Memory porblem!";
            return;
        }
        strcpy(m_color, color);
    }

    double getPrice() const { return m_price; }
    char* getColor() const { return m_color; }

    friend std::ofstream& operator<<(std::ofstream& file, const Baloon& object){
        file << object.getPrice() << " " << object.getColor();
        return file;
    }

    friend std::ifstream& operator>>(std::ifstream& file, Baloon& object){
        file >> object.m_price >> object.m_color;
        return file;
    }
};

int main(){
    Baloon b(2.50, "pink");
    std::cout << b.getPrice() << " " << b.getColor() << std::endl;
    b.setPrice(3.50);
    b.setColor("blue");
    std::cout << b.getPrice() << " " << b.getColor() << std::endl;
    // b.print();   
    return 0;
}