#include "DateAndTime.h"

int main(){

	DateAndTime dat(2000,12,31,23,59,54);

	for (int i=1; i<=10; i++){
		dat.printUniversal();
		(i%5==0 ? cout << '\n' : cout << ' ') ;
		dat.tick();
	}

	cout << '\n';
	return 0;
}

