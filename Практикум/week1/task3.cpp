#include <iostream>

const int MAX = 100;

template <typename T>
struct MyArray{
    T* elements;
    int size;
};

template <typename T>
void pushBack(int newElement, MyArray<T>& array){
    std::cout << "Push back the element " << newElement << std::endl;
    array.elements[array.size++] = newElement;
}

template <typename T>
void popBack(MyArray<T>& array){
    std::cout << "Pop the last element... " << std::endl;
    array.size--;
}

template <typename T>
T at(int index, MyArray<T>& array){
    std::cout << "Element at index " << index << " is: ";
    if(array.size < index || index < 0){
        std::cout << "Invaild index!";
        return -1;
    }
    return array.elements[index];
}

template <typename T>
void empty(MyArray<T>& array){
    if(array.size == 0){
        std::cout << "Array is empty.\n";
    }
    else std::cout << "Array is not empty.\n";
}

template <typename T>
void print(MyArray<T>& array){
    for(int i = 0; i < array.size; ++i){
        std::cout << array.elements[i] << " ";
    }

    std::cout << std::endl;
}

int main(){

    MyArray<int> array;
    array.size = 3;
    array.elements = new int[100];

    for(int i = 0; i < array.size; ++i){
        std::cin >> array.elements[i];
    }

    pushBack(4, array);
    print(array); 
    empty(array);
    std::cout << at(2, array) << std::endl;
    popBack(array);
    print(array); 

    delete[] array.elements;
    return 0;
}