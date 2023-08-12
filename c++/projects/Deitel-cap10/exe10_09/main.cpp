#include <iostream>
#include "Time.h" // Time class definition
using namespace std;

void imprimir(const Time t1, const Time t2, const Time t3){
	t1.printUniversal();
	cout << '\t';
	t2.printUniversal();
	cout << '\t';
	t3.printUniversal();
	cout << '\n';
}


int main()
{
	Time t0, t1(2), t3(23,59,59);
	imprimir(t0,t1,t3);
	t0.tick();
	t1.tick();
	t3.tick();
	imprimir(t0,t1,t3);
	t0.setCurrentTime();
	imprimir(t0,t1,t3);
	

	
	
	/*
 	Time t; // create Time object

   // cascaded function calls
   t.setHour( 18 ).setMinute( 30 ).setSecond( 22 );

   // output time in universal and standard formats
   cout << "Universal time: ";
   t.printUniversal();

   cout << "\nStandard time: ";
   t.printStandard();

   cout << "\n\nNew standard time: ";

   // cascaded function calls
   t.setTime( 20, 20, 20 ).printStandard();
   cout << endl;

   Time t1((23*3600) + (60*59) + 59);
   Time t2((5*60)+1113);
*/
} // end main

