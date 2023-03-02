#include <iostream>

constexpr size_t ARR_SIZE = 5;

void multBy2(int& num) {
    num *= 2;
}

bool divBy4(int num) {
    return num % 4 == 0;
}

void map(int array[], int size, void (*op) (int&)){
    for(int i = 0; i < size; ++i){
        op(array[i]);
    }

    for(int i = 0; i < size; ++i){
        std::cout << array[i] << " ";
    }
}

void filter(int array[], int size, bool (*op) (int)){
    for(int i = 0; i < size; ++i){
        if(!op(array[i])){
            for(int j = i; j < size - 1; ++j){
                array[j] = array[j + 1];
            }
            i--;
            size--;
        }
    }

    for(int i = 0; i < size; ++i){
        std::cout << array[i] << " ";
    }
}

// Реализирайте функция filter, която приема масив от произволен тип и функция от по-висок ред, която ще е предикат.
// filter ще премахва всеки елемент от масива, който не удовлетворява предиката.

int main() {

    int arr[ARR_SIZE] = { 1, 2, 3, 4, 5 };

    map(arr, ARR_SIZE, multBy2); // 2 4 6 8 10
    filter(arr, ARR_SIZE, divBy4); // 4 8

    return 0;
}
