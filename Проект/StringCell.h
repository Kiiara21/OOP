#pragma one
#include "Cell.h"

class StringCell : public Cell{

private:

    string m_data;

public:

    StringCell(string data) : Cell(), m_data(data) {}

    void printData() const override final {
        std::cout << m_data << " ";
    }

    string getData() const { return m_data; }

    friend std::ostream& operator<<(std::ostream& out, const StringCell& strnigCell);

    virtual ~StringCell () = default;
};

std::ostream& operator<<(std::ostream& out, const StringCell& stringCell){
    out << stringCell.m_data;
    return out;
}