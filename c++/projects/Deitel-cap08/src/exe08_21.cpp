// Ex. 8.21: ex08_21.cpp
// O que esse programa faz?
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void mystery1( char *, const char * ); // protótipo

int main()
{
	char string1[ 80 ];
	char string2[ 80 ];

	cout << "Enter two strings: ";
	cin >> string1 >> string2;
	mystery1( string1, string2 );
	cout << string1 << endl;
return 0; // indica terminação bem-sucedida
} // fim de main

// O que essa função faz?
void mystery1( char *s1, const char *s2 )
{
	while ( *s1 != '\0' )
		++s1;

	for ( ; *s1 = *s2; s1++, s2++ )
		; // estrutura vazia
} // fim da função mystery1
