#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

void buscarMultiplos(int [],int , int);
void imprimirPrimos(int [],int );

int main(){
    const int tamanhoArrei=1000;
    int primos[tamanhoArrei];

    for (int i=0; i<tamanhoArrei ; i++)
        primos[i]=0;


    buscarMultiplos(primos, tamanhoArrei,2);
    buscarMultiplos(primos, tamanhoArrei,3);
    buscarMultiplos(primos, tamanhoArrei,5);
    buscarMultiplos(primos, tamanhoArrei,7);

    mostarArray(primos, tamanhoArrei);

    imprimirPrimos(primos, tamanhoArrei);
}

void buscarMultiplos(int arrei[],int tamanho, int emAnalise){
    arrei[emAnalise]=0;

    for (int subscrito=emAnalise*2 ; subscrito<tamanho ; subscrito++)
        if   (multiple(subscrito,emAnalise))
            arrei[subscrito]=emAnalise;

}

void imprimirPrimos(int arrei[],int tamanho){
    for (int subscrito=2 ; subscrito<tamanho ; subscrito++)
        if (arrei[subscrito]==0)
            cout << "[" << subscrito << "]=" << arrei[subscrito] << " ";

    cout << "\n";

}