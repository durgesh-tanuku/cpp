#include <iostream>

class Complex
{
private:
    int real, imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    void print() 
    {
        std::cout << real << "+" << imag << "i" << std::endl;
    }

    const Complex operator + (const Complex& c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

int main()
{
    Complex c1(2,5);
    c1.print();
    Complex c2(4,9);
    c2.print();
    Complex c3 = c1 + c2;
    c3.print();
    return 0;    
}