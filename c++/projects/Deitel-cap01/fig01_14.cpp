//Fig 1.14: fig01_14.cpp
// Utilizando comandos if, operadores
// relacionais e operadores lógicos
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ( )
{
    int num1, num2; //Declaração

    cout << "Digite 2 inteiros e lhe direi\n"
         << "quais os relacionamentos que eles satisfazem:";
    cin >> num1 >> num2; // le os 2 onteiores

    if ( num1 == num2 )
        cout << num1 << " é igual a " << num2 << endl;

    if ( num1 != num2 )
        cout << num1 << " não é igual a " << num2 << endl;

    if ( num1 < num2 )
        cout << num1 << " é menor que " << num2 << endl;

    if ( num1 > num2 )
        cout << num1 << " é maior que " << num2 << endl;

    if ( num1 <= num2 )
        cout << num1 << " é menor que ou igual a " << num2 << endl;


    if ( num1 >= num2 )
        cout << num1 << " é maior que ou igual a " << num2 << endl;

    return 0; //indica o fim do programa
}
