#include "cap06.h"
#include "manimum.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ios;
#include <iomanip>
using std::setw;
using std::setiosflags;
using std::setprecision;

#include <sstream>



int main(){ 

    srand( time(0) );


    //inteiro
    int int1, int2 ;
    cout << "i\tint1\tint2\tmin" << endl;
    for (int i=1;i<=10;i++){
        int1 = gerarInteiro(1,10);
        int2 = gerarInteiro(1,10);

        cout << setw(2) << i              << "\t";
        cout << setw(2) << int1           << "\t";
        cout << setw(2) << int2           << "\t";
        cout << setw(2) << min(int1,int2) << "\t";

        cout << endl;
    }
    cout << endl;

    //double
    double double1, double2;
    cout << "i\tdouble1\tdouble2\tmin" << endl;
    for (int i=1;i<=10;i++){
        double1 = gerarDouble(1,10);
        double2 = gerarDouble(1,10);


        cout << setiosflags(ios::fixed | ios::showpoint) ; 
        cout << setw(2) << i                    << "\t";
        cout << setw(7) << setprecision(4) << double1              << "\t";
        cout << setw(7) << setprecision(4) << double2              << "\t";
        cout << setw(7) << setprecision(4) << min(double1,double2) << "\t";


        cout << endl;

    }
    cout << endl;

    //char
    char char1, char2;
    cout << "i\tchar1\tchar2\tmin" << endl;
    for (int i=1;i<=10;i++){
        int1 = gerarInteiro(1,10);
        int2 = gerarInteiro(1,10);

        cout << setw(2) << i                    << "\t";


        cout << endl;
    }
}
