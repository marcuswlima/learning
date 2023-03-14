#include "tabuleiro.h"

#include <iostream>
using std::cout;

// Conctrutor
Tabuleiro::Tabuleiro(){
    for (int x=0; x<lado; x++)
        for (int y=0; y<lado; y++)
            tabuleiro[x][y]=' ';
    
    setEscrevendo(false);
   
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


void Tabuleiro::queimar(){
    tabuleiro[getX()][getY()] = '*';
}


int Tabuleiro::maiorSubscrito(){
    return lado-1;
}

void Tabuleiro::plotar(int comandos[][2],int x,int y,int orientacao){

    setOrientacao(orientacao);
    setX(x);
    setY(y);
    if (getEscrevendo())
        queimar();

    int i=0;
    while (comandos[i][0]!=9)
    {


        switch (comandos[i][0])
        {
        case 1:/* Caneta para cima */
            setEscrevendo(false);
            break;
        case 2:/* Caneta para baixo*/
            setEscrevendo(true);
            break;
        case 3:/*Vira para a direita*/
            virarDireita();
            break;
        case 4:/*Vira para a esquerda*/
            virarEsquerda();
            break;
        case 5:/*Mova para a frente*/{
            int qtdCasas = comandos[i][1];
            avancar(qtdCasas);
            break;
        }
        case 6:/*Imprima o array 20 por 20*/
            break;
        case 9:/*Sentinela - final*/
            break;
        
        default:
            break;
        }


        i++; 

        cout << "\n";


    }

   
}

void Tabuleiro::avancar(int casas){
    for (int i=1; i<=casas ;i++){
        switch (getOrientacao())
        {
        case 0:/* Norte */
            setX(getX()-1);
            break;
        case 1:/* Leste */
            setY(getY()+1);
            break;
        case 2:/* Sul */
            setX(getX()+1);
            break;
        case 3:/* Oeste*/
            setY(getY()-1);
            break;
        default:
            break;
        }

        if (getEscrevendo())
            queimar();

    }

}

void Tabuleiro::virarDireita(){
    if (getOrientacao()==3)
        setOrientacao(0);
    else
        setOrientacao(getOrientacao()+1);

}

void Tabuleiro::virarEsquerda(){
    if (getOrientacao()==0)
        setOrientacao(3);
    else
        setOrientacao(getOrientacao()-1);

}


/// Orientaçcao
void Tabuleiro::setOrientacao(int in_orientacao){
    orientacao = in_orientacao;
}

int Tabuleiro::getOrientacao(){
    return orientacao;
}

/// X
void Tabuleiro::setX(int in_x){
    x = in_x;
}
int Tabuleiro::getX(){
    return x;
}

/// Y
void Tabuleiro::setY(int in_y){
    y = in_y;
}
int Tabuleiro::getY(){
    return y;
}

/// Escrevendo
void Tabuleiro::setEscrevendo(bool in_escrevendo){
    escrevendo = in_escrevendo;
}

bool Tabuleiro::getEscrevendo(){
    return escrevendo;
}
