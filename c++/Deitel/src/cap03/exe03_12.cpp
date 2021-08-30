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
    double t1, t2, t3, totalHoras=0, totalTaxa=0, totalCalculateCharges=0;

    cout << "Inform tempo carro 1: ";
    cin >> t1;
    cout << "Inform tempo carro 2: ";
    cin >> t2;
    cout << "Inform tempo carro 3: ";
    cin >> t3;

    cout << endl;
    cout << "Carro\tHoras\tTaxa Cobrada" << endl;

    // carro 1
    {
        totalHoras += t1;
        totalCalculateCharges += calculateCharges(t1);
        //cout << "1\t" << t1 << "\t" << calculateCharges(t1) << endl ;

    }
    // carro 2
    {
        totalHoras += t2;
        totalCalculateCharges += calculateCharges(t2);
        //cout << "2\t" << t2 << "\t" << calculateCharges(t2) << endl ;

    }

    // carro 3
    {
        totalHoras += t3;
        totalCalculateCharges += calculateCharges(t3);
        //cout << "3\t" << t3 << "\t" << calculateCharges(t3) << endl ;

    }

    // Total
    //cout << "Total\t" << totalHoras << "\t" << totalCalculateCharges << endl ;
//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

double calculateCharges (double in_horas) {

    int    iHorasTaxaMinima=3;
    double dTaxaMinima=2, dResposta;

    cout << "in_horas -> " << in_horas << "\t";

    if ( in_horas <= iHorasTaxaMinima ) 
        dResposta = dTaxaMinima;
    else {
        double dExcedido (in_horas - iHorasTaxaMinima);
        cout <<  "dExcedido -> " << dExcedido << "\t";
        dResposta = dTaxaMinima + (dExcedido*0.5);
    }

    cout << "dResposta -> " << dResposta ;

    cout << endl ;
    return dResposta;
}

