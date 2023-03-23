#include <iostream>
#include <cassert>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2; 

template <typename T>
class Vector{

private:
    T* m_elements;
    size_t m_size;
    size_t m_capacity;

    void deallocate(){
        // whats going on when we have T = char*?
        delete[] m_elements;
    }

    void copy(const Vector<T>& other){
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_elements = new (std::nothrow) T[m_capacity];
        if(!m_elements){
            std::cout << "Memory problem!";
            return;
        }

        for(int i = 0; i < m_size; ++i){
            m_elements[i] = other.m_elements[i];
        }
    }

    void resize(){
        T* newElements = new (std::nothrow) T [m_capacity * INCREASE_STEP];
        if(!newElements){
            std::cout << "Memory problem!";
            return;
        }

        for(int i = 0; i < m_size; ++i){
            newElements[i] = m_elements[i];
        }

        deallocate();
        m_elements = newElements;
        m_capacity *= INCREASE_STEP;
    }

    bool empty(){
        return m_size == 0;
    }

public:

    Vector(){
        m_elements = new (std::nothrow) T[INITIAL_CAPACITY];
        if(!m_elements){
            std::cout << "Memory problem!";
            return;
        }
        m_size = 0;
        m_capacity = INITIAL_CAPACITY;
    }

    Vector(const Vector<T>& other){
        copy(other);
    }

    Vector<T> operator=(const Vector<T>& other){
        if(&other != this){
            deallocate();
            copy(other);
        }
        return *this;
    }

    ~Vector(){
        deallocate();
    }

    size_t getSize() const { return m_size; }

    Vector<T> operator+ (const Vector<T>& other) {
        Vector<T> result;
        if(m_size > other.m_size){
            m_size = other.m_size;
        }
        result.m_elements = new (std::nothrow) T [m_size];
        if(!result.m_elements){
            std::cout << "Memory problem!";
            return Vector<T>();
        }

        for(int i = 0; i < m_size; ++i){
            result.m_elements[i] = m_elements[i] + other.m_elements[i];
        }
        
        result.m_size = m_size;
        result.m_capacity = m_capacity;

        return result;
    }

    T& operator[](size_t index){
        assert(m_elements[index] < m_size);
        std::cout << "\nElement " << index << ": ";
        return m_elements[index];
    }

    void push(const T& newElement){
        if(m_size == m_capacity){
            resize();
        }
        m_elements[m_size] = newElement;
        m_size++;
    }

    bool pop(){
        if(empty()){
            std::cout << "\nVector is empty!";
            return false;
        }
        
        m_size--;
        return true;
    }

    void print() const{
        std::cout << std::endl << "Size: " << getSize() << "\nElements: ";
        for(int i = 0; i < m_size; ++i){
            std::cout << m_elements[i] << " ";
        }
    }
};

int main(){
    Vector<int> v1;
    Vector<int> v2;
    Vector<int> v3;

    v2.push(3);
    v2.push(55);

    v1.push(1);
    v1.push(2);
    v1.push(1);
    v1.push(2);
    v1.push(1);
    v1.push(2);
    v1.push(1);
    v1.push(2);
    v1.push(1);
    v1.push(2);
    v1.push(1);
    v1.push(2);

    v1.print();    
    v1.pop();
    v1.pop();
    v1.pop();
    
    std::cout << v1[3];
    v1.print();

    v2.print();

    v3 = v1 + v2;
    v3.print();

    return 0;
}

