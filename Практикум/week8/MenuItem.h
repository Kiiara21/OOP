#pragma once
#include <string>
#include <iostream>

using std::string;

class MenuItem {

private:
    
    string m_name;
    string m_description;
    int m_quantity;
    double m_price;

public:
    
    MenuItem() : m_name(""), m_description(""), m_quantity(0), m_price(0.0) {}

    MenuItem(string name, string description, int quantity, double price): 
    m_name(name), m_description(description), m_quantity(quantity), m_price(price){}

    string getName() const { return m_name; }
    string getDescription() const { return m_description; }
    int getQuantity() const { return m_quantity; }
    double getPrice() const { return m_price; }
    void getInfo();
};
