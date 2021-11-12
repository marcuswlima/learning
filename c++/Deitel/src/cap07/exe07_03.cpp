#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;
using std::fixed;

#include <iomanip>
using std::setprecision;



void mostarArrayDouble( const double array[], int sizeOfArray );

int main(){
    srand( time(0) );


    //a)
    const int arraSize=10;

    //b)
    double arrei [arraSize] = {0.0};

    for (int i=0; i<arraSize; i++)
        arrei[i]=gerarDouble(0,100);

    //e)
    arrei[9]=1.667;

    //f)
    arrei[6]=3.333;

    //g)
    cout << "*** g) *****\n";
    cout << fixed << setprecision(4);
    cout << "[6]=" << arrei[6] << "\n"; 
    cout << "[9]=" << arrei[9] << "\n"; 

    //h)
    cout << "*** h) *****\n";
    for (int i=0; i<arraSize; i++)
        cout << "[" << i << "]=" << arrei[i] << " ";
    cout << "\n"; 

}


void mostarArrayDouble( const double array[], int sizeOfArray ){

    for (int i=0;i<sizeOfArray;i++)
        cout << "[" << i << "]=" << array[i] << " ";

    cout << "\n";

}