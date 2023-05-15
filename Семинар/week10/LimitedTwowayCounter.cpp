#include "LimitedTwowayCounter.h"
#include <iostream>

void LimitedTwowayCounter::decrement(){
    if((LimitedCounter::m_counter - LimitedCounter::m_step) < m_min) throw std::invalid_argument("Invalid decrement!");
    LimitedCounter::m_counter -= LimitedCounter::m_step;
}

void LimitedTwowayCounter::increment(){
    try {
        LimitedCounter::increment();
    } 
    catch (const std::invalid_argument &exception){
        std::cerr << exception.what();
    }
} 