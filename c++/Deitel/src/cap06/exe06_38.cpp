#include "cap06.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void adivinhar(int aleatorio);

int main(){

    int aleatorio=gerarInteiro(1,100);

    cout << aleatorio << endl;

    adivinhar(aleatorio);

    return 0;

}

void adivinhar(int aleatorio){
    int resposta;
    cout << "Informe o número: ";
    cin >> resposta ; 

    if (resposta==aleatorio){
        cout << "Parabéns!!!" << endl;
    }
    else{
        if (resposta < aleatorio)
            cout << "baixo";
        else
            cout << "alto";

        cout << ", tente Novamente" << endl;

        adivinhar(aleatorio);
    }


}

