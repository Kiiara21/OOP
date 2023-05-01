#include "Food.h"

void Food::getInfo(){
    MenuItem::getInfo();
    std::cout << m_isBig << " " << m_isVegan << "\n";
}