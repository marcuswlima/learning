#include <iostream>
using std::cout;

#include <iomanip>

#include "tabuleiro.h"

int gerarInteiro(int,int);

int main(){

    srand( time(0) );

    Tabuleiro tabuleiro;

    int comandos[40][2]={{2},
                         {5,4},
                         {1},
                         {5,1},
                         {2},
                         {5,3},
                         {9  }
                        };    
    int x=10, y=10, orientacao=2;

    tabuleiro.plotar(comandos
                    ,x
                    ,y
                    ,orientacao
                    );
    cout << "\n";
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

