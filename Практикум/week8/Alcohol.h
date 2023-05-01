#pragma once
#include "Drink.h"

class Alcohol : public Drink {

private:

    int m_procentAlcohol;

public:

    Alcohol(int procentAlcohol, string name, string description, int quantity, double price, string serveIn):
    Drink(serveIn, name, description, quantity, price), m_procentAlcohol(procentAlcohol) {}

    void getInfo();
    int getProcent() const { return m_procentAlcohol; }
};
