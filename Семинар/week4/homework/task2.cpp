#include <iostream>
#include <cassert>

const size_t MAX = 128;

class Sumator{

private:
    int m_array[MAX];
    int m_arraySize;

    int pow(int x, int k){
        int result = 1;
        while(k != 0){
            result *= x;
            k--;
        }
        return result;
    }

public:

    Sumator() : m_arraySize(10) {}
    Sumator(const int size) : m_arraySize(size) {}
    
    void add(const int elementToAdd){
        if(m_arraySize < MAX){
            m_array[m_arraySize] = elementToAdd;
            m_arraySize++;
        }
        else std::cout << "Array is full!";
    }

    int getSum(){
        int sum = 0;
        for(int i = 0; i < m_arraySize; ++i){
            sum += pow(m_array[i], i);
        }
        return sum;
    }

    void removeLast(){
        if(m_arraySize > 0){
            m_arraySize--;
        } else std::cout << "Array is empty!";
    }

    void changeAt(const int toChange, const int newElement){
        for(int i = 0; i < m_arraySize; ++i){
            if(m_array[i] == toChange){
                m_array[i] = newElement;
                return;
            }
        }
        std::cout << "There is no have such element!";
        return;
    }

    void print() const {
        for(int i = 0; i < m_arraySize; ++i){
            std::cout << m_array[i] << " ";
        }
    }
};

int main(){
    Sumator sumator(0);

    sumator.add(4); sumator.add(2);

    std::cout << sumator.getSum() << std::endl; // - 3

    sumator.add(5);
    sumator.print();

    std::cout << sumator.getSum() << std::endl; // - 28

    sumator.removeLast();

    std::cout << sumator.getSum() << std::endl; // - 3

    sumator.print();

    std::cout << std::endl;

    sumator.changeAt(2, 1);

    // std::cout << std::endl;

    sumator.print();

    std::cout << std::endl << sumator.getSum() << std::endl; // - 6
    return 0;
}