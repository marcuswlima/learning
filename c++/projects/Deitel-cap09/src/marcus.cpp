#include <iostream>
using std::cout;

#include <iomanip>
using std::setw;


#include "../../lib/BarraTitulo.h"
#include "../../lib/PrintArray.h"
#include "../../lib/marcusLib.h"
#include "../../lib/Mathematics.h"

void exe_07_17();

int main(){
    srand( time(0) );

    ImprimirTitulo("\\Deitel-cap09\\marcus.cpp");
    exe_07_17();
}

void exe_07_17(){
    const int tamanhoSomas=14;
    int errado=0 ;
    int somas[tamanhoSomas]={0}, tabela[7][7]={0};
    int quantLancamento[7]={0,0,0,0,0,0,0};

 //:   PrintVector(quantLancamento,7,"quantLancamento");


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

//    PrintVector(somas,tamanhoSomas,"somas");
    
//    PrintVector(quantLancamento,7,"quantLancamento");

    int qdtLinhas=10;
    int matriz[qdtLinhas][2];
    for ( int coluna = 0; coluna < 2; coluna++ )
        for ( int linha = 0; linha < (qdtLinhas-1); linha++ ) {
            matriz[linha][coluna]=GerarInteiro(1,100);
        }
   
//   matriz[0][0]=1000000;	
    PrintMatrix(matriz,qdtLinhas-1,2,"Matriz");
    cout << "CalcMdc -> " << CalcMdc(80,30) << endl;
    cout << "CalcRealRoots -> " << CalcRealRoots(10,10,1) << endl;
}


