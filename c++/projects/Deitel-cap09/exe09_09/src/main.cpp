#include "DateAndTime.h"

int main(){

	DateAndTime dat1(2000,12,31,23,59,54);

	for (int i=1; i<=10; i++){
		dat1.printUniversal();
		(i%5==0 ? cout << '\n' : cout << ' ') ;
		dat1.tick();
	}
	cout << '\n';

	Date d(2000,12,31);
	Time t(23,59,54);
	DateAndTime dat2(d,t);
	
	for (int i=1; i<=10; i++){
		dat2.printUniversal();
		(i%5==0 ? cout << '\n' : cout << ' ') ;
		dat2.tick();
	}
	cout << '\n';

	return 0;
}

