#include "Menu.h"

void Menu::add(MenuItem itemToAdd){
    if(m_size == m_capacity){
        resize();
    }
    m_items[m_size++] = itemToAdd;
}

void Menu::addMenuItem(string name, string description, int quantity, double price){
    add(MenuItem(name, description, quantity, price));
}

void Menu::addDrink(Drink& drinkToAdd) {
    add(drinkToAdd);
} 

void Menu::addAlcohol(Alcohol& alcoholToAdd) {

    if(alcoholToAdd.getProcent() == 0){
        m_numberOfNonAlcoholDrinks++;
    }
    add(alcoholToAdd);
}

void Menu::addFood(Food& foodToAdd) {
    add(foodToAdd);
}

void Menu::print() const {
    for(int i = 0; i < m_size; ++i){
        m_items[i].getInfo();
    }
}

MenuItem Menu::cheaperItem() {
    MenuItem cheaperItem = m_items[0];
    for(int i = 0; i < m_size; ++i){
        if(m_items[i].getPrice() < cheaperItem.getPrice()){
            cheaperItem = m_items[i];
        }
    }
    return cheaperItem;
}

int Menu::numberOfNonAlcoholDrinks() const { return m_numberOfNonAlcoholDrinks; }

// Drink& Menu::mostAlcoholDrink() const { }

Menu::~Menu(){
    erase();
}

void Menu::erase(){
    delete[] m_items;
}

void Menu::resize(){
    MenuItem* newItems = new (std::nothrow) MenuItem [m_capacity * INCRESE_STEP];
    if(!newItems){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < m_size; ++i){
        newItems[i] = m_items[i];
    }

    erase();
    m_items = newItems;
    m_capacity *= INCRESE_STEP;
}