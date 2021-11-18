#include <iostream>
using std::cout;

#include "../lib/marcusLib.h"

#include <iomanip>
using std::setw;

void imprimir(char [][8],int);
void posicionar(char [][8],int, int, int);
void posicionar(char [][8],int, int, char);
bool posicaoValida(int, int);
void marcar(char [][8],int , int);
bool marcado(char [][8],int, int);

int main(){
    srand( time(0) );

    const int colunas=(1+7);
    char board[colunas][colunas];
    int board2[colunas][colunas][2];

    int horizontal[colunas];
    int vertical[colunas];

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
    
    for (int x=0; x<colunas; x++)
        for (int y=0; y<colunas; y++)
            board[x][y]=' ';
    
/*

    int rand_currentRow=gerarInteiro(0,7), 
        rand_currentColumn=gerarInteiro(0,7),
        currentRow,
        currentColumn;
    posicionar(board,rand_currentRow,rand_currentColumn,'x');


    for (int moveNumber=0 ; moveNumber <= 7 ; moveNumber++){
        currentRow = rand_currentRow;
        currentColumn = rand_currentColumn;
        if (posicaoValida(currentRow+vertical[ moveNumber ], currentColumn + horizontal[ moveNumber ])){
            currentRow += vertical[ moveNumber ];
            currentColumn += horizontal[ moveNumber ];
            posicionar(board,currentRow,currentColumn,moveNumber);
        }
    }

    imprimir(board,colunas);

----------------------------------------------
    int currentRow=0, currentColumn=1;
    bool faz;
    marcar(board,currentRow,currentColumn);
    for (int i=1; i<=10; i++) {
        for (int moveNumber=0; moveNumber<7; moveNumber++){
            faz = posicaoValida(currentRow+vertical[ moveNumber ], currentColumn + horizontal[ moveNumber ])&&
                  !marcado(board,currentRow+vertical[ moveNumber ], currentColumn + horizontal[ moveNumber ]);
            if (faz){
                currentRow += vertical[ moveNumber ];
                currentColumn += horizontal[ moveNumber ];
                marcar(board,currentRow,currentColumn);
                break;
            }

        }
    }


    int currentRow=0, currentColumn=1;
    bool faz;
    marcar(board,currentRow,currentColumn);
    for (int i=1; i<=10; i++) {
        for (int moveNumber=0; moveNumber<7; moveNumber++){
            faz = posicaoValida(currentRow+vertical[ moveNumber ], currentColumn + horizontal[ moveNumber ])&&
                  !marcado(board,currentRow+vertical[ moveNumber ], currentColumn + horizontal[ moveNumber ]);
            if (faz){
                currentRow += vertical[ moveNumber ];
                currentColumn += horizontal[ moveNumber ];
                marcar(board,currentRow,currentColumn);
                break;
            }

        }
    }

*/


    return 0;

}

void imprimir(char arrei[][8],int colunas){
    cout << "/";
    for (int i=0;i<colunas;i++){
        cout << " " << i << " ";
        if (i<7)
            cout << "|";
    }
    cout << "\\";
    cout << "\n";

    for (int x=0; x<colunas; x++){
        cout << x;
        for (int y=0; y<colunas; y++)
            cout << setw(3) << arrei[x][y] ;
        cout << "|";
        cout << "\n";
    }

    cout << "\\";
    for (int i=1;i<=(colunas);i++)
        cout << "----";
    cout << "/";
    cout << "\n";
}

void posicionar(char arrei[][8],int x, int y, int valor){
    char cValue = '0' + valor;
    arrei[x][y]=cValue;
}

void posicionar(char arrei[][8],int x, int y, char valor){
    arrei[x][y]=valor;
}

bool posicaoValida(int x, int y){
    return x>=0 && x<=7 && y>=0 && y<=7;
}

bool marcado(char arrei[][8],int x, int y){
    return arrei[x][y]=='*';
}


bool aindaExisteVazio(char arrei[][8]){
    for (int x=0 ; x<7 ; x++)
        for (int y=0 ; y<7 ; y++)
            if (arrei[x][y] ==' ')
                return true;
    return false;
}

void imprimir(int x, int y){
    cout << x << " " << y << "\n";
}

void marcar(char arrei[][8],int x, int y){
    arrei[x][y]='*';
    imprimir(x,y);
}



