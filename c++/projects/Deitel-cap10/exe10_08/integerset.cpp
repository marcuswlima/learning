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

bool IntegerSet::isEqual(const IntegerSet &is1,const IntegerSet &is2){
	bool resp=true;

	for ( size_t i = 0; i < is1.numeros.size(); ++i){
		if (is1.getElement(i)!=is2.getElement(i)){
			resp=false;
			break;
		}
	}

	return resp;
}

void IntegerSet::unionOfSets(const IntegerSet &is1,const IntegerSet &is2){
	for ( size_t i = 0; i < numeros.size(); ++i){
		numeros[i] = ( is1.getElement(i) || is2.getElement(i) );
	}
}

void IntegerSet::intersectionOfSets(const IntegerSet &is1,const IntegerSet &is2){
	for ( size_t i = 0; i < numeros.size(); ++i){
		numeros[i] = ( is1.getElement(i) && is2.getElement(i) );
	}
}

void IntegerSet::insertElement(const size_t e){
	numeros[e] = true;
}

void IntegerSet::deleteElement(const size_t e){
	numeros[e] = false;
}


bool IntegerSet::getElement(const size_t e)const{
	return numeros[e];
}


