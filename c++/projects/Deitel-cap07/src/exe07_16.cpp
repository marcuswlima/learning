#include "../lib/marcusLib.h"

int main(){
    const int linhas=3, colunas=5;
    int sales[linhas][colunas]={0};
    int contador=1;

    for (int row=0; row<linhas; row++)
        for (int column=0; column<colunas; column++){
            sales[row][column]=contador;
            contador++;
        }

    mostraArr2D(sales,linhas,colunas);

}