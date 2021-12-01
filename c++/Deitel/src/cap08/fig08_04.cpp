// Figura 8.4: fig08_04.cpp
// Utilizando os operadores & e *.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int a; // a é um inteiro
    int *aPtr; // aPtr é um ponteiro int * -- para um inteiro

    a = 7; // atribuiu 7 a a
    aPtr = &a; // atribui o endereço de a ao aPtr

    cout << "The address of a is " << &a
         << "\nThe value of aPtr is " << aPtr;
    cout << "\n\nThe value of a is " << a
         << "\nThe value of *aPtr is " << *aPtr;
    cout << "\n\nShowing that * and & are inverses of "
         << "each other.\n&*aPtr = " << &*aPtr
         << "\n*&aPtr = " << *&aPtr << endl;

    int b; // a é um inteiro
    b=99;
    int *bPtr; // aPtr é um ponteiro int * -- para um inteiro
    bPtr = &b;

    cout << "&b -> "    <<  &b    << "\n";
    cout << "bPtr -> "  <<  bPtr  << "\n";
    cout << "*bPtr -> " <<  *bPtr << "\n";

    int c, d;
    cout << "&c -> "    <<  &c    << "\n";
    cout << "&d -> "    <<  &d    << "\n";

    return 0; // indica terminação bem-sucedida


 } // fim de main