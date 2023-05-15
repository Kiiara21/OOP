#pragma once

class Furniture {

protected:
    int m_width;
    int m_height;
    int m_length;
    int m_quantity;

    static int s_counter;
    unsigned int m_id;

public: 

    Furniture(int width, int height, int length, int quantity) : m_height(height), m_width(width), m_length(length), m_quantity(quantity) {
        for(int i = 0; i < quantity; ++i){
            m_id = s_counter++;
        }
    }

    virtual int price() = 0;
    virtual void getInfo() = 0;
    virtual int getId() = 0;

    virtual Furniture* clone() = 0;

    virtual int getQuantity() = 0;

    virtual void decreasesQuantity() = 0;

    virtual ~Furniture() = default;
};
