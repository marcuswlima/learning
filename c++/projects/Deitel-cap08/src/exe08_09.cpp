#include <iostream>
using namespace std;

int main(){
	long value1=200000, value2;
	long *longPtr;
	longPtr = &value1;

	cout << "the value of the object pointed to by longPtr -> " << *longPtr << '\n';

	value2=*longPtr;

	cout << "value of value2 " << value2 << '\n';
	cout << "value of address of value1 " << &value1 << '\n';
	cout << "address stored in longPtr " << longPtr << '\n';

}

