#pragma once
#include "LimitedTwowayCounter.h"

class Semaphore : public LimitedTwowayCounter{

private:

public:

    Semaphore() : LimitedTwowayCounter(0, 1, 0, 1) {}
    Semaphore(bool m_value) : LimitedTwowayCounter(0, 1, int(m_value), 1) {}

    bool isAvailable() { return getTotal() > 0; }
    void wait();
    void signal();

};