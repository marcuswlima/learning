#include "Rational.h"

/////////////////////////////////////////
// prototipations
/////////////////////////////////////////
int f_mmc(int n1, int n2);

/////////////////////////////////////////
// construtores
/////////////////////////////////////////

Rational::Rational(int pn, int pd){
    this->setRational(pn,pd);
}

/////////////////////////////////////////
// Sets
/////////////////////////////////////////
void Rational::setNumerator(int p){
    this->numerator=p;
}
void Rational::setDenominator(int p){
    if (p==0)
        throw invalid_argument("Denominador não pode ser zero");
    this->denomitator=p;
}

/////////////////////////////////////////
// gets
/////////////////////////////////////////
int Rational::getNumerator(){
    return this->numerator;
}
int Rational::getDenominator(){
    return this->denomitator;
}

/////////////////////////////////////////
// public
/////////////////////////////////////////
void Rational::print(){
    string resp;

    resp += to_string(this->getNumerator());
    resp += "/";
    resp += to_string(this->getDenominator());

	cout << resp << endl;

}

void Rational::printd(){
	int n = this->getNumerator(), d = this->getDenominator();
	double resposta=(double)n/d;

	cout << fixed << setprecision( 2 );
	cout << resposta << endl;
}

Rational Rational::add(Rational r1,Rational r2){

    Rational resp(1,1);
    int n1 = r1.getNumerator(),
        d1 = r1.getDenominator(),
        n2 = r2.getNumerator(),
        d2 = r2.getDenominator()
		;
    
    if (d1 == d2){
        resp.setRational(n1+n2,d1);
    }else{
        int mmc=f_mmc(d1,d2);

		n1 = mmc/d1*n1;
		n2 = mmc/d2*n2;
        resp.setRational(n1+n2,mmc);
    }

	resp.reduce();

    return resp;
}//add

Rational Rational::subtrac(Rational r1, Rational r2){
	r2.negate();
	return this->add(r1,r2);
}

Rational Rational::multiply(Rational r1, Rational r2){
    Rational resp(1,1);
	resp.setRational(r1.getNumerator()*r2.getNumerator(),r1.getDenominator()*r2.getDenominator());
	resp.reduce();
    return resp;
}

Rational Rational::divide(Rational r1, Rational r2){
	r2.invert();
	return this->multiply(r1,r2);
}

/////////////////////////////////////////
// privates
/////////////////////////////////////////
void Rational::setRational(int pn, int pd){
    this->setNumerator(pn);
    this->setDenominator(pd);
}

void Rational::negate(){
	int n=this->getNumerator();
	this->setNumerator(n*(-1));
}

void Rational::invert(){
	int n = this->getNumerator(), d = this->getDenominator();
	this->setRational(d,n);
}

void Rational::reduce(){
	int n = this->getNumerator(), d = this->getDenominator();
	int reduce=0;
	int mdc=CalcMdc(n,d);

	if (n>d && GetRemainder(n,d)==0){
		reduce=d;
	}
	else if (mdc>0){
		reduce=mdc;
	}else{
		reduce=1;
	}
	this->setRational(n/reduce, d/reduce);
}

/////////////////////////////////////////
// internals
/////////////////////////////////////////
int f_maior(int n1, int n2){
    return (n1>n2 ? n1 : n2);
}

int f_mmc(int n1, int n2){
    int maior=f_maior(n1,n2);

    maior++;
    while( HasRemainder(maior,n1) || HasRemainder(maior,n2) ){
       maior++;
    }
    return maior;
}
