#include <iostream>
#include "Date.h" 
using namespace std;

int main()
{
   Date hire( 1,  9, 1980 );
/*
   hire.print();
   cout << '\n';
   hire.printExtenso();
   cout << '\n';
   hire.printN2();
   cout << '\n';

   hire.nextDay();
   hire.printExtenso();
   cout << '\n';
*/
   Date data;
   data.print();
   cout << '\n';
   data.setCurrentDate();
   data.print();
   cout << '\n';

} // end main
