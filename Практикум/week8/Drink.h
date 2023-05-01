#pragma once
#include "MenuItem.h"

class Drink : public MenuItem {

private:

    string m_serveIn;

public:

    Drink(string serveIn, string name, string description, int quantity, double price): 
    MenuItem(name, description, quantity, price), m_serveIn(serveIn) {}

    void getInfo();
};
