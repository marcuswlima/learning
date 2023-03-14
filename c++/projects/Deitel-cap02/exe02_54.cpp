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
    double pi=0;
    int iteracao=1;

    cout << "0" << endl;
    for (int i=1; i<=200; i+=2) {
        cout << i << "\t";


        if ((iteracao%2) ==0 ) { // iteração par
            pi -= static_cast< double > (4) /i;
            cout << "-" ;

        }
        else {  // iteração impar
            pi += static_cast< double > (4) /i;
            cout << "+" ;
        }

        cout << "4/"<< i ;


        cout << "\t" << pi;
        cout << endl;

        ++iteracao;
    }


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

