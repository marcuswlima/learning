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

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()


double f_exe03_12 (double in_numero);

int main()
{
    double cein = 0;

    while (cein != -1) {

        cout << "informe: ";
        cin >> cein;

        cout <<  cein 
            << "\tf_exe03_12: " << f_exe03_12(cein) 
            << "\tround: "      << round(cein) 
            << "\tfloor: "      << floor(cein) 
            << "\tceil: "       << ceil(cein) 
            << "\ttrunc: "      << trunc(cein) 
        << endl;

    }



//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

double f_exe03_12 (double in_numero){
        return floor( in_numero + .5) ;

    }

