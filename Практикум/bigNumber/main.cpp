#include "bigNumber.h"

int main(){

    BigNumber bn("129"), bn2("123");
    bn += bn2;
    std::cout << bn;
    return 0;
}