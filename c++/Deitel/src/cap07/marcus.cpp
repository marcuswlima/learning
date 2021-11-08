#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
#include "../lib/marcusLib.h"

void imprimirArrayBiInt(int a[4]);

int main(){

    const int tamanhoTabela = 3; 
    const int qtdLinhas = tamanhoTabela+1; 
    const int qtdColunas = tamanhoTabela+1; 

    int tabela[ qtdLinhas ][ qtdColunas ];

    for (int x=1;x<qtdLinhas;x++)
        for (int y=1;y<qtdColunas;y++)
            tabela[x][y]=gerarInteiro(1,10);
    
    imprimirArrayBiInt(tabela);

    return 0;
}

void imprimirArrayBiInt(int a[4]){
    for (int x=1;x<4;x++)
        for (int y=1;y<4;y++)
            cout << a[x];

}