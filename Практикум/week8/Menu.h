#pragma once

#include "Food.h"
#include "Alcohol.h"

const size_t INITIAL_CAPACITY = 2;
const size_t INCRESE_STEP = 2;

class Menu {

private:

    MenuItem* m_items;

    size_t m_size;
    size_t m_capacity;

    int m_numberOfNonAlcoholDrinks;


    void erase();
    void resize();
    void add(MenuItem itemToAdd);

public:

    Menu(){
        m_size = 0;
        m_capacity = INITIAL_CAPACITY;
        m_numberOfNonAlcoholDrinks = 0;
        m_items = new (std::nothrow) MenuItem [INITIAL_CAPACITY];
        if(!m_items){
            std::cout << "Memory problem!";
            return;
        }
    }

    Menu(const Menu& other) = delete;
    Menu& operator=(const Menu& other) = delete;
    ~Menu();

    void addMenuItem(string name, string description, int quantity, double price);
    void addDrink(Drink& drinkToAdd);
    void addAlcohol(Alcohol& alcoholToAdd);
    void addFood(Food& foodToAdd);

    void print() const;
    MenuItem cheaperItem();

    int getNumberOfItems() const { return m_size; }

    int numberOfNonAlcoholDrinks() const;
    // Drink& mostAlcoholDrink() const;
    
};
