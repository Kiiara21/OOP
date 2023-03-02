#include <iostream>

template <typename T>
T id(T num) {
    return num;
}

template <typename T>
T pow2(T num) {
    return num * num;
}

template <typename T>
T sum(T firstNum, T secondNum) {
    return firstNum + secondNum;
}

template <typename T>
T product(T firstNum, T secondNum) {
    return firstNum * secondNum;
}

template <typename T>
T accumulate(int from, int to, T (*term) (T), T (*op) (T, T), T startingValue){
    T result = startingValue;

    for(int i = from; i <= to; ++i){
        result = op (result, term(i));
    }

    return result;
}

int main(){
    std::cout << accumulate(1, 4, id, sum, 0) << std::endl; // 10
    std::cout << accumulate(1, 4, pow2, sum, 0) << std::endl; // 30
    std::cout << accumulate(1, 5, id, product, 1) << std::endl; // 120
    return 0;
}