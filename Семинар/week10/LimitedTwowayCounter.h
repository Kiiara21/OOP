#include "LimitedCounter.h"
#include "TwowayCounter.h"

class LimitedTwowayCounter : public LimitedCounter, public TwowayCounter{

private:
    int m_min;

public:

    LimitedTwowayCounter(int min, int max) : LimitedCounter(max) {
        m_min = min;
    }

    LimitedTwowayCounter(int min, int max, int initial) : LimitedCounter(max, initial){
        m_min = min;
    }

    LimitedTwowayCounter(int min, int max, int initial, unsigned int step) : LimitedCounter(max, initial, step){ 
        m_min = min;
    }

    int getTotal() { return LimitedCounter::getTotal(); }
    unsigned int getStep() const { return LimitedCounter::getStep(); }
    
    int getMin() { return m_min; }
    
    void decrement() override;
    void increment() override;
};  