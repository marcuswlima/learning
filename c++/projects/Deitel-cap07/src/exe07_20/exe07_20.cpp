#include <iostream>
using std::cout;

#include "Atendente.h"

#include <iomanip>

int gerarInteiro(int, int);

int main(){

    srand( time(0) );

    Atendente atendente;
    int atendimento=1;


    while (atendente.haVagas()){

        cout << "* " << atendimento << "\n";
        int TipoPassagem;
        int preferenciaAssento;
        bool aceitaSugestao=true;

        TipoPassagem=gerarInteiro(1,2);

        preferenciaAssento=gerarInteiro(0,1);
        if (preferenciaAssento==1){
            if (TipoPassagem==1)
                preferenciaAssento = gerarInteiro(1,4);
            if (TipoPassagem==2)
                preferenciaAssento = gerarInteiro(5,10);
            
            aceitaSugestao=gerarInteiro(0,1);
        }


        Cliente cliente(TipoPassagem,preferenciaAssento,aceitaSugestao);
        cliente.imprimir();

        atendente.atender(cliente);
        atendente.mostrarAssentos();
        atendimento++;

    }

}// fim main

int gerarInteiro(int menor, int maior) {

    if (maior > menor){
        int faixa  = (maior - menor + 1);
        int gerado = (1 + rand() % faixa);
        return menor + (gerado-1);
    }
    else
        return 0;

}// fim gerarInteiro


