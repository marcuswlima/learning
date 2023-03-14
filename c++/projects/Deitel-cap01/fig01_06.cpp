//Fig 1.6: fig01_06.cpp
// Programa de Adição
#include <iostream>

int main ( )
{
    int integer1, integer2, sum; //Declaração

    std::cout << "Digite o primeiro numero inteiro\n"; //prompt
    std::cin >> integer1;
    std::cout << "Digite o segundo numero inteiro\n"; //prompt
    std::cin >> integer2;
    sum = integer1 + integer2; //atribuição a soma
    std::cout << "A soma é " << sum << "\n"; //imprime a soma

    return 0; //indica o fim do programa
}
