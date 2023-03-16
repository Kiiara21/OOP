#include <iostream>

class Complex {

private:
    int m_real = 0;
    int m_img = 0;

public:

    void setReal(int real){
        m_real = real;
    }
    void setImg(int img){
        m_img = img;
    }

    int getReal() const { return m_real; }
    int getImg() const { return m_img; }

    void print() const {
        if (m_img < 0)
            if (m_img == -1){
                std::cout << "The complex number is: " << m_real << "-i\n";
            }
            else
                std::cout << "The complex number is: " << m_real << m_img << "i\n";
        else if (m_img == 1){
            std::cout << "The complex number is: " << m_real << " + i\n";
        }
        else
            std::cout << "The complex number is: " << m_real << " + " << m_img << "i";
    }

};

Complex sum(Complex& first, Complex &second){
    Complex result;
    result.setReal(first.getReal() + second.getReal());
    result.setImg(first.getImg() + second.getImg());
    return result;
}

Complex sub(Complex& first, Complex &second){
    Complex result;
    result.setReal(first.getReal() - second.getReal());
    result.setImg(first.getImg() - second.getImg());
    return result;
}

Complex mult(Complex& first, Complex &second){
    int resultReal = first.getReal() * second.getReal() - first.getImg() * second.getImg();
    int resultImg = first.getImg() * second.getReal() + first.getReal() * second.getImg();
    Complex result;
    result.setReal(resultReal);
    result.setImg(resultImg);
    return result;
}

int main(){
    Complex c1, c2, c;

    c1.setReal(2);
    c1.setImg(1);

    c2.setReal(3);
    c2.setImg(2);

    c = mult(c1, c2);

    c.print();

    return 0;
}