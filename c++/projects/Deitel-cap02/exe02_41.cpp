#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
//static_cast< double > ()


#include <iomanip>

using std::setprecision;
using std::setiosflags;

#include <cmath>

int main()
{
    int cein=0, soma=0, quantidade=0;
    double media;

    while (cein != 9999) {
        cout << "informe: ";
        cin >> cein;

        if (cein == 9999)
            continue;

        soma += cein;
        ++quantidade;
    }

    media = static_cast< double > (soma) / quantidade ;

    cout << "soma -> "       << soma       << endl;
    cout << "quantidade -> " << quantidade << endl; 
    cout << "media -> "      << media      << endl; 

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

