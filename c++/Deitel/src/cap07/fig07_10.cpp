// Figura 7.10: fig07_10.cpp
// Rola um dado de seis lados 6.000.000 vezes.
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include "../lib/marcusLib.h"

int main()
{
    const int arraySize = 7; // ignora o elemento zero
    int frequency[ arraySize ] = { 0 };
    int faceDie;

    srand( time( 0 ) ); // semeia o gerador de número aleatório

    // lança o dado 6.000.000 vezes; usa o valor do dado como índice de freqüência
    for ( int roll = 1; roll <= 60000000; roll++ ) {
        faceDie = gerarInteiro(1,6);
        frequency[ faceDie ]++;

    }
    
    cout << "Face" << setw( 13 ) << "Frequency" << endl;

    // gera a saída do valor de cada elemento do array
    for ( int face = 1; face < arraySize; face++ )
        cout << setw( 4 ) << face << setw( 13 ) << frequency[ face ] << endl;

    return 0; // indica terminação bem-sucedida
} // fim de main