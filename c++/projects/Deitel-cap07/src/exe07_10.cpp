#include "../../lib/Mathematics.h"
#include "../../lib/PrintArray.h"

int main(){
	srand( time(0) );

	//Gerando as vendas
	const int tamanhoVendas=100;
	int vendas[tamanhoVendas];
	for (int i=0; i<tamanhoVendas; i++){
		vendas[i]=GerarInteiro(1,1099);
	}
	PrintVector(vendas,tamanhoVendas,"Vendas");

	const int tamanhoFaixas=11;
	int faixas[tamanhoFaixas]={0}
		,subscrito;

	

	for (int i=0; i<tamanhoVendas; i++){
		subscrito=vendas[i]/100;
		if (subscrito>10)
			subscrito = 10;

		faixas[subscrito]++;
	}

	PrintVector(faixas,tamanhoFaixas,"Faixas");

	cout << "\n";

	cout << "Inicio\tFim\tQuant\tGráfico\n";
	for (int i=0; i<tamanhoFaixas; i++){
		cout << "$" << i*100    << "\t";
		cout << "$" << i*100+99 << "\t";
		cout << faixas[i]       << "\t";

		for (int g=1; g<=faixas[i]; g++)
			cout << "*";

		cout << "\n";
	}

}
