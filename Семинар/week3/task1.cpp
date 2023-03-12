#include <iostream>

class Complex {

private:
    int m_real;
    int m_img;

public:
    Complex() : m_real(0), m_img(0) {}

    Complex(int real, int img) : m_real(real), m_img(img) {}

    int getReal() const { return m_real; }
    int getImg() const { return m_img; }

    void print() const {
        if (m_img < 0)
            if (m_img == -1)
            {
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

    Complex sum(Complex &second){
        Complex result(m_real + second.m_real, m_img + second.m_img);
        return result;
    }

    Complex sub(Complex &second){
        Complex result(m_real - second.m_real, m_img - second.m_img);
        return result;
    }

    Complex mult(Complex &second){
        int resultReal = m_real * second.m_real - m_img * second.m_img;
        int resultImg = m_img * second.m_real + m_real * second.m_img;
        Complex result(resultReal, resultImg);
        return result;
    }
};
