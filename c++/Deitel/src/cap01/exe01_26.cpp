//Fig 1.14: fig01_14.cpp
// Utilizando comandos if, operadores
// relacionais e operadores lógicos
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ( )
{
    int num1, num2, num3; //Declaração

    cout << "Digite o primeiro numero : ";
    cin >> num1 ; // le os 2 onteiores

    cout << "Digite o segundo numero  : ";
    cin >> num2 ; // le os 2 onteiores

    cout << "Digite o terceiro numero : ";
    cin >> num3 ; // le os 2 onteiores

    cout << "A soma é    : " << (num1 + num2 + num3)      << endl;
    cout << "A media é   : " << (num1 + num2 + num3) / 3  << endl;
    cout << "O produto é : " << (num1 * num2 * num3)      << endl;

    if ( num1 > num2 )
        if (num1 > num3)
            cout << "O maior é   : " << (num1) << endl;

    if ( num2 > num1 )
        if (num2 > num3)
            cout << "O maior é   : " << (num2) << endl;

    if ( num3 > num1 )
        if (num3 > num2)
            cout << "O maior é   : " << (num3) << endl;

    if ( num1 < num2 )
        if (num1 < num3)
            cout << "O menor é   : " << (num1) << endl;

    if ( num2 < num1 )
        if (num2 < num3)
            cout << "O menor é   : " << (num2) << endl;

    if ( num3 < num1 )
        if (num3 < num2)
            cout << "O menor é   : " << (num3) << endl;


    return 0; //indica o fim do programa
}
