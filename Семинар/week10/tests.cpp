#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Counter.h"
#include "TwowayCounter.h"
#include "LimitedCounter.h"
#include "Semaphore.h"

TEST_SUITE ("Counter tests"){
    TEST_CASE("Init counter with 0, and step with 1"){
        Counter counter;
        CHECK_EQ(counter.getTotal(), 0);
        CHECK_EQ(counter.getStep(), 1);    
    }

    TEST_CASE("Increment counter"){
        Counter counter;
        CHECK_EQ(counter.getTotal(), 0);
        CHECK_EQ(counter.getStep(), 1);
        counter.increment();
        CHECK_EQ(counter.getTotal(), 1);
        CHECK_EQ(counter.getStep(), 1);
    }

    TEST_CASE("Init counter with initial value"){
        Counter counter(2);
        CHECK_EQ(counter.getTotal(), 2);
        CHECK_EQ(counter.getStep(), 1);
    }

    TEST_CASE("Init counter with 100 and step with 100"){
        Counter counter(100, 100);
        CHECK_EQ(counter.getTotal(), 100);
        CHECK_EQ(counter.getStep(), 100);
    }
}

TEST_SUITE("Twowaycounter tests"){
    TEST_CASE("Init twoway counter with 0 and step 0"){
        TwowayCounter twowayCounter;
        CHECK_EQ(twowayCounter.getTotal(), 0);
        CHECK_EQ(twowayCounter.getStep(), 1);
    }

    TEST_CASE("Increment twoway counter"){
        TwowayCounter counter;
        CHECK_EQ(counter.getTotal(), 0);
        CHECK_EQ(counter.getStep(), 1);
        counter.increment();
        CHECK_EQ(counter.getTotal(), 1);
        CHECK_EQ(counter.getStep(), 1);
    }

    TEST_CASE("Init twoway counter with initial value"){
        TwowayCounter counter(2);
        CHECK_EQ(counter.getTotal(), 2);
        CHECK_EQ(counter.getStep(), 1);
    }

    TEST_CASE("Init twoway counter with 100 and step with 100"){
        TwowayCounter counter(100, 100);
        CHECK_EQ(counter.getTotal(), 100);
        CHECK_EQ(counter.getStep(), 100);
    }

    TEST_CASE("Decrement twoway counter"){
        TwowayCounter counter(100, 100);
        CHECK_EQ(counter.getTotal(), 100);
        CHECK_EQ(counter.getStep(), 100);
        counter.decrement();
        CHECK_EQ(counter.getTotal(), 0);
        CHECK_EQ(counter.getStep(), 100);
    }
}

TEST_SUITE ("Limited counter tests") {
    TEST_CASE("init with max"){
        LimitedCounter limitedConter(12);
        CHECK_EQ(limitedConter.getMax(), 12);
        CHECK_EQ(limitedConter.getTotal(), 0);
        CHECK_EQ(limitedConter.getStep(), 1);
    }

    TEST_CASE("init with max and initial"){
        LimitedCounter limitedConter(12, 12);
        CHECK_EQ(limitedConter.getMax(), 12);
        CHECK_EQ(limitedConter.getTotal(), 12);
        CHECK_EQ(limitedConter.getStep(), 1);
    }

    TEST_CASE("init with max, initial and step"){
        LimitedCounter limitedConter(12, 12, 12);
        CHECK_EQ(limitedConter.getMax(), 12);
        CHECK_EQ(limitedConter.getTotal(), 12);
        CHECK_EQ(limitedConter.getStep(), 12);
    }

    TEST_CASE("inicrement limited counter"){
        LimitedCounter limitedConter(12);
        CHECK_EQ(limitedConter.getMax(), 12);
        CHECK_EQ(limitedConter.getTotal(), 0);
        CHECK_EQ(limitedConter.getStep(), 1);
        limitedConter.increment();
        CHECK_EQ(limitedConter.getTotal(), 1);  
    }
  
}

