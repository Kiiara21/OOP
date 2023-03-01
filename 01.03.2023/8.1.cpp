#include <iostream>

template <typename T>
void input(T array, int n){
    for(int i = 0; i < n; ++i){
        std::cin >> array[i];
    }
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
    delete[] array;
    return 0;
}