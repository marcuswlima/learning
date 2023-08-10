// Fig. 10.12: fig10_12.cpp
// Demonstrating composition--an object with member objects.
#include <iostream>
#include "Date.h" // Employee class definition
using namespace std;

int main()
{
   Date hire( 3,  1, 1974 );

   hire.print();
   cout << '\n';
   hire.printExtenso();
   cout << '\n';
   hire.printN2();
   cout << '\n';
} // end main
