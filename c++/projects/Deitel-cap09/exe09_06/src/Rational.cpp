#include "Rational.h"

/////////////////////////////////////////
// prototipations
/////////////////////////////////////////
int f_mmc(int n1, int n2);

/////////////////////////////////////////
// construtores
/////////////////////////////////////////

Rational::Rational(int pr, int pi){
    this->setRational(pr,pi);
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

string Rational::print(){
    string resp;

    resp += to_string(this->getNumerator());
    resp += " / ";
    resp += to_string(this->getDenominator());

    return resp;
}

void Rational::setRational(int pn, int pd){
    this->setNumerator(pn);
    this->setDenominator(pd);
}

Rational Rational::add(Rational r1,Rational r2){

    Rational resp(1,1);
    int n1 = r1.getNumerator(),
        d1 = r1.getDenominator(),
        n2 = r2.getNumerator(),
        d2 = r2.getDenominator();
    
    if (d1 == d2){
        resp.setRational(n1+n2,d1);
    }else{
        int mmc=f_mmc(d1,d2);
        cout << "mmc -> "<< mmc << endl;
        resp.setRational(mmc,mmc);
    }

    return resp;
}//add

int GetRemainder(int divisor, int dividendo){
    return divisor % dividendo;
}

bool HasRemainder(int divisor, int dividendo){
    return GetRemainder(divisor,dividendo)>0;
}

int f_maior(int n1, int n2){
    return (n1>n2 ? n1 : n2);
}

int f_mmc(int n1, int n2){
    int maior=f_maior(n1,n2);

    maior++;
    while( HasRemainder(maior,n1) && HasRemainder(maior,n2) ){
       maior++;
    }
    return maior;
}
