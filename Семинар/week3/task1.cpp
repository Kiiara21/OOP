#include <iostream>



class Complex{

private:

    int m_a;
    int m_b;
    // int m_i;

public:

    Complex();
    Complex(int a, int b /*, int i*/);

    void setA(int a);
    void setB(int b);
    // void setI(int i); ??

    int getA() const;
    int getB() const;
    // int getI() const; ??

    void print();
};

Complex sumComplex(Complex firstComplexNumber, Complex secondComplexNumber){
    Complex result;
    result.setA(firstComplexNumber.getA() + secondComplexNumber.getA());
    result.setB(firstComplexNumber.getB() + secondComplexNumber.getB());
    // result.setI(firstComplexNumber.getI()); ??

    return result;
}

Complex diffComplex(Complex firstComplexNumber, Complex secondComplexNumber){
    Complex result;
    result.setA(firstComplexNumber.getA() - secondComplexNumber.getA());
    result.setB(firstComplexNumber.getB() - secondComplexNumber.getB());
    // result.setI(firstComplexNumber.getI()); ??

    return result;
}

Complex multComplex(Complex firstComplexNumber, Complex secondComplexNumber){
    Complex result;
    result.setA( (firstComplexNumber.getA() * secondComplexNumber.getA() - firstComplexNumber.getB() * secondComplexNumber.getB()) 
                +(firstComplexNumber.getB() * secondComplexNumber.getA() + firstComplexNumber.getA() * secondComplexNumber.getB()) );
    
    // fix it
    // result.setB(firstComplexNumber.getB() + secondComplexNumber.getB());
    // result.setI(firstComplexNumber.getI()); ??

    return result;
}

int main(){


    return 0;
}