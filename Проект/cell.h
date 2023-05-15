#pragma once
#include <iostream>
#include <string>
using std::string;

class Cell {

protected:

    static int s_cellId;
    unsigned int m_cellId;

public:

    Cell(){
        m_cellId = s_cellId++;
    }

    virtual void printData() const {
        std::cout << m_cellId << " ";
    }

    virtual unsigned int getId() const { return m_cellId; }

    virtual ~Cell() = default;

    virtual std::ostream& operator<<(std::ostream& out, const Cell& cell) = 0;
};

int Cell::s_cellId = 1;






