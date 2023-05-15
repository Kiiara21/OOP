#include "Table.h"

int Table::price(){
    return m_width * m_length * 15;
}

void Table::getInfo(){
    std::cout << m_width << " " << m_height << " " << m_length << " " << m_quantity << " " << m_id << "\n";
}

TypeTableSet Table::getType(){
    return m_type;
}

int Table::getId(){
    return m_id;
}

Furniture* Table::clone(){
    return new Table(*this);
}

int Table::getQuantity(){
    return m_quantity;
}

void Table::decreasesQuantity(){
    m_quantity--;
}