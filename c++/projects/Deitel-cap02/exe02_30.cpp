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

int main()
{
    int binario, resto=1, qdtDigitos = -1, decimal=0;


    cout << "Informe o número binário: ";
    cin >> binario;

    cout << "\n";

    while ( binario > 0 ) {
        resto = binario % 10; 
        binario = binario / 10;
        qdtDigitos++;

        //cout << "binario -> "<< binario << endl;
        cout << "digito -> "<< resto << "\t";
        cout << "qdtDigitos -> "<< qdtDigitos << "\t";
        cout << "Potencias -> "<< pow(2,qdtDigitos) << "\t";
        cout << endl  ;

        decimal = decimal + ( resto * pow(2,qdtDigitos) );
    }

    cout << endl << "decimal -> "<< decimal << "\n\n";

//------------------------------
    cout << endl << endl ;
    return 0;
}

