#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

#include <iomanip>
using std::setw;

int main(){
    srand( time(0) );

    const int tamanhoFaixas=11;
    const int tamanhoVendas=1;
    int faixas[tamanhoFaixas]={0};
    int vendas[tamanhoVendas];
    int subscrito;

    for (int i=0; i<tamanhoVendas; i++)
        vendas[i]=gerarInteiro(1,1099);

    cout << "Vendas\n";
    mostarArray(vendas,tamanhoVendas);

    for (int i=0; i<tamanhoVendas; i++){
        subscrito=vendas[i]/100;
        if (subscrito>10)
            subscrito = 10;
        
        faixas[subscrito]++;
    }

    mostarArray(faixas,tamanhoFaixas);

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