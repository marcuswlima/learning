// Fig. 9.10: fig09_10.cpp 
// Demonstrating a default constructor for class Time.
#include <iostream>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

int main()
{
	Time t1; // all arguments defaulted
	t1.setCurrentTime();

	t1.printUniversal(); 
	cout << ' ';
	for (int i=1; i<=5000; i++){
		t1.tick();
		t1.printStandard(); 
		cout << ' ';
	}

	cout << '\n';
	return 0;

} // end main
