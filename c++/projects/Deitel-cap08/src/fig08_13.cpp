// Fig. 8.13: fig08_13.cpp
// Selection sort with pass-by-reference. This program puts values into an
// array, sorts them into ascending order and prints the resulting array.
#include <iostream>
#include <iomanip>
using namespace std;

void selectionSort( int * const, const int ); // prototype
void swap( int * const, int * const ); // prototype
void selectionSort2( int [], const int ); // prototype

int main()
{
    const int arraySize = 10;
    int a[ arraySize ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    cout << "Data items in original order\n";

    for ( int i = 0; i < arraySize; ++i )
        cout << setw( 4 ) << a[ i ];

    selectionSort( a, arraySize ); // sort the array

    cout << "\nData items in ascending order\n";

    for ( int j = 0; j < arraySize; ++j )
        cout << setw( 4 ) << a[ j ];

    cout << endl;
} // end main

// function to sort an array
void selectionSort( int * const array, const int size ) // (Const Pointer to Nonconst data, - )
{
    int smallest; // index of smallest element

    // loop over size - 1 elements
    for ( int i = 0; i < size - 1; ++i )
    {
        smallest = i; // first index of remaining array

        // loop to find index of smallest element
        for ( int index = i + 1; index < size; ++index )

            if ( array[ index ] < array[ smallest ] )
                smallest = index;

        swap( &array[ i ], &array[ smallest ] );
    } // end if
} // end function selectionSort

// swap values at memory locations to which
// element1Ptr and element2Ptr point
void swap( int * const element1Ptr, int * const element2Ptr ) // (Const pointer to nocost data, const pointer to noconst data)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
} // end function swap
