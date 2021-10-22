#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;

#include <cmath>

using std::ios;

#include "cap06.h"

int main()
{
    int n1, n2 ;
    srand( time(0) );

    cout << "N1\tN2\tResultado" << endl ;

    for (int i=1;i<=20;i++){ 

        n1 = gerarInteiro(1,10);
        n2 = gerarInteiro(1,10);

        cout << setw( 2 ) << n1 << "\t";//<< " " << n2 << " " << multiple(n1,n2) << endl;
        cout << setw( 2 ) << n2 << "\t";
        cout << setw( 2 ) << multiple(n1,n2) << "\t";
        cout << endl;
    }


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

