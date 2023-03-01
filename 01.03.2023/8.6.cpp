#include <iostream>

template <typename T>
T maxArray(T (*(array[])) (T), int n, T x){
    T max = array[0](x);
    for(int i = 1; i < n; ++i){
        if(array[i](x) > max){
            max = array[i](x);
        }
    }
    return max;
}

template <typename T>
T f1(T x){
    return x;
}

template <typename T>
T f2(T x){
    return x + 1;
}

template <typename T>
T f3(T x){
    return x + 2;
}

int main(){
    int n = 3;
    double d = 3;
    int i = 4;
    double (*(arrayOfDouble[n])) (double) = {f1, f2, f3};
    int (*(arrayOfInt[n])) (int) = {f1, f2, f3};

    std::cout << maxArray(arrayOfDouble, n, d) << std::endl;
    std::cout << maxArray(arrayOfInt, n, i) << std::endl;

    return 0;
}