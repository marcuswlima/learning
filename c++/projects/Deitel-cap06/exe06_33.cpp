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

    double numeroGerado;
    int iQualityPoints, i0=0,i1=0,i2=0,i3=0,i4=0;

    cout << " # \t"        ;
    cout << "Número\t"     ;
    cout << "qualityPoints\t" << endl;
    for (int i=1;i<=10000;i++){
        numeroGerado = gerarDouble(1,100);
        iQualityPoints = qualityPoints(numeroGerado);

        cout << setiosflags(ios::fixed | ios::showpoint) ; 
        cout << setw(3) <<                    i              << "\t";
        cout << setw(8) << setprecision(4) << numeroGerado   << "\t";
        cout <<                               iQualityPoints << "\t";
        cout << endl;

        switch (iQualityPoints)
        {
        case 0:
            i0++;
            break;
        case 1:
            i1++;
            break;
        case 2:
            i2++;
            break;
        case 3:
            i3++;
            break;
        case 4:
            i4++;
            break;
        
        default:
            break;
        }
    }

    cout << "qualityPoints()=0 -> " << i0 << endl;
    cout << "qualityPoints()=1 -> " << i1 << endl;
    cout << "qualityPoints()=2 -> " << i2 << endl;
    cout << "qualityPoints()=3 -> " << i3 << endl;
    cout << "qualityPoints()=4 -> " << i4 << endl;

    return 0;
}

