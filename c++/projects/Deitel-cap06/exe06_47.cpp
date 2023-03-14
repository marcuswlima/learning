#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include "cai.h"

int main()
{
    int nivel, operacao;
    srand( time(0) );

    cout << "Nível [1,2] ";
    cin >> nivel;

    cout << "Operação [1-Adição, 2-subtração, 3-Multiplicação, 4-divisão e 5-Todos] ";
    cin >> operacao;


    testeMultiplicacao(nivel,operacao );

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

