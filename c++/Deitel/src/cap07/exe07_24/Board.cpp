#include "Board.h"


Board::Board(){
    for (int x=0; x<colunas; x++)
        for (int y=0; y<colunas; y++)
            board[x][y][0]=0;

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
    for (int i=1; i<=3; i++){
        for (int moveNumber=0; moveNumber<7; moveNumber++){
            newCurrentRow    = getCurrentRow()    + vertical  [ moveNumber ];
            newCurrentColumn = getCurrentColumn() + horizontal[ moveNumber ];

            if (posicaoValida(newCurrentRow, newCurrentColumn));
        }

    };

}

void Board::setInicio(int x ,int y){
    setCurrentRow(x);
    setCurrentColumn(y);
}
