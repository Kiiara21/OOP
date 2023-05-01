#include "Drink.h"

void Drink::getInfo(){
    MenuItem::getInfo();
    std::cout << m_serveIn << "\n";
}