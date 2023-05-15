#pragma one
#include "Cell.h"

class DoubleCell : public Cell{

private:

    double m_data;

public:

    DoubleCell(double data) : Cell(), m_data(data) {}

    void printData() const override final {
        std::cout << m_data << " ";
    }

    double getData() const { return m_data; }

    friend std::ostream& operator<<(std::ostream& out, const DoubleCell& doubleCell);
    
    virtual ~DoubleCell () = default;
};

std::ostream& operator<<(std::ostream& out, const DoubleCell& doubleCell){
    out << doubleCell.m_data;
    return out;
}
