
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

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()

int main()
{

    int n1 ;
    srand( time(0) );

    for (int i=1;i<=1000;i++){ 

        n1 = gerarInteiro(1,1000);

        cout << n1 << " " ;
        
        if (multiple(n1,2))
            cout << "true | ";
        else 
            cout << "false | ";

    }

        cout << endl;  


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

