// Figura 8.10: fig08_10.cpp
// Convertendo minúsculas em maiúsculas
// utilizando um ponteiro não constante para dados não constantes.
#include <iostream>
using std::cout;
using std::endl;

#include <cctype> // protótipos para islower e toupper
using std::islower;
using std::toupper;

void convertToUppercase( char * );

int main()
{
    char phrase[] = "Marcus William dos Santos Lima and $32.98";

    cout << "The phrase before conversion is: " << phrase;
    convertToUppercase( phrase );
    cout << "\nThe phrase after conversion is: " << phrase << endl;
    return 0; // indica terminação bem-sucedida
} // fim de main

// converte string em letras maiúsculas
void convertToUppercase( char *sPtr )
{
    while ( *sPtr != '\0' ) // faz loop enquanto caractere atual não é ‘\0’
    {
        if ( islower( *sPtr ) ) // se o caractere estiver em minúsculas,
            *sPtr = toupper( *sPtr ); // converte em maiúsculas

        sPtr++; // move sPtr para o próximo caractere na string
    } // fim do while
} // fim da função convertToUppercase

void convertToUppercase2( char sPtr[] )
{
    while ( *sPtr != '\0' ) // faz loop enquanto caractere atual não é ‘\0’
    {
        if ( islower( *sPtr ) ) // se o caractere estiver em minúsculas,
            *sPtr = toupper( *sPtr ); // converte em maiúsculas

        sPtr++; // move sPtr para o próximo caractere na string
    } // fim do while
} // fim da função convertToUppercase

void teste(int teste){

}

void teste(char teste){

}