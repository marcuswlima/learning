#include "Date.h"

int main(){
	Date d(2003,10,28);
	for (int i=1; i<=150; i++){

		d.print();
		cout << ' ';
		d.nextDay();
	}

	cout << '\n';
	return 0;
}
