#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int SIZE=10;
	double numbers[ SIZE ] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	double *nPtr;

	cout << fixed << showpoint << setprecision(1);

	for ( int i=0; i<SIZE; ++i)
		cout << numbers[i] << ' '; //array subcription
	cout << '\n';
	
	nPtr = numbers;
	cout << nPtr << '\n';
	nPtr = &numbers[0];
	cout << nPtr << '\n';

	for ( int i=0; i<SIZE; ++i)
		cout << *(nPtr + i) << ' '; //pointer offset with pointer
	cout << '\n';

	for ( int i=0; i<SIZE; ++i)
		cout << *(numbers + i) << ' '; //pointer offset with array name
	cout << '\n';
	
	for ( int i=0; i<SIZE; ++i)
		cout << nPtr[i] << ' '; //pointer subcript
	cout << '\n';

	cout << numbers[3] << " numbers[3] - array subscription\n";
	cout << *(numbers + 3) << " *(numbers + 3) - offset with array name as pointer\n";
	cout << nPtr[3] << " nPrt[3] - pointer subscription\n";
	cout << *(nPtr + 3) << " *(nPrt + 3) - offset with pointer\n";
}//main
