#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()


#include <iomanip>

using std::setprecision;
using std::setiosflags;

#include <cmath>

int main()
{
    int quantos, cein, menor=99999999;
    cout << "Quantos? ";
    cin >> quantos;

    for (int i=1; i<=quantos; ++i) {
        cout << i << " - Informe; ";
        cin >> cein;

        if ( cein < menor )
            menor = cein;
    }

    cout << "O menor valor informado é -> "<< menor;

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

