#include <iostream>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

class MagicalBox{

private:
    int *m_elements;
    int m_numberOfElements;
    int m_capacity;

    void copy(const MagicalBox& other);
    void erase();
    bool isEmpty() const;
    bool isFull() const;
    void resize();

public:

    MagicalBox();
    MagicalBox(const MagicalBox& other);
    MagicalBox& operator=(const MagicalBox& other);
    ~MagicalBox();

    int getNumberOfElements() const;

    void insert(int newElement);
    int pop(); 

    void print() const;
};

void MagicalBox::resize(){
    int* newElements = new (std::nothrow) int [m_capacity * INCREASE_STEP];
    if(!newElements){
        std::cout << "Mempory problem!";
        return;
    }

    for(int i = 0; i < m_numberOfElements; ++i){
        newElements[i] = m_elements[i];
    }

    delete[] m_elements;
    m_elements = newElements;
    m_capacity *= INCREASE_STEP;
}

void MagicalBox::copy(const MagicalBox& other){
    m_numberOfElements = other.m_numberOfElements;
    m_capacity = other.m_capacity;
    
    m_elements = new (std::nothrow) int [m_capacity];
    if(!m_elements){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < m_numberOfElements; ++i){
        m_elements[i] = other.m_elements[i];
    }
}

bool MagicalBox::isEmpty() const{
    return m_numberOfElements == 0;
}

bool MagicalBox::isFull() const{
    return m_numberOfElements == m_capacity;
}

void MagicalBox::erase(){
    delete[] m_elements;
}

MagicalBox::MagicalBox(){
    m_capacity = 0;
    m_numberOfElements = 0;
    m_elements = nullptr;
}

MagicalBox::MagicalBox(const MagicalBox& other){
    copy(other);
}

MagicalBox& MagicalBox::operator=(const MagicalBox& other){
    if(&other != this){
        erase();
        copy(other);
    }
    return *this;
}

MagicalBox::~MagicalBox(){
    erase();
}

void MagicalBox::insert(int newElement){
    if(isFull()){
        resize();
    }

    m_elements[m_numberOfElements++] = newElement;
}

int MagicalBox::pop(){
    if(isEmpty()){
        std::cout << "Box is empty!";
        return -1;
    }
    
    int randomIndex = rand() % m_numberOfElements;
    std::cout << "\nRandom index: " << randomIndex << std::endl; 
    int result = m_elements[randomIndex];
    m_elements[randomIndex] = m_elements[m_numberOfElements - 1];
    m_numberOfElements--;
    return result;
} 

int MagicalBox::getNumberOfElements() const { return m_numberOfElements; }

void MagicalBox::print() const{
    std::cout << "\nNumber of elements: " << getNumberOfElements() << std::endl;
    for(int i = 0; i < m_numberOfElements; ++i){
        std::cout << m_elements[i] << " ";
    }
}


int main(){

    MagicalBox mb;
    mb.insert(1);
    mb.insert(10);
    mb.insert(12);
    mb.insert(4);
    mb.insert(16);
    std::cout << mb.pop();
    mb.print();

    return 0;
}