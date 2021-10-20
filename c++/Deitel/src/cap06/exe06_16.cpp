#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;

#include <cmath>

using std::ios;

#include "MarcusTools.h"

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()

void imprimir_aleatorios(int menor, int maior);

int quantidade = 100;

int main()
{
    
    srand( time(0) );

    imprimir_aleatorios(1,30);
    imprimir_aleatorios(1,2);
    imprimir_aleatorios(1,100);
    imprimir_aleatorios(988,1003);
    imprimir_aleatorios(0,9);
    imprimir_aleatorios(-1,-101);
    imprimir_aleatorios(-3,1);
    imprimir_aleatorios(-3,-3);
    imprimir_aleatorios(-3,11);

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

void imprimir_aleatorios(int menor, int maior){

    int pares=0, impares=0, gerado;

    cout << menor << " <= n <= " << maior << endl ;

    if (maior > menor) {

        for (int i=1; i<=quantidade; i++ ) {
            gerado = gerarInteiro(menor,maior); 
            cout << gerado << " " ;
            if (ehPar(gerado))
                pares++;
            else
                impares++;
        }


        cout << endl ;
        cout << "pares: " << pares << " imapres: " << impares << endl;
    }
    cout << endl ;
}

