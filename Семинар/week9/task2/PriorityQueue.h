#pragma once

#include <iostream>

template <typename T>
struct item{
    T m_data = {T()};
    int m_priority = {0};
};

template <typename T>
class PriorityQueue {

private: 

    static const size_t INITIAL_CAPACITY = 2;
    static const size_t INCREASE_STEP = 2;  
    static const int INVALID_VALUE = -100;

private:    

    int m_maxPriority;
    
    item<T>* m_elemens;

    item<T> m_front;
    item<T> m_back;

    size_t m_size;
    size_t m_capacity;

private:
    
    void resize();
    void erase();
    void copy(const PriorityQueue& other);

public:
    PriorityQueue(int priority);
    PriorityQueue();
    ~PriorityQueue();
    PriorityQueue(const PriorityQueue& other);
    PriorityQueue& operator=(const PriorityQueue& other);

    bool isEmpty();
    bool isFull();

public:
    
    item<T> dequeue();
    void enqueue(item<T> newElement);
    item<T> peek();

    item<T> front();
    item<T> back();

    size_t getSize() const { return m_size; }
    int getPriorityByIndex(int index) const;
    T getDataByIndex(int index);

    void sort();
};

template <typename T>
T PriorityQueue<T>::getDataByIndex(int index){
    if(index > m_size || index < 0) throw std::out_of_range("Invaild index!");

    for(int i = 0; i < m_size; ++i){
        if(i == index){
            return m_elemens[i].m_data;
        }
    }
    return T();
}


template <typename T>
int PriorityQueue<T>::getPriorityByIndex(int index) const{
    if(index > m_size || index < 0) throw std::out_of_range("Invaild index!");

    for(int i = 0; i < m_size; ++i){
        if(i == index){
            return m_elemens[i].m_priority;
        }
    }
    return -1;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(int priority){
    m_maxPriority = priority;
    m_elemens = new (std::nothrow) item<T> [INITIAL_CAPACITY];
    if(!m_elemens) throw std::bad_alloc();
    m_size = 0;
    m_capacity = INITIAL_CAPACITY;
}

template <typename T>
void PriorityQueue<T>::resize(){
    item<T>* newElements = new (std::nothrow) item<T>[m_capacity * INCREASE_STEP];
    if(!newElements) throw std::bad_alloc();

    for(int i = 0; i < m_size; ++i){
        newElements[i] = m_elemens[i];
    }

    erase();
    m_elemens = newElements;
    m_capacity *= INCREASE_STEP;
}

template <typename T>
void PriorityQueue<T>::erase(){
    m_front.m_data = INVALID_VALUE;
    m_back.m_data = INVALID_VALUE;
    delete[] m_elemens;
}

template <typename T>
void PriorityQueue<T>::copy(const PriorityQueue& other){
    m_elemens = new (std::nothrow) item<T>[other.m_capacity];
    if(!m_elemens) throw std::bad_alloc();

    for(int i = 0; i < other.m_size; ++i){
        if(other.m_elemens[i].m_priority > m_maxPriority){
            throw std::invalid_argument("Priority is invalid!");
        }
        m_elemens[i] = other.m_elemens[i];
    }

    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_front = other.m_front;
    m_back = other.m_back;
}

template <typename T>
bool PriorityQueue<T>::isEmpty(){
    return m_size == 0;
}

template <typename T>
bool PriorityQueue<T>::isFull(){
    return m_size == m_capacity;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(){
    m_maxPriority = 0;
    m_elemens = new (std::nothrow) item<T> [INITIAL_CAPACITY];
    if(!m_elemens) throw std::bad_alloc();

    m_size = 0;
    m_capacity = INITIAL_CAPACITY;
    m_front = m_back = INVALID_VALUE;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue(){
    erase();
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& other){
    copy(other);
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue& other){
    if(&other != this){
        erase();
        copy(other);
    }
    return *this;
}   

template <typename T>
void PriorityQueue<T>::sort(){
    for(int i = 0; i < m_size; ++i){
        for(int j = i + 1; j < m_size; ++j){
            if(m_elemens[i].m_priority > m_elemens[j].m_priority){
                item temp = m_elemens[i];
                m_elemens[i] = m_elemens[j];
                m_elemens[j] = temp;
            }
        }
    }
}


template <typename T>
item<T> PriorityQueue<T>::dequeue(){
    sort();
    item<T> lastElement;
    if(m_size == 1){
        m_back.m_data = m_front.m_data = INVALID_VALUE;
        lastElement = m_elemens[0];
    }
    else
        lastElement = m_elemens[m_size-1];
        m_back = m_elemens[m_size-2];
    
    m_size--;
    return lastElement;
}

template <typename T>
void PriorityQueue<T>::enqueue(item<T> newElement){   
    if(newElement.m_priority > m_maxPriority) throw std::invalid_argument("Priority is invalid!");
    if(newElement.m_data == INVALID_VALUE) throw std::invalid_argument("New element is nullptr!");

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
item<T> PriorityQueue<T>::peek(){
    if(isEmpty()) throw std::out_of_range("The queue is empty!");
    sort();
    return m_elemens[m_size - 1];
}	

template <typename T>
item<T> PriorityQueue<T>::front(){
    if(isEmpty()){
        m_front.m_data = INVALID_VALUE;
        m_front.m_priority = -1;
    }
    return m_front;
}

template <typename T>
item<T> PriorityQueue<T>::back(){
    if(isEmpty()){
        m_back.m_data = INVALID_VALUE;
        m_back.m_priority = -1;
    }
    return m_back;
}