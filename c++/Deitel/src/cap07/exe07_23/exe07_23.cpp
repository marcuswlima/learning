#include <iostream>
using std::cout;

#include <iomanip>

#include "tabuleiro.h"

int gerarInteiro(int,int);

int main(){

    srand( time(0) );

    Tabuleiro tabuleiro;

    int comandos[40][2]={{5,12},
                         {9   }
                        };    
    int x_inicial = 18;
    int y_inicial = 4;


    tabuleiro.plotar(comandos,x_inicial, y_inicial);
    tabuleiro.imprimir();


    return 0;
} // fim main

int gerarInteiro(int menor, int maior) {

    if (maior > menor){
        int faixa  = (maior - menor + 1);
        int gerado = (1 + rand() % faixa);
        return menor + (gerado-1);
    }
    else
        return 0;

}// fim gerarInteiro

