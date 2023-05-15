#include "Bed.h"

int Bed::price(){
    return m_length * m_height * 22;
}

void Bed::getInfo(){
    std::cout << m_width << " " << m_height << " " << m_length << " " << m_quantity << " " << m_id << "\n";
}

int Bed::getId(){
    return m_id;
}

Furniture* Bed::clone(){
    return new Bed(*this);    
}

int Bed::getQuantity(){
    return m_quantity;
}

void Bed::decreasesQuantity(){
    m_quantity--;
}