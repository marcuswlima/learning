#include <iostream>
using std::cout;

#include <iomanip>
using std::setw;

#include "../../lib/BarraTitulo.h"
#include "../../lib/PrintArray.h"
#include "../../lib/marcusLib.h"
#include "../../lib/Mathematics.h"
#include "../../lib/ObterNumero.h"
#include "../../lib/SystemNumeral.h"

void Mathematics();
void PrintArray();
void ObterNumero();
void SystemNumeral();

int main(){
    srand( time(0) );
	//PrintArray();
	//ObterNumero();
	//Mathematics();	
	SystemNumeral();
}

void SystemNumeral(){
	ImprimirTitulo("libTester - SystemNumeral");
    cout << "ConvertHexaToDecimal -> " << ConvertHexaToDecimal("0") << endl;
	cout << "ConvertHexaToDecimal -> " << ConvertHexaToDecimal("1") << endl;
	cout << "ConvertHexaToDecimal -> " << ConvertHexaToDecimal("A") << endl;
	cout << "ConvertHexaToDecimal -> " << ConvertHexaToDecimal("F") << endl;
	cout << "ConvertHexaToDecimal -> " << ConvertHexaToDecimal("10") << endl;
	cout << "ConvertHexaToDecimal -> " << ConvertHexaToDecimal("11") << endl;
}

void ObterNumero(){
	int numero;
	ImprimirTitulo("ObterNumero.h");
    numero = ObterNumeroNaFaixa("Digite um número entre 1 e 10: ",1,10);
	cout << numero << endl;
}

void PrintArray(){
	ImprimirTitulo("PrintArray.h");
    const int tamanhoSomas=14;
    int errado=0 ;
    int somas[tamanhoSomas]={0}, tabela[7][7]={0};
    int quantLancamento[7]={0,0,0,0,0,0,0};
    
	for (int i=1;i<=36000;i++){
        int dado1 = GerarInteiro(1,6);
        int dado2 = GerarInteiro(1,6);
        if ((dado1>6)||(dado2>6))
            errado++;
        somas[dado1+dado2]++;
        tabela[dado1][dado2]++;

        quantLancamento[dado1]++;
        quantLancamento[dado2]++;
    }

    PrintVector(somas,tamanhoSomas);
    
	int qdtLinhas=5;
    int matriz[qdtLinhas][2];
    for ( int coluna = 0; coluna < 2; coluna++ )
        for ( int linha = 0; linha <= (qdtLinhas); linha++ ) {
            matriz[linha][coluna]=GerarInteiro(1,100000);
        }
    PrintMatrix(matriz,qdtLinhas,2);
}

void Mathematics(){
	ImprimirTitulo("Mathematics.h");
    cout << "CalcMdc -> " << CalcMdc(80,30) << endl;
    cout << "CalcRealRoots -> " << CalcRealRoots(10,10,1) << endl;
}
