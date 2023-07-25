#include <iostream>
#include "Mathematics.h"
using namespace std;

class Rational{
public:
//--Construtores
    Rational(int, int);
//--Sets
    void setNumerator(int);
    void setDenominator(int);
//--Gets
    int getNumerator();
    int getDenominator();
//----------------------
    string print();    
    Rational add(Rational,Rational);
    Rational subtrac(Rational,Rational);
    Rational multiply(Rational,Rational);
    Rational divide(Rational,Rational);
private:
    int numerator;
    int denomitator;
//----------------------
    void setRational(int, int);
	void negate();
    void reduce();
	void invert();
};
