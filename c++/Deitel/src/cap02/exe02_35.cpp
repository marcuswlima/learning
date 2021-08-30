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
    double lado1, lado2, lado3;
    cout << "lado1 : ";
    cin >> lado1;

    cout << "lado2 : ";
    cin >> lado2;

    cout << "lado3 : ";
    cin >> lado3;

    if ( lado1 < (lado2 + lado3) &&  lado2 < (lado1 + lado3) && lado3 < (lado1 + lado2) )
        cout << "Sim";
    else
        cout << "Não";



//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

