// Figura 8.7: fig08_07.cpp
// Eleva uma variável ao cubo usando passagem por referência com um argumento nPtr.
#include <iostream>
using std::cout;
using std::endl;

void cubeByReference( int * ); // protótipo

int main()
{
	int number = 5;

	cout << "The original value of number is " << number;

	cubeByReference( &number ); // passa endereço de number para cubeByReference

	cout << "\nThe new value of number is " << number << endl;
} // fim de main

// calcula o cubo de *nPtr; modifica a variável number em main
void cubeByReference( int *nPtr )
{
	*nPtr = *nPtr * *nPtr * *nPtr; // eleva *nPtr ao cubo
} // fim da função cubeByReference
  
