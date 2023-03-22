#include <iostream>

class Interval{

private:

    int m_a;
    int m_b;

    bool isPrime(int n){
        if (n <= 1){
            return false;
        }
        for (int i = 2; i < n; i++){
            if (n % i == 0){
                return false;
            }
        }
        return true;
    }

    int reverse(int n){
        int result = 0;
        while(n != 0){
            result *= 10;
            result += n % 10;
            n /= 10;
        }
        return result;
    }

    bool isPalindrom(int n){ 
        return n == reverse(n);
    }

    int len(int n){
        int result = 0;
        while(n != 0){
            result++;
            n /= 10;
        }
        return result;
    }

    bool isUniq(int n){
        if(n < 10){
            return true;
        }
        
        int size = len(n);
        int arr[size];
        for(int i = 0; i < size; ++i){
            arr[i] = n % 10;
            n /= 10;
        }

        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                if(arr[i] == arr[j]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isPowerOfTwo(int n){
        if (n == 0){
            return false;
        }
        while (n != 1) {
            if (n % 2 != 0){
                return false;
            }
            n = n / 2;
        }
        return true;
    }

    int min(int a, int b){
        if(a < b){
            return a;
        } return b;
    }

    int max(int a, int b){
        if(a > b){
            return a;
        } return b;
    }

public:

    Interval(){
        m_a = 0;
        m_b = 0;
    }

    Interval(int a, int b){
        if(a <= b){
            m_a = a;
            m_b = b;
        }
        else {
            m_a = b;
            m_b = a;
        }
    }

    void setA(const int a){
        m_a = a;
    }

    void setB(const int b){
        m_b = b;
        if(m_a > m_b){
            int temp = m_a;
            m_a = m_b;
            m_b = temp;
        }
    }

    int getA() const { return m_a; }
    int getB() const { return m_b; }

    bool isInInterval(int c){
        return (m_a <= c && c <= m_b);
    }

    int length() const {
        return m_b - m_a;
    }

    int numberOfPrimes(){
        int result = 0;
        for(int i = m_a; i <= m_b; ++i){
            if(isPrime(i)){
                result++;
            }
        }
        return result;
    }

    int numberOfPalindromes(){
        int result = 0;
        for(int i = m_a; i <= m_b; ++i){
            if(isPalindrom(i)){
                result++;
            }
        }
        return result;
    }

    int numberOfUniqs(){
        int result = 0;
        for(int i = m_a; i <= m_b; ++i){
            if(isUniq(i)){
                result++;
            }
        }
        return result;
    }

    bool areStartAndEndPowerOfTwo(){
        return isPowerOfTwo(m_a) && isPowerOfTwo(m_b);
    }

    Interval intersect(Interval& other){
        if(m_b < other.m_a || m_a > other.m_b){
            std::cout << "The intervals dont have common points!";
            return Interval();
        }
        Interval result;
        result.setA(max(m_a, other.m_a));
        result.setB(min(m_b, other.m_b));
        return result;
    }

    Interval unionOfTwoIntervals(Interval& other){
        if(m_b < other.m_a || m_a > other.m_b){
            std::cout << "The intervals dont have common points!";
            return Interval();
        }
        Interval result;
        result.setA(min(m_a, other.m_a));
        result.setB(max(m_b, other.m_b));
        return result;
    }

    bool isSuperInterval(Interval& other){
        if(m_b < other.m_a || m_a > other.m_b){
            std::cout << "The intervals dont have common points!";
            return false;
        }
        return (m_a <= other.m_a && m_b >= other.m_b);
    }

};

int main(){
    
    Interval i;
    i.setA(2);
    i.setB(16);
    std::cout << i.getA() << " " << i.getB() << std::endl; 
    std::cout << i.length() << std::endl;
    std::cout << i.numberOfPrimes() << std::endl;
    std::cout << i.numberOfPalindromes();
    std::cout << std::endl << std::endl;
    std::cout << i.numberOfUniqs() << std::endl;
    std::cout << i.areStartAndEndPowerOfTwo() << std::endl; 

    Interval t1(3,10); // [3, 10]
    Interval t2(4,14); // [4, 14]
    Interval t3; // [0, 0]

    Interval result = t1.intersect(t2); // [4, 10]
    std::cout << result.getA() << " " << result.getB() << std::endl; 
    std::cout << t2.isSuperInterval(result) << std::endl; //true
    std::cout << result.numberOfPrimes() << std::endl;
    return 0;


}