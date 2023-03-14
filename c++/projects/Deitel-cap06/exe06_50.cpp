// Exercício 6.50: ex06_50.cpp
// O que esse programa faz?
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int mystery( int, int ); // protótipo de função

int main()
{
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << "The result is " << mystery( x, y ) << endl;
    return 0; // indica terminação bem-sucedida
} // fim de main

// O parâmetro B deve ser um inteiro positivo para evitar recursão infinita
int mystery( int a, int b )
{
    if ( b == 1 ) // caso básico
        return a;
    else // passo de recursão
        return a + mystery( a, b - 1 );
} // fim da função mistery