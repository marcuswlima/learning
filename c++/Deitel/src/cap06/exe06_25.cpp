#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include "cap06.h"

void separaInteiro (int entrou);

int gExpoente;

int main()
{
    int inteiro;

    srand( time(0) );


    for (int i=1;i<=100;i++){

        inteiro = gerarInteiro(1,32767);

        if (inteiro > 10000)
            gExpoente = 4;
        else
            if (inteiro > 1000)
                gExpoente = 3;
            else
                if (inteiro > 100)
                    gExpoente = 2;
                else 
                    if (inteiro > 10)
                        gExpoente = 1;
                    else 
                        gExpoente = 0;

        cout << setw(3) << i       << " - " 
             << setw(5) << inteiro << " - ";
        separaInteiro(inteiro) ;

        cout << endl; 
    }



//--------------------------------------------
    cout << endl << endl ;
    return 0;

}

void separaInteiro (int entrou){
    int separado, resto ;
    if (gExpoente==0)
        cout << entrou;
    else{
        separado = entrou/integerPower(10,gExpoente);
        resto = entrou%integerPower(10,gExpoente);
        cout << separado << " ";
        gExpoente--;
        separaInteiro(resto);
    }
}
