#pragma once
#include "Furniture.h"
#include <iostream>

class Bed : public Furniture {

public:
    Bed(int width, int height, int length, int quantity) : Furniture(width, height, length, quantity) {}

    int price() override;

    void getInfo() override;

    int getId() override final;

    Furniture* clone() override final;

    int getQuantity() override final;

    void decreasesQuantity() override final;

};