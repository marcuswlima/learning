#include <iostream>
using std::cout;

#include "Triade.h"

Tecla gerar3M_2(Tecla);
void aumentarAlturaEmMeioTom_2(Tecla &);
void aumentarAlturaEmUmTom_2(Tecla &);

Triade::Triade(Tecla t){
    setT1(t);
}

void Triade::setT1(Tecla t){
    t1 = t;
}

Tecla Triade::getT1(){
    return t1;
}

void Triade::setT3(Tecla t){
    t3 = t;
}

Tecla Triade::getT3(){
    return t3;
}

void Triade::imprimir(){
    t1.imprimirTecla();
    t3.imprimirTecla();
}

void Triade::gerarMaior(){
    this->setT3(gerar3M_2(this->getT1()));
}

Tecla gerar3M_2(Tecla t){
    Tecla r;

    r.setOitava(t.getOitava());
    r.setNota(t.getNota());
    r.setAcidente(t.getAcidente());

    aumentarAlturaEmUmTom_2(r);
    aumentarAlturaEmUmTom_2(r);
    return r;
}

void aumentarAlturaEmUmTom_2(Tecla &t){
    aumentarAlturaEmMeioTom_2(t);
    aumentarAlturaEmMeioTom_2(t);
}


// aumentar a tecla em 1/2 tom
void aumentarAlturaEmMeioTom_2(Tecla &t){

    if (t.getOitava()!=9){

        if (t.getAcidente()==0) {// teclas bancas 
            if (t.getNota() == 3)
                t.setNota(4);
            else if (t.getNota() == 7 ){
                t.setNota(1);
                t.setOitava(t.getOitava()+1);
            }
            else
                t.setAcidente(1);

        }
        else if (t.getAcidente()==1) {// notas sustenidas
            t.setNota(t.getNota()+1);
            t.setAcidente(0);
        }
        else if (t.getAcidente()==-1){

            //cout << "*" << getNota() << "-" << getAcidente() <<"*";
            t.setAcidente(0);
        }
    }
    else
        cout << "Ultima tecla";

}
