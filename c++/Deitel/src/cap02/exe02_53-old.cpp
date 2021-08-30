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
using std::setw;

#include <cmath>

int main()
{
    cout << "Decimal\tBinário\tOctal\tHexadecimal" << endl;

    int decimal=57,base=2,posicao,expoente = 0;

    while ( decimal > pow(base,expoente) ) {
        ++expoente;
    }
    --expoente;

    cout << endl << endl ;

    //----------------------------------------------------------------

    int resto, potencia;

    cout << "decimal -> " << decimal << "\n\n" ;

    cout << "expoente -> " << expoente << endl ; 
    potencia = pow(base,expoente);
    cout << "potencia -> " << potencia << endl ; 
    resto = decimal % potencia;
    cout << "resto -> " << resto << endl ; 

    if ( resto >= 0 )
        cout << "Binário 1";
    else
        cout << "Binário 0";

    -- expoente ; 
    cout << endl ; 
    //----------------------------------------------------------------

    cout << endl ;
    decimal = resto;
    cout << "expoente -> " << expoente << endl ; 
    potencia = pow(base,expoente);
    cout << "potencia -> " << potencia << endl ; 
    resto = decimal % potencia;
    cout << "resto -> " << resto << endl ; 

    if ( resto >= 0 )
        cout << "Binário 1";
    else
        cout << "Binário 0";

    -- expoente ; 
    cout << endl ; 

    cout << endl ;
    decimal = resto;
    cout << "expoente -> " << expoente << endl ; 
    potencia = pow(base,expoente);
    cout << "potencia -> " << potencia << endl ; 
    resto = decimal % potencia;
    cout << "resto -> " << resto << endl ; 

    if ( resto >= 0 )
        cout << "Binário 1";
    else
        cout << "Binário 0";

    -- expoente ; 
    cout << endl ; 

    cout << endl ;
    decimal = resto;
    cout << "expoente -> " << expoente << endl ; 
    potencia = pow(base,expoente);
    cout << "potencia -> " << potencia << endl ; 

    resto = decimal % potencia;
    cout << "resto -> " << resto << endl ; 

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

