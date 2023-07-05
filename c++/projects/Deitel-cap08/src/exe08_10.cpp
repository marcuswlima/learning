#include <iostream>
using namespace std;

void zero(long []);
int add1AndSum(int *);

int main(){
	long numeros[1];
	zero(numeros);
	int vNumeros[]={2,3,4};
	int vNumeros2[]={3};
	cout << add1AndSum(vNumeros) << endl;
}//main

void zero(long *array){
}//zero

int add1AndSum(int oneTooSmall[]){
	int resposta=0;
	for (int i=0; i<=2; i++)
		resposta += oneTooSmall[i];
	
	return resposta;

}
