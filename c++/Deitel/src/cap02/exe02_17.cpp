#include <iostream>

using std::cout; 
using std::cin; 
using std::endl;


int main () {
    int numeroConta=0;
    double saldoinicial,debitos, creditos, limite, saldofinal;

    while ( numeroConta != -1 ) {

        cout << "Digite o número da conta (-1 para encerrar)..: ";
        cin  >> numeroConta ;

        if ( numeroConta == -1 )
            continue;

        cout << "Saldo inicial...: ";
        cin  >> saldoinicial;
        cout << "debitos totais..: ";
        cin  >> debitos;
        cout << "creditos totais.: ";
        cin  >> creditos;
        cout << "limite..........: ";
        cin  >> limite;

        saldofinal = saldoinicial + debitos - creditos;

        if ( saldofinal > limite ) {
            cout << "Conta: "                    << numeroConta << endl;
            cout << "Limite de crédito: "        << limite      << endl;
            cout << "Saldo: "                    << saldofinal  << endl;
            cout << "Limite de crédito excedido"                << endl;

        }

        cout << endl;
    }



    return 0;
}