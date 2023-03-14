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

#include <cmath>

int decriptografar (int in_valor) {
    int numero = in_valor, d1,d2,d3,d4;

    d4 = (numero % 10);
    numero /= 10;
    d3 = (numero % 10);
    numero /= 10;
    d2 = (numero % 10);
    d1 = numero/10;

    return d3*1000 + d4*100 + d1*10 + d2;

}


int criptografar (int in_valor) {
    int numero = in_valor, d1,d2,d3,d4;

    d4 = (numero % 10);
    numero /= 10;
    d3 = (numero % 10);
    numero /= 10;
    d2 = (numero % 10);
    d1 = numero/10;

    return d3*1000 + d4*100 + d1*10 + d2;

}

int main()
{
    int numero, criptografado, decriptografado;

    cout << "Número: ";
    cin >> numero;

    criptografado = criptografar(numero);

    cout << "Criptografado: " << criptografado << endl;

    decriptografado = decriptografar(criptografado);

    cout << "decriptografado: " << decriptografado << endl;

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

