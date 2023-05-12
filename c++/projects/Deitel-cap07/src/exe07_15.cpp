#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

int pesquisaLiniear(const int[], int , int );

int main(){

    srand( time(0) );

    const int tamanhonumerosNaoRepetidos=19;
    int numerosNaoRepetidos[tamanhonumerosNaoRepetidos]={0};
    int inseridos=0;

    for (int i=1;i<=20;i++){
        int numero=gerarInteiro(10,100);
        if (pesquisaLiniear(numerosNaoRepetidos,tamanhonumerosNaoRepetidos,numero) == -1) {
            numerosNaoRepetidos[inseridos]=numero;
            inseridos++;
        }
    }

    mostarArray(numerosNaoRepetidos,tamanhonumerosNaoRepetidos);
}

int pesquisaLiniear(const int arrei[], int tananhoArrei, int chave ){
    for (int i=0; i<tananhoArrei; i++)
        if (arrei[i]==chave)
            return arrei[i];
    
    return -1;

}