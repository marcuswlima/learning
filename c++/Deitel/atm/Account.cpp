#include <iostream>
using std::cout;
using std::endl;

#include "Account.h" 

Account::Account(int saldoInicial){

    if (saldoInicial < 0){
        cout << "o saldo inicial não pode ser negativo" << endl;
        saldo = 0;
    }
    else
        saldo = saldoInicial;

}

void Account::credit(int valor){
    saldo += valor;

}
void Account::debit(int valor) {
    if (valor > saldo)
        cout << "Debit amount exceeded account balance" << endl;
    else
        saldo -= valor;

} 
int Account::getBalance() {
    return saldo;

}