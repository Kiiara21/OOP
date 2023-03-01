#include <iostream>

double f(double param){
    return param;
}

double f1(double param){
    return param;
}

double f2(double param){
    return param - 1; 
}

double f3(double param){
    return param;
}

int main(){
    double (*(functions[4]))(double param) = {f, f1, f2, f3};
    functions[0] = f2;
    std::cout << functions[0](3.6);
    return 0;
}