TEST_SUITE("Limited twoway counter tests"){
    TEST_CASE("Init counter with min and max"){
        LimitedTwowayCounter counter(0, 100);
        CHECK_EQ(counter.getMin(), 0);
        CHECK_EQ(counter.getMax(), 100);
        CHECK_EQ(counter.getTotal(), 0);
        CHECK_EQ(counter.getStep(), 1);
    }

    TEST_CASE("Init counter with min, max and initial"){
        LimitedTwowayCounter counter(0, 100, 14);
        CHECK_EQ(counter.getMin(), 0);
        CHECK_EQ(counter.getMax(), 100);
        CHECK_EQ(counter.getTotal(), 14);
        CHECK_EQ(counter.getStep(), 1);
    }

    TEST_CASE("Init counter with min, max, initial and step"){
        LimitedTwowayCounter counter(0, 100, 16, 8);
        CHECK_EQ(counter.getMin(), 0);
        CHECK_EQ(counter.getMax(), 100);
        CHECK_EQ(counter.getTotal(), 16);
        CHECK_EQ(counter.getStep(), 8);
    }

    TEST_CASE("increment limited twoway counter"){
        LimitedTwowayCounter counter(0, 100);
        CHECK_EQ(counter.getMin(), 0);
        CHECK_EQ(counter.getMax(), 100);
        CHECK_EQ(counter.getTotal(), 0);
        CHECK_EQ(counter.getStep(), 1);
        counter.increment();
        CHECK_EQ(counter.getTotal(), 1);
    }

    TEST_CASE("increment with step=3 limited twoway counter"){
        LimitedTwowayCounter counter(0, 100, 0, 3);
        CHECK_EQ(counter.getMin(), 0);
        CHECK_EQ(counter.getMax(), 100);
        CHECK_EQ(counter.getTotal(), 0);
        CHECK_EQ(counter.getStep(), 3);
        counter.increment();
        CHECK_EQ(counter.getTotal(), 3);
    }

    TEST_CASE("Decrement limited twoway counter"){
        LimitedTwowayCounter counter(0, 100);
        CHECK_EQ(counter.getMin(), 0);
        CHECK_EQ(counter.getMax(), 100);
        CHECK_EQ(counter.getTotal(), 0);
        CHECK_EQ(counter.getStep(), 1);
        counter.increment();
        counter.decrement();
        CHECK_EQ(counter.getTotal(), 0);
    }

    TEST_CASE("Decrement with step=3 limited twoway counter"){
        LimitedTwowayCounter counter(0, 100, 1, 3);
        CHECK_EQ(counter.getMin(), 0);
        CHECK_EQ(counter.getMax(), 100);
        CHECK_EQ(counter.getTotal(), 1);
        CHECK_EQ(counter.getStep(), 3);
        counter.increment();
        counter.decrement();
        CHECK_EQ(counter.getTotal(), 1);
    }
}

TEST_SUITE("Semaphore tests"){
    TEST_CASE("init semaphore"){
        Semaphore sem;
        CHECK_EQ(sem.getTotal(), 0);
        CHECK_EQ(sem.getMin(), 0);
        CHECK_EQ(sem.getMax(), 1);
        CHECK_EQ(sem.getStep(), 1);
    }

    TEST_CASE("init semaphore woth bool value"){
        Semaphore sem(false);
        CHECK_EQ(sem.getTotal(), 0);
        CHECK_EQ(sem.getMin(), 0);
        CHECK_EQ(sem.getMax(), 1);
        CHECK_EQ(sem.getStep(), 1);
    }

    TEST_CASE("check if semaphore is available"){
        Semaphore sem1(true), sem2(false);
        CHECK_FALSE(!sem1.isAvailable());
        CHECK_FALSE(sem2.isAvailable());
    }

    TEST_CASE("Semaphore wait"){
        Semaphore sem(true);
        sem.wait();
        CHECK_EQ(sem.getTotal(), 0);
    }

    TEST_CASE("Semaphore signal"){
        Semaphore sem;
        sem.signal();
        CHECK_EQ(sem.getTotal(), 1);
    }

}