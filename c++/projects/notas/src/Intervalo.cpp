#include <iostream>
#include <cmath>
#include "Intervalo.h"

using namespace std;

int tipoIntervalor(Tecla, Tecla);


void aumentarAlturaEmUmTom(Tecla &);
void aumentarAlturaEmMeioTom(Tecla &);

/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Intervalo::Intervalo()
{
    Tecla t1;
    Tecla t2;

    setT1(t1);
    setT2(t2);
}

Intervalo::Intervalo(Tecla t1)
{
    setT1(t1);
}


Intervalo::Intervalo(Tecla t1, Tecla t2)
{
    setT1(t1);
    setT2(t2);
}

Intervalo::Intervalo(int o1, int n1, int a1, int o2, int n2, int a2)
{
    Tecla t1(o1,n1,a1);
    Tecla t2(o2,n2,a2);

    setT1(t1);
    setT2(t2);
}

/////////////////////////////////////////
// Acesso
/////////////////////////////////////////
void Intervalo::setT1(Tecla t){
    t1 = t;
}

void Intervalo::setT2(Tecla t){
    t2 = t;
}

Tecla Intervalo::getT1(){
    return t1;
}

Tecla Intervalo::getT2(){
    return t2;
}

/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////

void Intervalo::aleatorio(){
    //getT1().aleatorio(); // Primeira Nota
    this->getT1().setTecla(4,5,0);
    //cout << getT1().getNota();
    
/*
    int qdtSemiTons = gerarInteiro(3,4);

    switch (qdtSemiTons)
    {
        case 3:this->i3m(getT1());break;
        case 4:this->i3M(getT1());break;
        default:break;
    }
*/    
}

void Intervalo::imprimirIntervalo(){
    this->getT1().imprimirTecla();
    this->getT2().imprimirTecla();

    cout << "\n";

}


/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////


Tecla notaMenor(Tecla t1, Tecla t2){
    if (t1.getOitava() < t2.getOitava())
        return t1;
    else if (t1.getOitava() > t2.getOitava())
        return t2;
    else //mesma oitava
        if (t1.getNota() < t2.getNota())
            return t1;
        if (t1.getNota() > t2.getNota())
            return t2;
        else // mesma nota
            if (t1.getAcidente() < t2.getAcidente())
                return t1;
            else if (t1.getAcidente() > t2.getAcidente())
                return t2;
            else    
                return t1; //teclas identicas
}

bool notasIguais(Tecla t1, Tecla t2){
    return t1.getOitava()   == t2.getOitava()  &&
           t1.getNota()     == t2.getNota()    &&
           t1.getAcidente() == t2.getAcidente();
}

int tipoIntervalor(Tecla t1, Tecla t2){
    int quantNotas = abs( t1.getNota() - t2.getNota() ), quantSemitons;
    
    return quantNotas+1;
}

