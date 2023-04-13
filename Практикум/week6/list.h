#pragma once
#include <fstream>
#include <cassert>
#include <iostream>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

template <typename T>
class List {

private:

    T* m_elements;
    size_t m_size;
    size_t m_capacity;

    void erase();
    void copy(const List<T>& other);
    void resize();

    bool isEmpty() const;

    bool isContain(const T& element) const;


public:

    List();
    ~List();
    List(const List<T>& other);
    List& operator=(const List<T>& other);

    void add(const T& newElement);
    void remove(const unsigned int index);

    T operator[](const unsigned int index);
    T operator[](const unsigned int index) const;

    size_t getSize() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const List<U>& list);
    
    template <typename U>
    friend std::istream& operator>>(std::istream& out, List<U>& list);

};

template <typename T>
void List<T>::erase(){
    delete[] m_elements;
}

template <typename T>
void List<T>::copy(const List<T>& other){
    m_elements = new (std::nothrow) T [other.m_capacity];
    if(!m_elements){
        std::cout << "Memory porblem!";
        return;
    }
    for(int i = 0; i < other.m_size; ++i){
        m_elements[i] = other.m_elements[i];
    }
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}

template <typename T>
void List<T>::resize(){
    T* newElements = new (std::nothrow) T [m_capacity*INCREASE_STEP];
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

template <typename T>
bool List<T>::isEmpty() const{
    return m_size == 0;
}

template <typename T>
List<T>::List(){
    m_capacity = INITIAL_CAPACITY;
    m_size = 0;
    m_elements = new (std::nothrow) T [m_capacity];
}

template <typename T>
List<T>::~List(){
    erase();
}

template <typename T>
List<T>::List(const List<T>& other){
    copy(other);
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other){
    if(&other != this){
        erase();
        copy(other);
    }
}


template <typename T>
bool List<T>::isContain(const T& element) const {
    for(int i = 0; i < m_size; ++i){
        if(m_elements[i] == element){
            return true;
        }
    }
    return false;
}

template <typename T>
void List<T>::add(const T& newElement){
    if(isContain(newElement)){
        std::cout << "The element already exist in the list!\n";
        return;
    }

    if(m_size == m_capacity){
        resize();
    }

    m_elements[m_size++] = newElement;
}

template <typename T>
void List<T>::remove(const unsigned int index){
    m_elements[index] = m_elements[m_size - 1];
    m_size--;
}

template <typename T>
T List<T>::operator[](const unsigned int index){
    assert(index < m_size);
    return m_elements[index];
}

template <typename T>
T List<T>::operator[](const unsigned int index) const{
    assert(index < m_size);
    return m_elements[index];   
}

template <typename T>
size_t List<T>::getSize() const{
    return m_size;
}

template <typename U>
std::ostream& operator<<(std::ostream& out, const List<U>& list){
    for(int i = 0; i < list.m_size; ++i){
        out << list.m_elements[i] << " "; 
    }
    return out;
}

template <typename U>
std::istream& operator>>(std::istream& in, List<U>& list){
    in >> list.m_size;
    for(int i = 0; i < list.m_size; ++i){
        in >> list.m_elements[i];
    }

    return in;
}
