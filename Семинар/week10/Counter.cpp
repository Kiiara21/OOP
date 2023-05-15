#include "Counter.h"

Counter::Counter(){
    m_counter = 0;
    m_step = 1;
}

Counter::Counter(int initial){
    m_counter = initial;
    m_step = 1;
}

Counter::Counter(int initial, unsigned int step){
    m_counter = initial;
    m_step = step;
}

void Counter::increment(){
    m_counter += m_step;
}
