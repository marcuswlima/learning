#include <string> 
using std::string;

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "Employee.h"

Employee::Employee(string nome, string sobrenome, int salarioMensal){
    setNome(nome);
    setSobreNome(sobrenome);
    setsalarioMensal(salarioMensal);
}

void Employee::setNome(string in_nome){
    nome = in_nome;
}

string Employee::getNome(){
    return nome;
}

void Employee::setSobreNome(string in_sobrenome){
    sobreNome = in_sobrenome;
}

string Employee::getSobreNome(){
    return sobreNome;
}

void Employee::setsalarioMensal(int in_salarioMensal){
    salarioMensal = in_salarioMensal;
}

int Employee::getSalarioMensal(){
    return salarioMensal;
}

void Employee::showEmployee() {
    cout << getSobreNome() << ", " << getNome() << " que ganha " << getSalarioMensal() << endl;
}