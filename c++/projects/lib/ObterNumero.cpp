#include "ObterNumero.h"

#include <iostream>
using std::cout;
using std::cin;

bool isNumber(string line) 
{
    return (atoi(line.c_str())); 
}

int ObterNumero(string mensagem){
    string digitado;

    do {
        cout << mensagem ; 
        cin >> digitado;
    } while (!isNumber(digitado)&&digitado!="0");

    return  stoi(digitado); 

}

int ObterNumeroNaFaixa(string mensagem, int inferior, int superior){
    int resposta;
    do {
        resposta=ObterNumero(mensagem);
    }while (resposta<inferior || resposta >superior);

    return resposta;
}
