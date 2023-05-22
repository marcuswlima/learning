#include <iostream>
using namespace std;

//using std::setw;
//using std::cout;

#include "../../lib/BarraTitulo.h"
#include "../../lib/PrintArray.h"
#include "../../lib/marcusLib.h"
#include "../../lib/Mathematics.h"
#include "../../lib/ObterNumero.h"
#include "../../lib/SystemNumeral.h"
#include "../../lib/NumeroExtenso.h"

void Mathematics();
void PrintArray();
void ObterNumero();
void SystemNumeral();
void NumeroExtenso();
void BarraTitulo();	

int main(){
	srand( time(0) );
//PrintArray();
//	ObterNumero();
//	Mathematics();	
//	SystemNumeral();
//	NumeroExtenso();
	BarraTitulo();
}

void BarraTitulo(){	
	ImprimirTitulo("Marcus William dos santos lima");
}

/*
void NumeroExtenso(){
	ImprimirTitulo("libTester - NumeroExtenso");
	for(int i=1;i<=999;i++){		
        cout << i << "\t" << ShowNumberEnglishPronuciation (i) << endl;
    }
}
*/

void SystemNumeral(){
	ImprimirTitulo("libTester - SystemNumeral");
	string str_binario, str_hexa;
	for(int i=1;i<=1050;i++){		
		str_hexa    = ConvertDecimalToHexadecimal(i);
		str_binario = ConvertDecimalToBinary(i);
		cout << setw(3)  << i << "\t";
		cout << setw(3)  << str_hexa    << "\t";
		cout << setw(11) << str_binario << "\t";
		cout             << ConvertHexaToDecimal(str_hexa) << "\t";
		//cout             << ConvertBinaryToDecimal(str_binario) << "\t";

		cout << endl;

	}
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

    PrintVector(somas,tamanhoSomas,"vector de inteiro");
    
	int qdtLinhas=5;
    int matriz[qdtLinhas][2];
    PrintMatrix(matriz,qdtLinhas,2,"Matriz de inteiro");

	qdtLinhas=5;
    string str_matriz[3][2]={{"marcus","william"},{"dos","santos"},{"lima"}};
    PrintMatrix(str_matriz,3,2,"Matriz string de 2 colunas");
    PrintMatrix(str_matriz,3,2);
}

void Mathematics(){
	ImprimirTitulo("Mathematics.h");
    cout << "CalcMdc -> " << CalcMdc(80,30) << endl;
    cout << "CalcRealRoots -> " << CalcRealRoots(10,10,1) << endl;
}
