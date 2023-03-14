// Figura 8.6: fig08_06.cpp
// Eleva uma variável ao cubo utilizando passagem por valor.
#include <iostream>
using std::cout;
using std::endl;

int cubeByValue( int ); // protótipo

int main()
{
    int number = 5;
    
    cout << "The original value of number is " << number;

    number = cubeByValue( number ); // passa number por valor ao cubeByValue
    cout << "\nThe new value of number is " << number << endl;
    return 0; // indica terminação bem-sucedida
} // fim de main

// calcula e retorna o cubo do argumento inteiro
int cubeByValue( int n )
{
    return n * n * n; // eleva a variável local n ao cubo e retorna o resultado
} // fim da função cubeByValue