#include "Complex.h"

/////////////////////////////////////////
// construtores
/////////////////////////////////////////

Complex::Complex(){

    this->setComplex(0,0);
}

Complex::Complex(double pr, double pi){

    this->setComplex(pr,pi);
}


/////////////////////////////////////////
// Sets
/////////////////////////////////////////
void Complex::setReal(double p){
    this->real=p;
}
void Complex::setImaginary(double p){
    this->imaginary=p;
}

/////////////////////////////////////////
// gets
/////////////////////////////////////////
double Complex::getReal(){
    return this->real;
}
double Complex::getImaginary(){
    return this->imaginary;
}

string Complex::cprint(){
    string resp;

    resp += to_string(this->getReal());
    resp += " + ";
    resp += to_string(this->getImaginary());
    resp += "i";

    return resp;
}

void Complex::setComplex(double pr, double pi){
    this->setReal(pr);
    this->setImaginary(pi);
}

void Complex::add(Complex c1){
    double r = this->getReal(), i=this->getImaginary();
    this->setComplex( r + c1.getReal(), i + c1.getImaginary());
}

void Complex::subtrac(Complex c1){
    double r = this->getReal(), i=this->getImaginary();
    this->setComplex( r - c1.getReal(), i - c1.getImaginary());
}
