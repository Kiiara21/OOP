#pragma once
#include "Author.h"

const size_t MAX = 128;

class Book {

private:

    string m_name;
    Author m_author[MAX];
    double m_price;
    string m_text;

    size_t m_numberOfAuthors;

    void print() const;

public:
    Book();
    Book(const string name, const Author* author, const size_t numberOfAuthors, const double price, const string text);
    string getName() const;
    double getPrice() const;
    string getText() const;

    bool hasAuthor(const string name, const string lastname) const;
    void setPrice(const double price);

    friend std::ostream& operator<< (std::ostream& out, const Book& book);
    friend std::istream& operator>> (std::istream& in, Book& book);

    bool operator==(const Book& other);
};  
