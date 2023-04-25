#pragma once
#include "Book.h"

struct Pair {
    Book book;
    int count;
};

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

class Library {

private:

    Pair* m_pairs;
    size_t m_size;
    size_t m_capacity;

    void copy(const Library& other);
    void erase();
    void resize();

public:

    Library();
    Library(const Library& other);
    ~Library();
    Library& operator=(const Library& other);

    Library(const Pair* pairs, const size_t numberOfPairs);

    int operator[] (const string name) const; //  търси по име на книгата и връща бройката
    void takeBook(Book& bookToTake);
    void sortLibrary();
    Book* allBooksWithAuthor(const Author& author);
    bool hasBookInLibrary(const Book& book);

    friend void writeToFile(const std::ostream fileToWriteIn, const Library& library);
    friend void readFromFile(const std::istream fileToReadFrom, Library& library);


    friend std::ostream& operator<< (std::ostream& out, const Library& library);
    friend std::istream& operator>> (std::istream& in, Library& library);

};