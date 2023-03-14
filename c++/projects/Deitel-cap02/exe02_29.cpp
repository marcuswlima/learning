#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )


#include <iomanip>

using std::setprecision;
using std::setiosflags;

int main()
{
    int numero, n1,n2, n3, n4, n5;

    cout << "Informe um número de 5 dígitos ";
    cin >> numero;

    n1 = numero / 10000 ;
    numero = numero - (n1 * 10000);

    n2 = numero / 1000;
    numero = numero - (n2 * 1000);

    n3 = numero / 100;
    numero = numero - (n3 * 100);

    n4 = numero / 10;
    numero = numero - (n4 * 10);

    n5 = numero;

    if ( n1 == n5 && n2 == n4)
        cout << "Polindromo" << endl;
    else
        cout << "Ñ Polindromo" << endl;


    cout << endl << endl ;
    return 0;
}

