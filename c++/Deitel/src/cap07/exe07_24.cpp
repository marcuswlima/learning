#include <iostream>
using std::cout;

void imprimir(char arrei[][8],int colunas);
void posicioar(char arrei[][8], int x, int y, char valor);

int main(){
    const int colunas=(1+7);
    char board[colunas][colunas];

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
    
    int currentRow=3, currentColumn=3, moveNumber=0;

    posicioar(board,currentRow,currentColumn,'x');

    moveNumber=0;
    currentRow=3;
    currentColumn=3;
    currentRow += vertical[ moveNumber ];
    currentColumn += horizontal[ moveNumber ];
    posicioar(board,currentRow,currentColumn,'0');

    moveNumber=1;
    currentRow=3;
    currentColumn=3;
    currentRow += vertical[ moveNumber ];
    currentColumn += horizontal[ moveNumber ];
    posicioar(board,currentRow,currentColumn,'1');

    moveNumber=2;
    currentRow=3;
    currentColumn=3;
    currentRow += vertical[ moveNumber ];
    currentColumn += horizontal[ moveNumber ];
    posicioar(board,currentRow,currentColumn,'2');

    moveNumber=3;
    currentRow=3;
    currentColumn=3;
    currentRow += vertical[ moveNumber ];
    currentColumn += horizontal[ moveNumber ];
    posicioar(board,currentRow,currentColumn,'3');

    imprimir(board,colunas);

}

void imprimir(char arrei[][8],int colunas){
    cout << "/";
    for (int i=1;i<=colunas;i++)
        cout << "-";
    cout << "\\";
    cout << "\n";

    for (int x=0; x<colunas; x++){
        cout << "|";
        for (int y=0; y<colunas; y++)
            cout << arrei[x][y];
        cout << "|";
        cout << "\n";
    }

    cout << "\\";
    for (int i=1;i<=(colunas);i++)
        cout << "-";
    cout << "/";
    cout << "\n";
}

void posicioar(char arrei[][8],int x, int y, char valor){
    arrei[x][y]=valor;
}
