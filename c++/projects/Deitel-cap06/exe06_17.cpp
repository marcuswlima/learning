#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "cap06.h"

int main()
{
    int garado;
    srand( time(0) );

    garado = gerarInteiro(1,5) ; 
    //cout << garado << endl;

    cout << garado << endl;
    cout << garado*2 << endl;
    cout << (garado*2)+1 << endl;
    cout << ((garado*2)+1)*2 << endl;

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}
