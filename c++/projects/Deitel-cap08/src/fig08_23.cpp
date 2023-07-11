#include <iostream>
using namespace std;
int main(){
	int number;
	cout << number << endl;


	double *realPtr;
	long *integerPtr;
//	integerPtr = *static_cast< long *>(realPtr);
//
	void *sPtr = 0;
	number = *static_cast< int * >( sPtr );
}
