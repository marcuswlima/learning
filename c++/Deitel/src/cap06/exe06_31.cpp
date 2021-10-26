#include <iostream>
using std::cout;
using std::endl;

#include "cap06.h"

#include <iomanip>
using std::setw;


int main(){

    srand( time(0) );

    int x;

    for (int i=1; i<=100; i++){

        x = gerarInteiro(0,99999);

        cout << setw(3) << i << "\t";
        cout << setw(5) << x << "\t";
        separarAndInverter(x);
        cout << endl;

    }
    return 0;
}