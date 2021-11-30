#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

#include <iomanip>
using std::setw;

#include <vector>
using std::vector;


int main(){
    srand( time(0) );

    const int tamanhoFaixas=11
             ,tamanhoVendas=10;

    int faixas[tamanhoFaixas]={0}
       ,vendas[tamanhoVendas]
       ,subscrito;

    for (int i=0; i<tamanhoVendas; i++)
        vendas[i]=gerarInteiro(1,1099);

    mostarArray(vendas,tamanhoVendas,"Vendas");

    for (int i=0; i<tamanhoVendas; i++){
        subscrito=vendas[i]/100;
        if (subscrito>10)
            subscrito = 10;
        
        faixas[subscrito]++;
    }

    mostarArray(faixas,tamanhoFaixas,"Faixas");

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