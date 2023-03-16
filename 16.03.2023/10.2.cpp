#include <iostream>

class NumbersSummator{

private:
    int m_sum;
    int strat = 0;
    int m_numberOfChange = 0;
public:
    NumbersSummator(int sum) : m_sum(sum) {
        strat = m_sum;
    }

    int sum() const { return m_sum; }

    void add(int toAdd){
        m_sum += toAdd;
        m_numberOfChange++;
    }

    void sub(int toSub){
        m_sum -= toSub;
        m_numberOfChange++;
    }

    int num() const { return m_numberOfChange; }

    double average() const { return (m_sum - strat) / m_numberOfChange; }
};

int main(){
    NumbersSummator seq1 (10) ;
    seq1.add (10);
    seq1.add (5);
    seq1.sub (15);
    std::cout << seq1.sum() << std::endl; //−>10 (10+10+5−15)
    std::cout << seq1.average() << std::endl; //−>0 (10+5−15)/3
    return 0;
}