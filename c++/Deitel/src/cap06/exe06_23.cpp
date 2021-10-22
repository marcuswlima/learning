#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;


#include "cap06.h"


int main()
{
    int lado;
    char caracterDePreenchimento;

    cout << "Qual o lado do quandrado ? ";
    cin >> lado ; 

    cout << "Qual o lado caracter a ser utilizador ? ";
    cin >> caracterDePreenchimento ; 

    imprimirQuadrado(lado, caracterDePreenchimento);

    return 0;
}
