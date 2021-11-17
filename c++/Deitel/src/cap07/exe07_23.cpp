#include <iostream>
using std::cout;

#include "../lib/marcusLib.h"

int main(){

    srand( time(0) );

    const int lado=20;
    char tabuleiro[lado][lado]={' '};

    for (int x=0; x<lado; x++)
        for (int y=0; y<lado; y++)
            tabuleiro[x][y]=' ';

    tabuleiro[gerarInteiro(0,19)][gerarInteiro(0,19)]='*';


    for (int i=1;i<=22;i++)
        cout << "-";
    cout << "\n";

    for (int x=0; x<lado; x++){
        cout << "|";
        for (int y=0; y<lado; y++)
            cout << tabuleiro[x][y];
        cout << "|";
        cout << "\n";
    }

    for (int i=1;i<=22;i++)
        cout << "-";
    cout << "\n";


}