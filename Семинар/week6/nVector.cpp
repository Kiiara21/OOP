#include "nVector.h"

void Nvector::copy(const Nvector& other){
    m_elements = new (std::nothrow) int [other.m_capacity];
    if(!m_elements){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < other.m_size; ++i){
        m_elements[i] = other.m_elements[i];
    }

    m_size = other.m_size;
    m_capacity = other.m_capacity;
}

void Nvector::erase(){
    delete[] m_elements;
}

void Nvector::resize(){
    int* newElements = new (std::nothrow) int [m_capacity * INCREASE_STEP];
    if(!newElements){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < m_size; ++i){
        newElements[i] = m_elements[i];
    }

    erase();
    m_elements = newElements;
    m_capacity *= INCREASE_STEP;
}

bool Nvector::isEmpty() const{
    return m_size == 0;
}

bool Nvector::isFull() const{
    return m_size == m_capacity;
}

Nvector::Nvector(){
    m_elements = new (std::nothrow) int [INITIAL_CAPACITY];
    if(!m_elements){
        std::cout << "Memory problem!";
        return;
    }  
    m_size = 0;
    m_capacity = INITIAL_CAPACITY;
}

Nvector::Nvector(const Nvector& other){
    copy(other);
}

Nvector& Nvector::operator=(const Nvector& other){
    if(&other != this){
        erase();
        copy(other);
    }

    return *this;
}

Nvector::~Nvector(){
    erase();
}

size_t Nvector::getSize() const{
    return m_size;
}

size_t Nvector::getCapacity() const{
    return m_capacity;
}

void Nvector::push(int newElement){
    if(isFull()){
        resize();
    }
    m_elements[m_size++] = newElement;
}

void Nvector::pop(){    
    if(isEmpty()){
        std::cout << "Vector is empty!";
        return;
    }
    m_size--;
}

void Nvector::clear(){
    m_size = 0;
}

int &Nvector::operator[](const size_t index){
    assert(m_size > index);
    return m_elements[index];
}

int const Nvector::operator[](const size_t index) const{
    assert(m_size > index);
    return m_elements[index];
}

Nvector operator+(const Nvector& firstVector, const Nvector& secondVector){
    Nvector result;
    assert(firstVector.getSize() == secondVector.getSize());
    for(int i = 0; i < firstVector.getSize(); ++i){
        result.push(firstVector.m_elements[i] + secondVector.m_elements[i]);
    }
    
    return result;
}

Nvector operator-(const Nvector& firstVector, const Nvector& secondVector){
    Nvector result;
    assert(firstVector.getSize() == secondVector.getSize());
    for(int i = 0; i < firstVector.getSize(); ++i){
        result.push(firstVector.m_elements[i] - secondVector.m_elements[i]);
    }
    
    return result;
}
    
Nvector& Nvector::operator*(const int scalar){
    for(int i = 0; i < m_size; ++i){
        m_elements[i] *= scalar;
    }
    return *this;
}

// bool Nvector::areUsporedni(const Nvector& other);
// bool Nvector::arePependikulerni(const Nvector& other);

std::ostream& operator<<(std::ostream& out, const Nvector& nvector){
    for(int i = 0; i < nvector.m_size; ++i){
        out << nvector.m_elements[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Nvector& nvector){
    in >> nvector.m_size;
    
    for(int i = 0; i < nvector.getSize(); ++i){
        in >> nvector.m_elements[i];
    }

    return in;
}
