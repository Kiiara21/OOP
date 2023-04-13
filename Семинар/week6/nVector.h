#pragma once
#include <iostream>
#include <cassert>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;



class Nvector{
private:

    int *m_elements; // dynamic arrat
    size_t m_size;
    size_t m_capacity;

    void copy(const Nvector& other);
    void erase();

    void resize();

    bool isEmpty() const;
    bool isFull() const;

public:

    Nvector();
    Nvector(const Nvector& other);
    Nvector& operator=(const Nvector& other);
    ~Nvector();

    size_t getSize() const;
    size_t getCapacity() const;


    void push(int newElement);
    void pop();
    void clear();

    int &operator[](const size_t index);
    int const operator[](const size_t index) const;

    friend Nvector operator+(const Nvector& firstVector, const Nvector& secondVector);
    friend Nvector operator-(const Nvector& firstVector, const Nvector& secondVector);
    Nvector& operator*(const int scalar);

    bool areUsporedni(const Nvector& other);
    bool arePependikulerni(const Nvector& other);

    friend std::ostream& operator<<(std::ostream& out, const Nvector& nvector);
    friend std::istream& operator>>(std::istream& in, Nvector& nvector);

};  
