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
    double amount, 
           principal = 1000,
           rate = .05;
    
    for (int i=5; i<=10; ++i) {
        cout << "Taxa em "<< i << "%" << endl;

        cout << "Ano" << setw(21)
            << "Quantia em depósito" << endl;

        cout << setiosflags( ios::fixed | ios::showpoint)
            << setprecision( 2 ); 

        amount = 0;
        rate = static_cast< double > (i) / 100;
        for (int year=1; year <= 10; year++) {
            amount = principal * pow( 1.0 + rate, year );
            cout << setw( 4 ) << year << setw (21) << amount << endl; 
        }
    }


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

