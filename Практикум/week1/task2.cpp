#include <iostream>

const int MAX = 100;

void bubbleSort(int* array, int size){
    for(int i = 0; i < size; ++i){
        for(int j = i + 1; j < size; ++j){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void insertInSorted(int array[], int size, int x){
    int i = size;
    while (i > 0 && array[i-1] > x){
        array[i] = array[i-1];
        --i;
    }
    array[i] = x;
}

void insertionSort(int *array, int size){
    for (int i = 1; i < size; ++i){
        insertInSorted(array, i, array[i]);
    }
}

void sort(int* array, int size, void (*sortFunction) (int*, int)){
    sortFunction(array, size);
}

int main(){

    int array[MAX];

    int size;
    std::cin >> size;

    for(int i = 0; i < size; ++i){
        std::cin >> array[i];
    }

    sort(array, size, bubbleSort);

    for(int i = 0; i < size; ++i){
        std::cout << array[i];
    }
    return 0;
}