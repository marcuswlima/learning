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

int fatorial (int in_fatoriante){
    int resposta = 1;
    for (int i=in_fatoriante; i>0; --i) 
        resposta *= i;

    return resposta;
}

int main()
{
    int numero, fatorado ;
    double eMat=1;
    cout << "Número: ";
    cin >> numero;

    fatorado = fatorial(numero);

    cout << "fatorado -> " << fatorado << endl;

    for (int i; i<= numero; ++i)
        eMat += 1/fatorial(i);

    cout << "eMat -> " << eMat;

//--------------------------------------------


    cout << endl << endl ;
    return 0;
}

