#include <iostream>
#include "integerset.h"

using namespace std;

//-------------------------------------
// construtores
//-------------------------------------
IntegerSet::IntegerSet(){
	for (int i; i <= INITIAL_SIZE-1; i++){
		numeros.push_back(false);
	}
}

//-------------------------------------
// publics
//-------------------------------------
void IntegerSet::printSet()const{
	for ( size_t i = 0; i < numeros.size(); ++i){
		cout << '[' << i << ']' << numeros[i] << ' ';
	}
	cout << '\n';
}

void IntegerSet::unionOfSets(IntegerSet is1,IntegerSet is2){
	for ( size_t i = 0; i < numeros.size(); ++i){
		numeros[i] = is1.getElement(i) || is2.getElement(i);
	}
}

void IntegerSet::insertElement(const int e){
	numeros[e]=true;
}

void IntegerSet::deleteElement(const int e){
	numeros[e] = false;
}


bool IntegerSet::getElement(const size_t e)const{
	return numeros[e];
}


