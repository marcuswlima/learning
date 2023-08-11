#include "integerset.h"

#include <iostream>
#include "integerset.h"

using namespace std;

int main(){

	IntegerSet is1,is2,is3;

	is1.printSet();
	is2.printSet();
	is3.printSet();
	cout << '\n';

	is1.insertElement(1);
	is2.insertElement(2);

	is1.printSet();
	is2.printSet();
	is3.printSet();
	cout << '\n';

	is3.unionOfSets(is1,is2);

	is1.printSet();
	is2.printSet();
	is3.printSet();
	cout << '\n';
	
	return 0;
}
