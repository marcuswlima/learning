#include "cap06.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ios;
#include <iomanip>
using std::setw;
using std::setiosflags;
using std::setprecision;

int main(){

    srand( time(0) );

    double d1, d2, d3;

    d1 = gerarDouble(1,100);
    d2 = gerarDouble(1,100);
    d3 = gerarDouble(1,100);

    cout << setiosflags(ios::fixed | ios::showpoint) ; 
    cout << setw(8) << setprecision(4) << d1                 << endl;
    cout << setw(8) << setprecision(4) << d2                 << endl;
    cout << setw(8) << setprecision(4) << d3                 << endl;
    cout << setw(8) << setprecision(4) << menorDe3(d1,d2,d3) << endl;

    return 0;
}
