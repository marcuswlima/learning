#include "PrintArray.h"
#include "BarraTitulo.h"

#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>
using std::setw;


void PrintVector( const double arrei[], const int sizeOfArray, const string titulo ){

    if (titulo!="titulo")
        ImprimirTitulo(titulo);

    for (int i=0;i<sizeOfArray;i++)
        cout << "[" << i << "]=" << arrei[i] << " ";

    cout << endl;
    cout << endl;

}

void PrintVector( const int arrei[], int sizeOfArray, string titulo="" ){

    if (titulo!="")
        ImprimirTitulo(titulo);

    for (int i=0;i<sizeOfArray;i++)
        cout << "[" << i << "]=" << arrei[i] << " ";

    cout << endl;
    cout << endl;

}

void PrintMatrix(const int arrei[][2], const int linhas, const int colunas, string titulo=""){

    if (titulo!="")
        ImprimirTitulo(titulo);

    for ( int linha = 0; linha < linhas; linha++ ) {
        for ( int coluna = 0; coluna < colunas; coluna++ )
            cout << "[" << linha << "," << coluna << "]="  << setw(4) << arrei[ linha ][ coluna ] << " ";

        cout << "\n";
    }
    cout << "\n";

}
