#include "../../lib/Mathematics.h"
#include "../../lib/BarraTitulo.h"
#include "../../lib/PrintArray.h"

void outputVector(vector<int> array);

int main(){
    srand( time(0) );

    const int tamanhoSomas=13;
    int somas[tamanhoSomas]={0}, tabela[7][7]={0}, dado1, dado2;
	vector<int> vSomas(tamanhoSomas);


    for (int i=1;i<=36000;i++){
        dado1 = GerarInteiro(1,6);
        dado2 = GerarInteiro(1,6);
        somas[dado1+dado2]++;
        tabela[dado1][dado2]++;
		vSomas[dado1+dado2]++;
    }

	PrintVector(somas,tamanhoSomas,"Somas");
    

    for ( int linha = 1; linha < 7; linha++ ) {
        for ( int coluna = 1; coluna < 7; coluna++ ){
            cout << "[" << linha << "," << coluna << "]="  << setw(4) << tabela[ linha ][ coluna ] << " ";
		}

        cout << "\n";
    }

	ImprimirTitulo("outputVector");
	outputVector(vSomas);
}

void outputVector(vector<int> array){
	size_t i;

	for (i=2; i < array.size(); ++i){
		cout << "[" << i << "]=" << array[i] << " ";
	}

	cout << endl;

}

