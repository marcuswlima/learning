//Fig 1.6: fig01_06.cpp
// Programa de Adição
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ( )
{
    int integer1, integer2; //Declaração

    cout << "Digite o primeiro numero inteiro\n"; //prompt
    cin >> integer1;
    cout << "Digite o segundo numero inteiro\n"; //prompt
    cin >> integer2;

    if ( integer1 > integer2 )
        cout << "O maior eh --> " << integer1 << endl;

    if ( integer1 < integer2 )
        cout << "O maior eh --> " << integer2 << endl;

    if ( integer1 == integer2 )
        cout << "Estes numeros são iguais" << endl;

    return 0; //indica o fim do programa
}
