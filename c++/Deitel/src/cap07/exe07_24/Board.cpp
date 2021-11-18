#include "Board.h"

#include <iostream>
using std::cout;

#include <iomanip>
using std::setw;

Board::Board(){
    zerar();

    horizontal[ 0 ] = 2;
    horizontal[ 1 ] = 1;
    horizontal[ 2 ] = -1;
    horizontal[ 3 ] = -2;
    horizontal[ 4 ] = -2;
    horizontal[ 5 ] = -1;
    horizontal[ 6 ] = 1;
    horizontal[ 7 ] = 2;
      vertical[ 0 ] = -1;
      vertical[ 1 ] = -2;
      vertical[ 2 ] = -2;
      vertical[ 3 ] = -1;
      vertical[ 4 ] = 1;
      vertical[ 5 ] = 2;
      vertical[ 6 ] = 2;
      vertical[ 7 ] = 1;
}

void Board::setCurrentRow(int x){
    currentRow = x;
}

int Board::getCurrentRow(){
    return currentRow;
}

void Board::setCurrentColumn(int y){
    currentColumn = y;
}

int Board::getCurrentColumn(){
    return currentColumn;
}

bool posicaoValida(int x, int y){
    return x>=0 && x<=7 && y>=0 && y<=7;
}

void Board::movimentar(){
    int newCurrentRow, newCurrentColumn;
    bool faz,fez;

    cout << "[" << getCurrentRow() << "," << getCurrentColumn() << "] ";

    for (int i=1; i<=100; i++){

        faz = false; 

        for (int moveNumber=0; moveNumber<7; moveNumber++){
            newCurrentRow    = getCurrentRow()    + vertical  [ moveNumber ];
            newCurrentColumn = getCurrentColumn() + horizontal[ moveNumber ];

            faz = posicaoValida(newCurrentRow, newCurrentColumn) && !marcado(newCurrentRow, newCurrentColumn);

            if (faz){
                setCurrentRow(newCurrentRow);
                setCurrentColumn(newCurrentColumn);
                marcar(getCurrentRow(),getCurrentColumn(),i+1);
                break;
            }
        }

        fez = faz;

        if(!fez){
            cout << i << " movimentacoes\n";
            break;
        }

    }

}


void Board::setInicio(int x ,int y){
    setCurrentRow(x);
    setCurrentColumn(y);
    marcar(x,y,1);
}

int Board::marcado(int x ,int y){
    return board[x][y]>0;
}

void Board::imprimirOcupacao(){
    cout << "/";
    for (int i=0;i<=7;i++){
        cout <<  i ;
    }
    cout << "\\";
    cout << "\n";

    for (int x=0; x<colunas; x++){
        cout << x;
        for (int y=0; y<colunas; y++)
            if (marcado(x,y))
                cout << board[x][y];
            else
                cout << "|" ;
        cout << "\n";
    }
}

void Board::marcar(int x ,int y, int ordem){
    board[x][y]=ordem;
}

void Board::imprimirOrdem(){
    cout << "\n";
    cout <<"------------------------------------------\n"; 
    cout <<" |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |\n";
    cout <<"------------------------------------------\n"; 


    for (int x=0; x<colunas; x++){
        cout << x << "| ";
        for (int y=0; y<colunas; y++)
            cout << setw(2) << board[x][y]<< " | ";
        cout << "\n";
    }

    cout <<"------------------------------------------\n"; 

}

void Board::zerar(){
    for (int x=0; x<colunas; x++)
        for (int y=0; y<colunas; y++){
            board[x][y]=0;
        }
}