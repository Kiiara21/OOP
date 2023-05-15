#pragma once

class Counter {

protected:

    int m_counter;
    unsigned int m_step;

public:

    Counter();
    Counter(int initial);
    Counter(int initial, unsigned int step);

    int getTotal() { return m_counter; }
    unsigned int getStep() const { return m_step; }

    virtual void increment();
};
