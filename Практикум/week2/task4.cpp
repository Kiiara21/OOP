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

class Shisha{

private:    
    double m_price;
    char* m_type;
    char* m_taste; 

public: 

    Shisha() : m_price(0), m_type(nullptr), m_taste(nullptr){}

    Shisha(double price, const char* type, const char* taste) : m_type(nullptr), m_taste(nullptr) {
        setPrice(price);
        setType(type);
        setTaste(taste);
    }

    ~Shisha(){
        delete[] m_type;
        delete[] m_taste;
    }
    
    void print() const{
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

class Alcohol{

private:    
    double m_price;
    char* m_name;

public: 

    Alcohol() : m_price(0), m_name(nullptr) {};

    Alcohol(double price, const char* name) : m_name(nullptr) {
        setPrice(price);
        setName(name);
    }

    ~Alcohol(){
        delete[] m_name;
    }
    
    void print() const{
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

const size_t MAX = 1000;

class NightClub{

private:
    Baloon m_baloons[MAX];
    Shisha m_shishas[MAX];
    Alcohol m_alcohols[MAX];

    size_t m_numberOfBaloons;
    size_t m_numberOfShishas;
    size_t m_numberOfAlcohols;

    bool strCmp(const char* first, const char* second) const {
    
        size_t firstSize = strlen(first);
        size_t secondSize = strlen(second);

        if(firstSize != secondSize){
            return false;
        }

        for(int i = 0; i < firstSize; ++i){
            if(first[i] != second[i]){
                return false;
            }
        }

        return true;
    }

public:

    NightClub(){
        m_numberOfBaloons = 0;
        m_numberOfShishas = 0;
        m_numberOfAlcohols = 0;
    }

    int getNumberOfBaloons() const { return m_numberOfBaloons; }
    int getNumberOfAlcohols() const { return m_numberOfAlcohols; }
    int getNumberOfShishas() const { return m_numberOfShishas; }

    void addBallon(double ballonPrice, const char* ballonColor){
        m_baloons[m_numberOfBaloons].setColor(ballonColor);
        m_baloons[m_numberOfBaloons].setPrice(ballonPrice);
        m_numberOfBaloons++;
    }   

    void addShisha(double shishaPrice, const char* shishaType, const char* shishaTaste){
        m_shishas[m_numberOfShishas].setPrice(shishaPrice);
        m_shishas[m_numberOfShishas].setType(shishaType);
        m_shishas[m_numberOfShishas].setTaste(shishaTaste);
        m_numberOfShishas++;
    }

    void addAlcohol(double alcoholPrice, const char* alcoholName){
        m_alcohols[m_numberOfAlcohols].setPrice(alcoholPrice);
        m_alcohols[m_numberOfAlcohols].setName(alcoholName);
        m_numberOfAlcohols++;
    }
    
    void removeBalloon(const char* color){
        for(int i = 0; i < m_numberOfBaloons; ++i){
            if(strCmp(m_baloons[i].getColor(), color)){
                m_baloons[i].setPrice(m_baloons[m_numberOfBaloons - 1].getPrice());
                m_baloons[i].setColor(m_baloons[m_numberOfBaloons - 1].getColor());
            }
        }
        m_numberOfBaloons--;
    }

    void removeShisha(const char* type){
        for(int i = 0; i < m_numberOfShishas; ++i){
            if(strCmp(m_shishas[i].getType(), type)){
                m_shishas[i].setPrice(m_shishas[m_numberOfShishas - 1].getPrice());
                m_shishas[i].setType(m_shishas[m_numberOfShishas - 1].getType());
                m_shishas[i].setTaste(m_shishas[m_numberOfShishas - 1].getTaste());
            }
        }
        m_numberOfShishas--;
    }

    void removeAlcohol(const char* name){
        for(int i = 0; i < m_numberOfAlcohols; ++i){
            if(strCmp(m_alcohols[i].getName(), name)){
                m_alcohols[i].setName(m_alcohols[m_numberOfAlcohols - 1].getName());
                m_alcohols[i].setPrice(m_alcohols[m_numberOfAlcohols - 1].getPrice());
            }
        }
        m_numberOfAlcohols--;   
    }

    bool hasBalloonCheaperThan(int n) const {
        for(int i = 0; i < m_numberOfBaloons; ++i){
            if(m_baloons[i].getPrice() < n){
                return true;
            }
        }

        return false;
    }

    bool hasShishaWithTaste(const char* taste) const {
        for(int i = 0; i < m_numberOfShishas; ++i){
            if(strCmp(m_shishas[i].getTaste(), taste)){
                return true;
            }
        }

        return false;
    }

    bool hasAlcoholBetween(int A, int B) const {
        for(int i = 0; i < m_numberOfAlcohols; ++i){
            if(m_alcohols[i].getPrice() >= A && m_alcohols[i].getPrice() <= B){
                return true;
            }
        }

        return false;
    }

    void printBalloons() const {
        for(int i = 0; i < m_numberOfBaloons; ++i){
            m_baloons[i].print();
            std::cout << std::endl;
        }
    }

    void printAlcohols() const {
        for(int i = 0; i < m_numberOfAlcohols; ++i){
            m_alcohols[i].print();
            std::cout << std::endl;
        }
    }

    void printShishas() const {
        for(int i = 0; i < m_numberOfShishas; ++i){
            m_shishas[i].print();
            std::cout << std::endl;
        }
    }

    void printAll() const {
        printBalloons();
        printShishas();
        printAlcohols();
    }
};


int main(){

    NightClub nc;
    nc.addBallon(2, "Pink");
    nc.addBallon(2, "Pink");
    std::cout << nc.getNumberOfBaloons() << std::endl;
    nc.removeBalloon("Pink");
    std::cout << nc.getNumberOfBaloons() << std::endl;
    

    nc.addAlcohol(5, "vino");
    nc.addAlcohol(5, "vino");
    std::cout << nc.getNumberOfAlcohols() << std::endl;
    nc.removeAlcohol("vino");
    std::cout << nc.getNumberOfAlcohols() << std::endl;

    nc.addShisha(6, "ice", "ghjk");
    std::cout << nc.getNumberOfShishas() << std::endl;
    nc.removeShisha("ice");
    std::cout << nc.getNumberOfShishas();

    return 0;
}