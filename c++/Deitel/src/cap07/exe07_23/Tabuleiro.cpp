#include "tabuleiro.h"

#include <iostream>
using std::cout;

// Conctrutor
Tabuleiro::Tabuleiro(){
    for (int x=0; x<lado; x++)
        for (int y=0; y<lado; y++)
            tabuleiro[x][y]=' ';
   
}

void Tabuleiro::queimar(int x, int y){
    tabuleiro[x][y] = '*';
}

void Tabuleiro::imprimir(){
    cout << "/";
    for (int i=1;i<=lado;i++)
        cout << "-";
    cout << "\\";
    cout << "\n";

    for (int x=0; x<lado; x++){
        cout << "|";
        for (int y=0; y<lado; y++)
            cout << tabuleiro[x][y];
        cout << "|";
        cout << "\n";
    }

    cout << "\\";
    for (int i=1;i<=(lado);i++)
        cout << "-";
    cout << "/";
    cout << "\n";
}

int Tabuleiro::maiorSubscrito(){
    return lado-1;
}

void Tabuleiro::plotar(int in_movimentos[][2],int x_inicial,int y_inical){
    int x_atual = x_inicial, y_atual=y_inical;
    queimar(x_atual,y_atual);

    // popular array interno de movimentos
    int i=0;
    while (in_movimentos[i][0]!=9)
    {

        for (int coluna=0;coluna<2; coluna++)
            movimentos[i][coluna] = in_movimentos[i][coluna];
        
        i++;

    }

/*
    i=0;
    while (movimentos[i][0]!=9)
    {
        for (int p=1; p<=movimentos[i][2]; p++){
            x_atual--;
            queimar(x_atual,y_atual);
        }

    }
*/    
    
}