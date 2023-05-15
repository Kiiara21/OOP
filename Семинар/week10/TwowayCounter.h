#pragma once
#include "Counter.h"

class TwowayCounter : public Counter{

public:

    TwowayCounter() : Counter() {}
    TwowayCounter(int initial) : Counter(initial) {}
    TwowayCounter(int initial, unsigned int step) : Counter(initial, step) {}

    virtual void decrement();
};