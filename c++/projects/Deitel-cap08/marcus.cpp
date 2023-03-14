#include <iostream>
using std::cout;

int main(){

	int *countPtr,count ;


	cout << "countPtr -> " <<  countPtr << "\n";
	countPtr=0;
	cout << "countPtr -> " <<  countPtr << "\n";
	countPtr=&count;
	cout << "countPtr -> " <<  countPtr << "\n";

	int y = 5;
	int *yPtr;

	yPtr = &y;
	cout << "y -> " <<  y << "\n";
	cout << "yPtr -> " <<  yPtr << "\n";
	cout << "*yPtr -> " <<  *yPtr << "\n";

	return 0;

}
