#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

#include <iomanip>
using std::setw;

int main(){
    srand( time(0) );

    const int tamanhoSomas=13;
    int somas[tamanhoSomas]={0}, tabela[7][7]={0};

    for (int i=1;i<=36000;i++){
        int dado1 = gerarInteiro(1,6);
        int dado2 = gerarInteiro(1,6);
        somas[dado1+dado2]++;
        tabela[dado1][dado2]++;
    }
    
    cout << "Somas\tvalor\tGráfico\n";
    for (int i=2;i<tamanhoSomas; i++)  {
        cout << "[" << i << "]" << "\t";
        cout << somas[i]        << "\t";

        //for (int g=1; g<=somas[i]; g++)
          //  cout << "*";

        cout << "\n";
    }
    cout << "\n";

    for ( int linha = 1; linha < 7; linha++ ) {
        for ( int coluna = 1; coluna < 7; coluna++ )
            cout << "[" << linha << "," << coluna << "]="  << setw(4) << tabela[ linha ][ coluna ] << " ";

        cout << "\n";
    }


}