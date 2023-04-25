#include "Book.h"

Book::Book(){
    m_name = "";
    m_numberOfAuthors = 0;
    m_price = 0;
    m_text = "";
}

void Book::print() const {
    std::cout << *this;
}

Book::Book(const string name, const Author* author, const size_t numberOfAuthors, const double price, const string text){
    
    if(name == ""){
        throw std::invalid_argument("Name is empty string");
    }
    m_name = name;
    
    if(numberOfAuthors <= 0){
        throw std::invalid_argument("Book can`t have zero or less authors");
    }
    m_numberOfAuthors = numberOfAuthors;

    if(price < 0){
        throw std::invalid_argument("Negative price");
    }
    m_price = price;
    
    if(text == ""){
        throw std::invalid_argument("Text is empty string");
    }
    m_text = text;
        
    for(int i = 0; i < m_numberOfAuthors; ++i){
        m_author[i] = author[i];
    }

}

string Book::getName() const{
    return m_name;
}

double Book::getPrice() const{
    return m_price;
}

string Book::getText() const{
    return m_text;
}

bool Book::hasAuthor(const string name, const string lastname) const{
    for(int i = 0; i < m_numberOfAuthors; ++i){
        if(m_author[i].getName() == name && m_author[i].getLastName() == lastname){
            return true;
        }
    }
    return false;
}

void Book::setPrice(const double price){
    if(price < 0){
        throw std::invalid_argument("negative price");
    }
    m_price = price;
}

std::ostream& operator<< (std::ostream& out, const Book& book){
    out << book.m_name << "\n";
    for(int i = 0; i < book.m_numberOfAuthors; ++i){
        out << book.m_author[i] << " ";
    }
    out << book.m_price << "\n" << book.m_text;
    return out;
}

bool Book::operator==(const Book& other){

    for(int i = 0; i < m_numberOfAuthors; ++i){
        if(m_author[i].getEmail() != other.m_author[i].getEmail()){
            return false;
        }
    }

    return (m_name == other.m_name && m_numberOfAuthors == other.m_numberOfAuthors &&
            m_price == other.m_price && m_text == other.m_text);
}


std::istream& operator>> (std::istream& in, Book& book){
    in >> book.m_name;
    for(int i = 0; i < book.m_numberOfAuthors; ++i){
        in >> book.m_author[i];
    }
    in >> book.m_price;
    in >> book.m_text;
    return in;
}
