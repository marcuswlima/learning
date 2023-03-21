#include "Intervalo.h"


int tipoIntervalor(Tecla, Tecla);
void aumentarAlturaEmUmTom(Tecla &);
void aumentarAlturaEmMeioTom(Tecla &);

/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Intervalo::Intervalo()
{
    Tecla t;
    t.Aleatorio();
    setT1(t);
}

Intervalo::Intervalo(Tecla t)
{
    setT1(t);
}

Intervalo::Intervalo(int o, int n, int a)
{
    Tecla t(o,n,a);
    setT1(t);
}

/////////////////////////////////////////
// Acesso
/////////////////////////////////////////
void Intervalo::setT1(Tecla t){
    t1 = t;
}

Tecla Intervalo::getT1(){
    return t1;
}

void Intervalo::setT2(Tecla t){
    t2 = t;
}

Tecla Intervalo::getT2(){
    return t2;
}

void Intervalo::setNumero(int n){
    numero = n;
}

int Intervalo::getNumero(){
    return numero;
}

void Intervalo::setQualidade(char q){
    qualidade = q;
}

char Intervalo::getQualidade(){
    return qualidade;
}

/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////

int teclado[]={0,1,0,2,0,3,4,0,5,0,6,0,7};

int RetornarSubescrito(int nota){
    int resposta;
    for (int i=1;i<=12;i++){
        if (teclado[i]==nota){
            resposta = i;
            break; 
        }
    }
    return resposta;
}

string QualificarIntervalo(int diff){
    string resposta = "";

    if (diff==1) resposta = "2m";

}


void Intervalo::EncontrarQualificacao(Tecla t){
    setT2(t);

    int n1=getT1().getNota(), n2=t.getNota();
    setNumero(n2-n1+1);
}

string Intervalo::GerarDescricao(){
    string resposta;
    int diferencaEmSemiTons = this->getT2().getNota() - this->getT1().getNota();

    resposta += this->getT1().GerarDescricao() + " ";
    resposta += this->getT2().GerarDescricao() + " - ";
    //resposta += to_string(this->getNumero()) + " - ";
    resposta += to_string(this->getT1().getNota()) + " - ";
    resposta += to_string(this->getT2().getNota()) + " - ";
    resposta += to_string(RetornarSubescrito(this->getT1().getNota())) + " - ";
    resposta += to_string(RetornarSubescrito(this->getT2().getNota())) + " - ";
    resposta += to_string(diferencaEmSemiTons) + " - ";

    return resposta;

}

void Intervalo::Imprimir(){
    cout << this->GerarDescricao();
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

