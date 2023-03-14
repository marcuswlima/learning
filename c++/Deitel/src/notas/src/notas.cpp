#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "Tecla.h"
#include "/home/marcus/Developer/github/learning/c++/Deitel/src/lib/marcusLib.h"

/////////////////////////////////////////
// Declarações
/////////////////////////////////////////
void imprimir(Tecla);
Tecla gerar3m(Tecla);
Tecla gerar3M(Tecla);
void aumentarAlturaEmUmTom(Tecla &);
void aumentarAlturaEmMeioTom(Tecla &);
void gerarTriadeMaior(Tecla , Tecla &, Tecla &);
void gerarTriadeMenor(Tecla , Tecla &, Tecla &);
void gerarTriadeDiminuta(Tecla , Tecla &, Tecla &);
void gerarTriadeAumentada(Tecla , Tecla &, Tecla &);
void imprimirTriade(Tecla, Tecla, Tecla);

/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main ( )
{
    srand( time(0) );

    Titulo("Notas");

    Tecla t1(3,3,-1), t3, t5;

    gerarTriadeMaior(t1, t3, t5);
    imprimirTriade(t1, t3, t5);

    gerarTriadeMenor(t1, t3, t5);
    imprimirTriade(t1, t3, t5);

    gerarTriadeDiminuta(t1, t3, t5);
    imprimirTriade(t1, t3, t5);

    gerarTriadeAumentada(t1, t3, t5);
    imprimirTriade(t1, t3, t5);

    return 0; //indica o fim do programa
}

void imprimirTriade(Tecla t1, Tecla t3, Tecla t5){
    t1.imprimirTecla();
    t3.imprimirTecla();
    t5.imprimirTecla();
    cout<<"\n";
}

void gerarTriadeMaior(Tecla t1, Tecla &t3, Tecla &t5){
    t3=gerar3M(t1);
    t5=gerar3m(t3);
}

void gerarTriadeMenor(Tecla t1, Tecla &t3, Tecla &t5){
    t3=gerar3m(t1);
    t5=gerar3M(t3);
}

void gerarTriadeDiminuta(Tecla t1, Tecla &t3, Tecla &t5){
    t3=gerar3m(t1);
    t5=gerar3m(t3);
}

void gerarTriadeAumentada(Tecla t1, Tecla &t3, Tecla &t5){
    t3=gerar3M(t1);
    t5=gerar3M(t3);
}

Tecla gerar3m(Tecla t){
    Tecla r;

    r.setOitava(t.getOitava());
    r.setNota(t.getNota());
    r.setAcidente(t.getAcidente());

    aumentarAlturaEmUmTom(r);
    aumentarAlturaEmMeioTom(r);
    return r;
}

Tecla gerar3M(Tecla t){
    Tecla r;

    r.setOitava(t.getOitava());
    r.setNota(t.getNota());
    r.setAcidente(t.getAcidente());

    aumentarAlturaEmUmTom(r);
    aumentarAlturaEmUmTom(r);
    return r;
}

void aumentarAlturaEmUmTom(Tecla &t){
    aumentarAlturaEmMeioTom(t);
    aumentarAlturaEmMeioTom(t);
}

// aumentar a tecla em 1/2 tom
void aumentarAlturaEmMeioTom(Tecla &t){

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

