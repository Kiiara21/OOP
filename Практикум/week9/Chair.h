#pragma once
#include "Furniture.h"
#include "TypeChairSet.h"
#include <iostream>

class Chair : public Furniture {

private:

    TypeChairSet m_type;

public:

    Chair(int width, int height, int length, int quantity, TypeChairSet type) : m_type(type), Furniture(width, height, length, quantity) {}
    
    int price() override;

    void getInfo() override;

    TypeChairSet getType();

    int getId() override final;

    Furniture* clone() override final;

    int getQuantity() override final;

    void decreasesQuantity() override final;
};

