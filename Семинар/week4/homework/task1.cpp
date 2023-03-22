#include <iostream>
#include <cstring>
#include <cassert>

const size_t MAX = 128;

class Beer {

private:
    char m_brand[MAX];
    int m_quantity;
    
public:

    Beer(const char brand[MAX], const int quantity);

    void setBrand(const char* brand);
    void setQuantity(const int quantity);

    const char* getBrand() const; 
    int getQuantity() const;

    void add(Beer& beerToAdd, int mlToAdd);
    void addInBeer(int mlToAdd);
    bool check(const char* givenBrand);

    void print() const;
};

Beer::Beer(const char* brand, const int quantity) : m_quantity(quantity) {
    assert(brand != nullptr);
    strcpy(m_brand, brand);
}

void Beer::setBrand(const char* brand){
    assert(brand != nullptr);
    strcpy(m_brand, brand);
}

void Beer::setQuantity(const int quantity){
    m_quantity = quantity;
}

const char* Beer::getBrand() const { return m_brand; } 

int Beer::getQuantity() const { return m_quantity; }

void Beer::add(Beer& beerToAdd, int mlToAdd){
    strcat(m_brand, "&");
    strcat(m_brand, beerToAdd.getBrand());
    setQuantity(m_quantity + mlToAdd);
    beerToAdd.setQuantity(beerToAdd.getQuantity() - mlToAdd);
}

void Beer::addInBeer(int mlToAdd){
    setQuantity(m_quantity + mlToAdd);
}

bool Beer::check(const char* givenBrand){
    return strstr(m_brand, givenBrand) != nullptr;
}

void Beer::print() const {
    std::cout << m_brand << " " << m_quantity << std::endl;
}

int main(){

    Beer beer1("Corona", 500), beer2("Heineken", 500);

    beer1.print();
    beer2.print();

    beer1.add(beer2, 250);

    beer1.print();
    beer2.print();

    std::cout << std::boolalpha << beer1.check("Heineken") << std::endl;
    std::cout << std::boolalpha << beer1.check("Stella Artois") << std::endl;
    std::cout << std::boolalpha << beer1.check(beer2.getBrand()) << std::endl;
    
    return 0;
}