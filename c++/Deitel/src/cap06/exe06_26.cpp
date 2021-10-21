#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "MarcusTools.h"

int main(){

    srand( time(0) );

    int quantidade, hora, minuto, segundo;

    cout << "Informe a quatidade de vezes :" << endl;
    cin >> quantidade ;

    for (int i=1; i<=quantidade; i++){

        hora = gerarInteiro(0,11);
        minuto = gerarInteiro(0,59);
        segundo = gerarInteiro(0,59);

        cout << hora << ":" << minuto << ":" << segundo << endl;
    }


}