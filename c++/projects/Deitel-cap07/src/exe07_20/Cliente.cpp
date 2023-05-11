#include "Cliente.h"

#include <iostream>
using std::cout;

Cliente::Cliente(int tipoPassagem=2,int preferenciaAssento=0, bool aceitaSugestao=true){
    setTipoPassagem(tipoPassagem);
    setPreferenciaAssento(preferenciaAssento);
    setAceitaSugestao(aceitaSugestao);
}

void Cliente::setTipoPassagem(int in_tipoPassagem){
    tipoPassagem = in_tipoPassagem;
}

void Cliente::setPreferenciaAssento(int in_preferenciaAssento){
    preferenciaAssento = in_preferenciaAssento;
}

void Cliente::setAceitaSugestao(bool in_aceitaSugestao){
    aceitaSugestao = in_aceitaSugestao;
}

int Cliente::getTipoPassagem(){
    return tipoPassagem;
}

int Cliente::getPreferenciaAssento(){
    return preferenciaAssento;
}

bool Cliente::getAceitaSugestao(){
    return aceitaSugestao;
}

void Cliente::imprimir(){
    cout << "TipoPassagem: "       << getTipoPassagem()       << "\n";
    cout << "PreferenciaAssento: " << getPreferenciaAssento() << "\n";
    cout << "AceitaSugestao: "     << getAceitaSugestao()     << "\n";
}
