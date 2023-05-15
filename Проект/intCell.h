#pragma once
#include "Cell.h"

class IntCell : public Cell{

private:

    int m_data;

public:

    IntCell(int data) : Cell(), m_data(data) {}

    void printData() const override final {
        std::cout << m_data << " ";
    }

    int getData() const { return m_data; }

    friend std::ostream& operator<<(std::ostream& out, const IntCell& intCell);

    virtual ~IntCell () = default;
};

std::ostream& operator<<(std::ostream& out, const IntCell& intCell){
    out << intCell.m_data;
    return out;
}