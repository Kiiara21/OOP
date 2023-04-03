#include <iostream>
#include "time.h"

int main(){

    Time t1(1, 20), t2(1, 20), t3(1, 20), t4(1, 20), t5(1, 20);

    t3 = t1 + t2;
    t4 = t1 + 5; // (добавя 5 часа)
    t5 = 6 + t1; //(добавя 6 часа)

    std::cout << t3 << "\n";
    std::cout << t4 << "\n";
    std::cout << t5 << "\n";

    ++t3; //(добавя 1 час)
    t4++; //(добавя 1 час)

    std::cout << t4;
    return 0;
}