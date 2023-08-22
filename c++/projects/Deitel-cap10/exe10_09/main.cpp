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
	
} // end main

