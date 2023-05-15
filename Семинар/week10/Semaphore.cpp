#include "Semaphore.h"
#include <iostream>

void Semaphore::wait() { 
    try {
        decrement(); 
    }
    catch (const std::invalid_argument &exception){
        std::cerr << exception.what();    
    }
}

void Semaphore::signal() { 
    try {
        increment(); 
    }
    catch (const std::invalid_argument &exception){
        std::cerr << exception.what();    
    }
}   