#include <iostream>

template <typename T>
void input(T array[], int n){
    for(int i = 0; i < n; ++i){
        std::cin >> array[i];
    }
}

template <typename T>
bool ordered(T array[], int n){
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(array[i] > array[j]){
                return false;
            }
        }
    }

    return true;
}

int main(){

    int n;
    std::cin >> n;
    double* array = new (std::nothrow) double[n];
    if(!array){
        std::cout << "Memory problem!";
        return -1;
    }

    input(array, n);
    std::cout << ordered(array, n); 
    delete[] array;
    return 0;
}