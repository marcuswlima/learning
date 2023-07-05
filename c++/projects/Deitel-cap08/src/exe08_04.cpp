#include <iostream>
using namespace std;

int main(){
	double number1=7.3;
	double number2;
	char *prt;

	double *fPtr;

	fPtr = &number1;

	cout << "*fPtr->" << *fPtr << endl;

	number2 = *fPtr;
	cout << "number2->" << number2 << endl;
	cout << "address number1->" << &number1 << endl;
	cout << "fPtr->" << fPtr << endl;
}//main

