#include "Chair.h"

int Chair::price(){
    return m_height * m_width * 9;
}

void Chair::getInfo(){
    std::cout << m_width << " " << m_height << " " << m_length << " " << m_quantity << " " << m_id << "\n";
}

TypeChairSet Chair::getType(){
    return m_type;
}

int Chair::getId(){
    return m_id;
}

Furniture* Chair::clone(){
    return new Chair(*this);
}

int Chair::getQuantity(){
    return m_quantity;
}

void Chair::decreasesQuantity(){
    m_quantity--;
}