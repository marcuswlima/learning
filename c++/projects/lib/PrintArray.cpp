#include "PrintArray.h"
#include "BarraTitulo.h"

void PrintVector( const char arrei[], const int sizeOfArray, const string titulo ){

    if (titulo!="")
        ImprimirTitulo(titulo);

    for (int i=0;i<sizeOfArray;i++)
        cout << "[" << i << "]=" << arrei[i] << " ";

    cout << endl;
    cout << endl;

}

void PrintVector( const double arrei[], const int sizeOfArray, const string titulo ){

    if (titulo!="")
        ImprimirTitulo(titulo);

    for (int i=0;i<sizeOfArray;i++)
        cout << "[" << i << "]=" << arrei[i] << " ";

    cout << endl;
    cout << endl;

}

void PrintVector( const int arrei[], const int sizeOfArray, const string titulo ){

    if (titulo!="")
        ImprimirTitulo(titulo);

    for (int i=0;i<sizeOfArray;i++)
        cout << "[" << i << "]=" << arrei[i] << " ";

    cout << endl;
    cout << endl;

}

void PrintMatrix(const int arrei[][2], const int linhas, const int colunas, const string titulo){
	int maiorNumero=0,tamanhoMaiorNumero=0;

    if (titulo!="")
        ImprimirTitulo(titulo);

    for ( int linha = 0; linha < linhas; linha++ ){ 
        for ( int coluna = 0; coluna < colunas; coluna++ ){
			if (arrei[linha][coluna]>maiorNumero){
				maiorNumero = arrei[linha][coluna];
			}
		}
	}
	tamanhoMaiorNumero = to_string(maiorNumero).length(); //tranformar em string e apresentar tamanho da string

    for ( int linha = 0; linha < linhas; linha++ ) {
        for ( int coluna = 0; coluna < colunas; coluna++ )
            cout << "[" << linha << "," << coluna << "]="  << setw(tamanhoMaiorNumero) << arrei[ linha ][ coluna ] << " ";

        cout << "\n";
    }
    cout << "\n";

}

void PrintMatrix(const string arrei[][2], const int linhas, const int colunas, const string titulo){
	int maiorTamanho=0;

    if (titulo!="")
        ImprimirTitulo(titulo);

    for ( int linha = 0; linha < linhas; linha++ ){ 
        for ( int coluna = 0; coluna < colunas; coluna++ ){
			if (arrei[linha][coluna].length() > maiorTamanho){ //apresentar tamanho da string
				maiorTamanho = arrei[linha][coluna].length();
			}
		}
	}

    for ( int linha = 0; linha < linhas; linha++ ) {
        for ( int coluna = 0; coluna < colunas; coluna++ )
            cout << "[" << linha << "," << coluna << "]="  << setw(maiorTamanho) << arrei[ linha ][ coluna ] << " ";

        cout << "\n";
    }
    cout << "\n";

}
