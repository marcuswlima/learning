// Figura 8.15: fig08_15.cpp
// Este programa coloca valores em um array, classifica os valores em
// ordem crescente e imprime o array resultante.
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

void selectionSort( int * const, const int ); // protótipo
void swap( int * const, int * const ); // protótipo

int main()
{
    const int arraySize = 10;
    int a[ arraySize ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    cout << "Data items in original order\n";

    for ( int i = 0; i < arraySize; i++ )
        cout << setw( 4 ) << a[ i ];

    selectionSort( a, arraySize ); // classifica o array

    cout << "\nData items in ascending order\n";

    for ( int j = 0; j < arraySize; j++ )
        cout << setw( 4 ) << a[ j ];

    cout << endl;
    return 0; // indica terminação bem-sucedida
} // fim de main

// função para classificar um array
void selectionSort( int * const array, const int size )
{
    int smallest; // índice do menor elemento

    // itera sobre size - 1 elementos
    for ( int i = 0; i < size - 1; i++ )
    {
        smallest = i; // primeiro índice do array remanescente

        // faz um loop para localizar o índice do menor elemento
        for ( int index = i + 1; index < size; index++ )

            if ( array[ index ] < array[ smallest ] )
                smallest = index;

        swap( &array[ i ], &array[ smallest ] );
    } // fim do for
} // fim da função selectionSort

// troca os valores nas posições da memória para as quais
// element1Ptr e element2Ptr apontem
void swap( int * const element1Ptr, int * const element2Ptr )
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
} // fim da função swap