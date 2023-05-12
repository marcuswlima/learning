#include "../../lib/BarraTitulo.h"
#include "../../lib/Mathematics.h"
int main(){
	ImprimirTitulo("exe07_37");

	const int tamanhoVector=10;
	vector< int > numeros(tamanhoVector);

	for(int i=1; i <= numeros.size(); i++){
		numeros[ i ] = GerarInteiro(1,100);
	}
}

