#include "LimitedCounter.h"
#include <iostream>

void LimitedCounter::increment(){
    if((m_counter + m_step) > m_max) throw std::invalid_argument("Invaild increment!");
    m_counter += m_step;
}
