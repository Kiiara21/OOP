#pragma once
#include "Counter.h"

class LimitedCounter : public Counter{

protected:

    int m_max;

public:

    LimitedCounter(int max) : Counter(), m_max(max) {}
    LimitedCounter(int max, int initial) : Counter(initial), m_max(max) {}
    LimitedCounter(int max, int init, unsigned int step) : Counter(init, step), m_max(max) {}

    int getMax() { return m_max; }
    
    void increment() override;
};