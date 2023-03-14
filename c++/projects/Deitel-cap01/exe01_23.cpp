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

    cout << "A soma é "      << integer1 + integer2 << endl; //imprime a soma
    cout << "A diferença e " << integer1 - integer2 << endl;
    cout << "O produto é "   << integer1 * integer2 << endl;
    cout << "O quociente é " << integer1 / integer2 << endl;

    return 0; //indica o fim do programa
}
