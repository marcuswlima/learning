#include "Atendente.h"

#include <iostream>
using std::cout;

Atendente::Atendente(){
    for (int i=0; i<sizeAssentos; i++)
        assentos[i]=0;
}

void Atendente::setAssentoVendido(int assento){
    assentoVendido = assento;
}

int Atendente::getAssentoVendido(){
    return assentoVendido;
}

bool Atendente::estaOcupado(int assentoDesejado){
    return assentos[assentoDesejado]==1;
};

int Atendente::obterUmaVaga(int tipoPassagem){
    int menor, maior ;

    if (tipoPassagem==1){ // primeira classe
        menor = 1;
        maior = 4;
    }
    else {   // economica
        menor = 5;
        maior = 10;
    }

    for (int i=menor; i<=maior; i++)
        if (!estaOcupado(i)){
            return i;
        }

    return -1;

}

void Atendente::mostrarAssentos(){
    cout << "[1] [2] [3] [4] | [5] [6] [7] [8] [9] [10]\n";

    for (int i=1; i<=4; i++){ 
        if (assentos[i]==1)
            cout << " * " ;
        else 
            cout << "   ";
        ;
        cout << " ";
    }        

    cout << "| ";

    for (int i=5; i<=10; i++){ 
        if (assentos[i]==1)
            cout << " * " ;
        else 
            cout << "   ";
        ;
        cout << " ";
    }        


    cout << "\n";

}

void Atendente::emitirBilhete(Cliente cliente){
    cout << "********* Bilhete ";

    if (cliente.getTipoPassagem() == 1)
        cout << "Primeira classe, ";
    else
        cout << "Economica, ";

    cout << "assento: " << getAssentoVendido();

    cout << "\n";
}

void Atendente::queimarAssento(int assento ){
    assentos[assento]=1;
    setAssentoVendido(assento);
}

void Atendente::atender(Cliente cliente){
    int assentoLivre;
    if ( cliente.getPreferenciaAssento() == 0 ){  // se não há preferencia 
        assentoLivre = obterUmaVaga(cliente.getTipoPassagem());
        if (assentoLivre > 0){ //Se ainda existe vaga
            queimarAssento(assentoLivre);
            emitirBilhete(cliente);
        } else { // está lotado
            cout << "Lotado\n";
        }
    } else {  // se há prefencia
        bool desejadoLivre = !estaOcupado(cliente.getPreferenciaAssento());
        if (desejadoLivre){ // o desejado está livre
            queimarAssento(cliente.getPreferenciaAssento());
            emitirBilhete(cliente);
        } else { //o desejado não está livre
            if (cliente.getAceitaSugestao()){
                assentoLivre = obterUmaVaga(cliente.getTipoPassagem());
                 if (assentoLivre > 0){ //Se ainda existe vaga
                    queimarAssento(assentoLivre);
                    emitirBilhete(cliente);
                } else {
                    cout << "Lotado\n";
                }
            } else   
             cout << "Proximo\n";
        }

    }
}

bool Atendente::haVagas(){
    for (int i=1; i<=10; i++)
        if (!estaOcupado(i)){
            return true;
        }

    return false;

}

