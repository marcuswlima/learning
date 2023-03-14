#include <iostream>

using std::cout;
using std::endl;

#include "PrintArray.h"

void PrintVector( const double arrei[], int sizeOfArray, string titulo ){

    if (titulo!="titulo")
        cout << titulo << "\n";

    for (int i=0;i<sizeOfArray;i++)
        cout << "[" << i << "]=" << arrei[i] << " ";

    cout << endl;
    cout << endl;

}

void PrintVector( const int arrei[], int sizeOfArray, string titulo ){

    if (titulo!="titulo")
        cout << titulo << "\n";

    for (int i=0;i<sizeOfArray;i++)
        cout << "[" << i << "]=" << arrei[i] << " ";

    cout << endl;
    cout << endl;

}
