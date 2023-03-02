#include <iostream>

int max2(int firstNum, int secondNum) {
    return std::max(firstNum, secondNum);
}

bool anyEven(bool res, int num) {
    return res || num % 2 == 0;
}


template <typename T, typename V>
V fold(T array[], size_t size, V (*op) (V, T), V startingValue){
    V result = op(startingValue, array[0]);

    for(int i = 1; i < size; ++i){
        result = op(result, array[i]); 
    }

    return result;
}

int main() {
    constexpr std::size_t ARR_SIZE = 5;
    int arr[ARR_SIZE] = { 1, 2, 8, 4, 5 };

    std::cout << fold(arr, ARR_SIZE, max2, arr[0]) << std::endl; // 8
    std::cout << std::boolalpha << fold(arr, ARR_SIZE, anyEven, false) << std::endl; // true

    return 0;
}
