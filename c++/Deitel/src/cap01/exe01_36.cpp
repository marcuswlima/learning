#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main()
{
    int sequencia;
    cout << "Informe a sequencia de 5 caracteres: ";

    cin >> sequencia;


    cout << sequencia / 10000 << "   ";
    sequencia = sequencia % 10000;

    cout << sequencia / 1000 << "   ";
    sequencia = sequencia % 1000;

    cout << sequencia / 100 << "   ";
    sequencia = sequencia % 100;

    cout << sequencia / 10 << "   ";
    sequencia = sequencia % 10;

    cout << sequencia << "   ";

    cout << endl;

    return 0;
}

