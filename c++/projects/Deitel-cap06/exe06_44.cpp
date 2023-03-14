// Figura 6.29: fig06_29.cpp
// Testando a função fatorial recursiva.
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

int gIteração;

unsigned long factorial( unsigned long ); // protótipo de função

int main()
{
    // calcula o fatorial de 0 a 10
    for ( int counter = 0; counter <= 10; counter++ ){
        gIteração = 0;
        cout << counter << "! = " << endl << factorial( counter ) << endl;
    }

    return 0; // indica terminação bem-sucedida
} // fim de main

// definição recursiva da função fatorial
unsigned long factorial( unsigned long number )
{
    gIteração++;
    cout << gIteração ;
    for (int i=1;i<=gIteração;i++)
        cout << " ";
    cout << "entrou -> " << number << endl;
    if ( number <= 1 ) // testa caso básico
        return 1; // casos básicos: 0! = 1 e 1! = 1
    else // passo de recursão
        return number * factorial( number - 1 );
    
} // fim da função fatorial