#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()

using std::setprecision;
using std::setiosflags;
using std::setw;

double calculateCharges (double in_horas);


int main()
{
    double t1, t2, t3, totalHoras=0, totalCalculateCharges=0, dCalculateCharges;

    cout << "Inform tempo carro 1: ";
    cin >> t1;
    cout << "Inform tempo carro 2: ";
    cin >> t2;
    cout << "Inform tempo carro 3: ";
    cin >> t3;

    cout << endl;
    cout << "Carro\tHoras\tTaxaCobrada" << setprecision(2) <<  setiosflags( ios::fixed | ios::showpoint) << endl;

    dCalculateCharges = calculateCharges(t1);
    cout << "1\t" << t1 << "\t" << dCalculateCharges << endl;

    totalHoras += t1;
    totalCalculateCharges += dCalculateCharges;

    dCalculateCharges = calculateCharges(t2);
    cout << "2\t" << t2 << "\t" << dCalculateCharges << endl;
    totalHoras += t2;
    totalCalculateCharges += dCalculateCharges;

    dCalculateCharges = calculateCharges(t3);
    cout << "3\t" << t3 << "\t"  << dCalculateCharges << endl;
    totalHoras += t3;
    totalCalculateCharges += dCalculateCharges;

    cout << "Total\t" << totalHoras << "\t" << totalCalculateCharges << endl;

//--------------------------------------------

    cout << endl << endl ;
    return 0;
}

double calculateCharges (double in_horas) {

    int    iHorasTaxaMinima=3;
    double dTaxaMinima=2, dResposta;

    if ( in_horas < 24 ) {
        if ( in_horas <= iHorasTaxaMinima ) 
            dResposta = dTaxaMinima;
        else {
            double dExcedido (in_horas - iHorasTaxaMinima);
            dResposta = dTaxaMinima + (dExcedido*0.5);
        }
    }
    else
       dResposta = 10 ;

    return dResposta;
}

