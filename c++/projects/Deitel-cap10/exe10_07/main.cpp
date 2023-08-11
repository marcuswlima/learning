#include <iostream>
#include "Date.h" 
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
