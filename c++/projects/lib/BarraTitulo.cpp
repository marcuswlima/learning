#include "BarraTitulo.h"

void ImprimirBarra(int tamanho){
    for (int i = 1; i <= tamanho-2 + 6; i++)
    {
        cout << "-";
    }
}

void ImprimirBarraSuperior(int tamanhoTitulo){
    cout << "/";
    ImprimirBarra(tamanhoTitulo);
    cout << "\\";
    cout << endl;
}

void ImprimirBarraInferior(int tamanhoTitulo){
    cout << "\\";
    ImprimirBarra(tamanhoTitulo);
    cout << "/";
    cout << endl;
}

void ImprimirTitulo(string titulo){
    int tamanhoTitulo = titulo.length();
    ImprimirBarraSuperior(tamanhoTitulo);
    cout << "|- "+ titulo + " -|" << endl;
    ImprimirBarraInferior(tamanhoTitulo);
}

