// Fig. 8.12: fig08_12.cpp
// Attempting to modify a constant pointer to constant data.
#include <iostream>
using namespace std;

int main()
{
	int x = 5, y;

	// ptr is a constant pointer to a constant integer.
	// ptr always points to the same location; the integer
	// at that location cannot be modified.
	const int *const ptr = &x;

	cout << *ptr << endl;

	*ptr = 7; // error: *ptr is const; cannot assign new value
	ptr = &y; // error: ptr is const; cannot assign new address
} // end main

