#pragma once
#include "MenuItem.h"

class Food : public MenuItem {

private:

    bool m_isBig;
    bool m_isVegan;

public:

    Food(bool isBig, bool isVegan, string name, string description, int quantity, double price) : 
    MenuItem(name, description, quantity, price), m_isBig(isBig), m_isVegan(isVegan) {}

    void getInfo();
};