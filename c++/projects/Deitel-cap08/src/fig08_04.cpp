// Figura 8.4: fig08_04.cpp
// Utilizando os operadores & e *.
//#include <iostream>
//using std::cout;
//#using std::endl;

#include "../../lib/ConsolidatorSystemLib.h"

int main()
{
    int a; // a é um inteiro
    int *aPtr; // aPtr é um ponteiro int * -- para um inteiro

    a = 7; // atribuiu 7 a a
    aPtr = &a; // atribui o endereço de a ao aPtr

    cout << "The address of a is  " << &a
         << "\nThe value of aPtr is " << aPtr;
    cout << "\n\nThe value of a is " << a
         << "\nThe value of *aPtr is " << *aPtr;
    cout << "\n\nShowing that * and & are inverses of each other."
         << "\n&*aPtr = " << &*aPtr
         << "\n*&aPtr = " << *&aPtr << endl;

     cout << "****************************************\n";
     cout << "a      -> "  << a      << "\n"; // valor da variavel
     cout << "&a     -> "  << &a     << "\n";
     cout << "aPtr   -> "  << aPtr   << "\n"; // valor da variavel
     cout << "*aPtr  -> "  << *aPtr  << "\n";
     cout << "&aPtr  -> "  << &aPtr  << "\n"; // valor da variavel
     cout << "*&aPtr -> "  << *&aPtr << "\n"; // valor da variavel


     cout << "****************************************\n";

     cout << "a      -> "  << a      << "\n"; // valor da variavel
     cout << "aPtr   -> "  << aPtr   << "\n"; // valor da variavel
     cout << "&Ptr   -> "  << &aPtr   << "\n"; // valor da variavel
     cout << "*aPtr  -> "  << *aPtr   << "\n"; // valor da variavel

     int y, *yPtr;
     yPtr = &y;
     cout << "y->"  <<y<< "\n"; // valor da variavel
     *yPtr = 8;
     cout << "y->"  <<y<< "\n"; // valor da variavel


    return 0; // indica terminação bem-sucedida


 } // fim de main
