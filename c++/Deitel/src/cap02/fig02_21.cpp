//Fig 2.21: fig02_21.cpp
//Calculando Juros compostos
#include <iostream>

using std::cout;
using std::endl;
using std::ios;

#include <iomanip>

using std::setw;
using std::setiosflags;
using std::setprecision;

#include <cmath>

int main ( )
{
    double amount,
           principal = 1000.0,
           rate = .05;

    cout << setw( 4 ) << "Ano" << setw( 21 ) 
         << "Quantia em depósito" << endl;

    // ajustar o formato de numeros em ponto flutuante
    cout << setiosflags( ios::fixed | ios::showpoint )
         << setprecision(2);

    for ( int year = 1; year <= 10 ; year++){
      amount = principal * pow (1.0 + rate, year);
      cout << setw( 4 ) << year << setw( 21 ) << amount << endl;    
    }
    
    return 0; //indica o fim do programa
}
