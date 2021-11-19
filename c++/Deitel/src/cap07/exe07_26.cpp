#include <iostream>
using std::cout;

#include <iomanip>
using std::setw;

void imprimirTabuleiro(int [][8], int );
void marcarAlcancaveis(int arrei[][8], int x, int y);
const int lado=8;

int main(){
    int tabuleiro[lado][lado];

    for(int x=0;x<lado;x++)
        for(int y=0 ; y<lado ; y++){
            tabuleiro[x][y]=x+y;
        }

    imprimirTabuleiro(tabuleiro,lado);


    // zerar tabuleiro
    for(int x=0;x<lado;x++)
        for(int y=0 ; y<lado ; y++){
            tabuleiro[x][y]=0;
        }


    int x=7,y=0;
    marcarAlcancaveis(tabuleiro, x, y);
    imprimirTabuleiro(tabuleiro,lado);

    return 0;
   
}

void imprimirTabuleiro(int arrei[][8], int lado ){
    cout << "\n";
    cout <<"------------------------------------------\n"; 
    cout <<" |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |\n";
    cout <<"------------------------------------------\n"; 


    for (int x=0; x<lado; x++){
        cout << x << "| ";
        for (int y=0; y<lado; y++)
            cout << setw(2) << arrei[x][y]<< " | ";
        cout << "\n";
    }

    cout <<"------------------------------------------\n"; 

}

void marcar(int arrei[][8], int x, int y, int valor){
    arrei[x][y]=valor;
}

bool EstaoMesmaColuna(int x1,int y1, int x2, int y2){
    return y1==y2;
}

bool EstaoMesmaLinha(int x1,int y1, int x2, int y2){
    return x1==x2;
}

bool EstaoMesmaDiagonal(int x1,int y1, int x2, int y2){
    return (x1+y1==x2+y2);
}

int quantosAlcanca(int x, int y){
    int contador=0;
    for(int row=0 ; row<lado ; row++)
        for(int col=0 ; col<lado ; col++)
            if (EstaoMesmaColuna(x,y,row,col) || EstaoMesmaLinha(x,y,row,col) || EstaoMesmaDiagonal(x,y,row,col)) 
                contador++;
    
    return contador;
}

void marcarAlcancaveis(int arrei[][8], int x, int y){
    int iQuantosAlcanca=quantosAlcanca(x,y);

    cout << iQuantosAlcanca;
    for(int row=0 ; row<lado ; row++){
        cout << row << "\n";
        for(int col=0 ; col<lado ; col++){
            if (EstaoMesmaColuna(x,y,row,col) /*|| EstaoMesmaLinha(x,y,row,col) || EstaoMesmaDiagonal(x,y,row,col)*/) 
                marcar(arrei,x,y,iQuantosAlcanca);
        }
    }
}