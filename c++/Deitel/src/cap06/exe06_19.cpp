#include <iostream>
using std::cout;
using std::endl;
#include "cap06.h"

#include <iomanip>
using std::setprecision;
using std::fixed; 
using std::setw; 


double tamanhoCateto();

int main()
{
   srand( time(0) );

    cout << "Triangulo\tLado1\tLado2\tHypotenuse" << endl ;

    double cateto1,cateto2;

    for (int i=1;i<=100;i++){

        cateto1 = tamanhoCateto();
        cateto2 = tamanhoCateto();

        // configura o formato de número de ponto flutuante
        cout << fixed << setprecision( 2 );        

        cout << setw( 5 ) << i        << "\t\t";
        cout << setw( 6 ) << cateto1  << "\t";
        cout << setw( 6 ) << cateto2  << "\t";
        cout << setprecision( 4 ) << setw( 8 ) << hypotenuse(cateto1,cateto2)  ;
        //cout << setprecision(3) << fixed << "\t\t" << cateto1 << "\t" << cateto2 << "\t" << setprecision(3) << hypotenuse(cateto1,cateto2) << endl;

        cout << endl;

    }


    //double teste=hypotenuse(1,1);
    return 0;
}

double tamanhoCateto(){ 
    return gerarInteiro(0,100) + ( static_cast < double > ( gerarInteiro(0,99) ) / 100);
}
