#pragma once
#include "Furniture.h"
#include "TypeTableSet.h"
#include <iostream>

class Table : public Furniture {

private:

    TypeTableSet m_type;

public:

    Table(int width, int height, int length, int quantity, TypeTableSet type) : m_type(type), Furniture(width, height, length, quantity) {}

    int price() override;

    void getInfo() override;

    TypeTableSet getType();

    int getId() override final;

    Furniture* clone() override final;

    int getQuantity() override final;

    void decreasesQuantity() override final;


};
