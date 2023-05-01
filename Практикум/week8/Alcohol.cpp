#include "Alcohol.h"

void Alcohol::getInfo(){
    Drink::getInfo();
    std::cout << m_procentAlcohol << "\n";
}