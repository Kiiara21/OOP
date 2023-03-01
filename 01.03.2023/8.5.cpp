#include <iostream>

template <typename T>
T max(T a, T b){
    return (a > b) ? a : b;
}

template <typename T>
T fmax(T (*f)(T), T (*g)(T), T x){
    T fx = f(x);
    T gx = g(x);

    return max(fx, gx);
}

template <typename T>
T f(T x){
    return x * 2;
}

template <typename T>
T g(T x){
    return x * 3;
}

int main(){
    // int a = 6;
    std::cout << fmax(f, g, 3) << std::endl;
    std::cout << fmax(f, g, 3.4) << std::endl; 
    std::cout << fmax(f, g, 'b') << std::endl;
    // std::cout << fmax(f, g, *a) << std::endl; // !
    
    return 0;
}