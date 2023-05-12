#include "../../lib/BarraTitulo.h"
#include "../../lib/Mathematics.h"
void outputVector(vector<int> array);
int main(){
	ImprimirTitulo("exe07_40");

	const int tamanhoVector=10;
	vector< int > numeros(tamanhoVector);

	for(int i=0; i <= numeros.size(); ++i){
		numeros[ i ] = GerarInteiro(1,100);
	}

	outputVector(numeros);
}

void outputVector(vector<int> array){
	size_t i;

//	for (i=0; i < array.size(); ++i){
//		cout << "[" << i << "]=" << array[i] << " ";
//	}

	cout << endl;

}


