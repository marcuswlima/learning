#include <iostream>
#include "integerset.h"

using namespace std;

void imprimir(IntegerSet is1, IntegerSet is2,  IntegerSet is3){
	is1.printSet();
	is2.printSet();
	is3.printSet();
	cout << '\n';
}


int main(){

	IntegerSet is1,is2,is3;
	imprimir(is1,is2,is3);

	is1.insertElement(1);
	is2.insertElement(2);
	imprimir(is1,is2,is3);
	
	is3.unionOfSets(is1,is2);
	imprimir(is1,is2,is3);

	is1.insertElement(4);
	is2.insertElement(4);
	is3.intersectionOfSets(is1,is2);
	imprimir(is1,is2,is3);

	bool bul = IntegerSet::isEqual(is1,is2);
	cout << bul << '\n';


	return 0;
}
