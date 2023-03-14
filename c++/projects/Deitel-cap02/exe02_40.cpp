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
    int quantidade, informado, soma=0 ;
    cout << "Quantos ? ";
    cin >> quantidade;

    for (int i=1; i<=quantidade; ++i){
        cout << i<< " um valor: ";
        cin >> informado;

        soma += informado;

    }

    cout << "A soma do(s) "<< quantidade << " números é " << soma;

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

