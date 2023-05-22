#include "BarraTitulo.h"

void ImprimirBarra(int tamanho){
	for (int i = 1; i <= tamanho-2 + 2; i++)
    {
        cout << "\u2500";
    }
}

void ImprimirBarraSuperior(int tamanhoTitulo){
    cout << "\u250C";
    ImprimirBarra(tamanhoTitulo);
    cout << "\u2510";
    cout << endl;
}

void ImprimirBarraInferior(int tamanhoTitulo){
    cout << "\u2514";
    ImprimirBarra(tamanhoTitulo);
    cout << "\u2518";
    cout << endl;
}

void ImprimirTitulo(string titulo){
    int tamanhoTitulo = titulo.length();
    ImprimirBarraSuperior(tamanhoTitulo);
	cout << "\u2502" + titulo + "\u2502" << endl;
    ImprimirBarraInferior(tamanhoTitulo);
}

