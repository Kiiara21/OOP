#pragma once

#include <iostream>

template <typename T>
class Queue {

private: 

    static const size_t INITIAL_CAPACITY = 2;
    static const size_t INCREASE_STEP = 2;  

private:    

    T* m_elemens;

    T m_front;
    T m_back;

    size_t m_size;
    size_t m_capacity;

private:
    
    void resize();
    void erase();
    void copy(const Queue& other);

public:
    Queue();
    ~Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);

    bool isEmpty();
    bool isFull();

public:

    T dequeue();
    void enqueue(T newElement);
    T peek();

    T front();
    T back();

    size_t getSize() const { return m_size; }
};

template <typename T>
void Queue<T>::resize(){
    T* newElements = new (std::nothrow) T[m_capacity * INCREASE_STEP];
    if(!newElements){
        std::cout << "throw exception!";
        return;
    }

    for(int i = 0; i < m_size; ++i){
        newElements[i] = m_elemens[i];
    }

    erase();
    m_elemens = newElements;
    m_capacity *= INCREASE_STEP;
}

template <typename T>
void Queue<T>::erase(){
    m_front = -100;
    m_back = -100;
    delete[] m_elemens;
}

template <typename T>
void Queue<T>::copy(const Queue& other){
    m_elemens = new (std::nothrow) T[other.m_capacity];
    if(!m_elemens){
        return;
    }
    for(int i = 0; i < other.m_size; ++i){
        m_elemens[i] = other.m_elemens[i];
    }

    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_front = other.m_front;
    m_back = other.m_back;
}

template <typename T>
bool Queue<T>::isEmpty(){
    return m_size == 0;
}

template <typename T>
bool Queue<T>::isFull(){
    return m_size == m_capacity;
}

template <typename T>
Queue<T>::Queue(){
    m_elemens = new (std::nothrow) T [INITIAL_CAPACITY];
    if(!m_elemens){
        return;
    }
    m_size = 0;
    m_capacity = INITIAL_CAPACITY;
    m_front = m_back = -100;
}

template <typename T>
Queue<T>::~Queue(){
    erase();
}

template <typename T>
Queue<T>::Queue(const Queue& other){
    copy(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other){
    if(&other != this){
        erase();
        copy(other);
    }
    return *this;
}   

template <typename T>
T Queue<T>::dequeue(){
    T lastElement = -100;
    if(m_size == 1){
        m_back = m_front = -100;
        lastElement = m_elemens[0];
    }
    else
        lastElement = m_elemens[m_size-1];
        m_back = m_elemens[m_size-2];
    
    m_size--;
    return lastElement;
}

template <typename T>
void Queue<T>::enqueue(T newElement){   
    if(isFull()){
        resize();
    }

    if(m_size == 0){
        m_front = m_back = newElement;
    }
    else
        m_back = newElement;

    m_elemens[m_size++] = newElement;
}

template <typename T>
T Queue<T>::peek(){
    if(isEmpty()){
        std::cout << "Queue is empty!";
        return -100;
    }
    return m_elemens[m_size - 1];
}	


template <typename T>
T Queue<T>::front() {
    if(isEmpty()){
        m_front = -100;
    }
    return m_front;
}

template <typename T>
T Queue<T>::back(){
    if(isEmpty()){
        m_back = -100;
    }
    return m_back;
}