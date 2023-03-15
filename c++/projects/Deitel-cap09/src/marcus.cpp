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

    ImprimirTitulo("Marcus William");
    exe_07_17();

    cout << "CalcMdc -> " << CalcMdc(80,30) << endl;
}

void exe_07_17(){
    const int tamanhoSomas=14;
    int errado=0 ;
    int somas[tamanhoSomas]={0}, tabela[7][7]={0};
    int quantLancamento[7]={0,0,0,0,0,0,0};

    PrintVector(quantLancamento,7,"quantLancamento");


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

    PrintVector(somas,tamanhoSomas,"somas");
    
    PrintVector(quantLancamento,7,"quantLancamento");

    for ( int linha = 1; linha < 7; linha++ ) {
        for ( int coluna = 1; coluna < 7; coluna++ )
            cout << "[" << linha << "," << coluna << "]="  << setw(4) << tabela[ linha ][ coluna ] << " ";

        cout << "\n";
    }

}

