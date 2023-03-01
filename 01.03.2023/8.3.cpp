#include <iostream>

template <typename T>
void input(T array[], int n){
    for(int i = 0; i < n; ++i){
        std::cin >> array[i];
    }
}

template <typename T>
bool member(T array[], int n, T x){
    for(int i = 0; i < n; ++i){
        if(array[i] == x){
            return true;
        }
    }

    return false;
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
    double x = 5.0;
    std::cout << member(array, n, x);
    delete[] array;
    return 0;
}