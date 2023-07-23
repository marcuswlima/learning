#include <iostream>
using namespace std;

class Complex{
public:
//--Construtores
    Complex();
    Complex(double, double);
//--Sets
    void setReal(double);
    void setImaginary(double);
//--Gets
    double getReal();
    double getImaginary();
//----------------------
    string cprint();    
    void add(Complex);
    void subtrac(Complex);
private:
    double real;
    double imaginary;
//----------------------
    void setComplex(double, double);
};