#include "list.h"
#include <iostream>

int main(){

    List<int> l;
    l.add(1);
    l.add(2);
    l.add(1);
    l.add(1);
    std::cout << l[1] << std::endl;
    l.remove(1);
    std::cout << l;
    return 0;
}