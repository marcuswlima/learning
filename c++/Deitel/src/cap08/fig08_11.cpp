// Figura 8.11: fig08_11.cpp
// Imprimindo uma string um caractere por vez utilizando
// um ponteiro não constante para dados constantes.
#include <iostream>
using std::cout;
using std::endl;

void printCharacters( const char * ); // imprime usando ponteiro para dados const

int main()
{
    const char phrase[] = "Print characters of a string";

    cout << "The string is:\n";
    printCharacters( phrase ); // imprime caracteres em phrase
    cout << endl;
    return 0; // indica terminação bem-sucedida
} // fim de main

// sPtr pode ser modificado, mas não pode modificar o caractere para o qual
// ele aponta, isto é, sPtr é um ponteiro ‘de leitura’
void printCharacters( const char *sPtr )
{
    for ( ; *sPtr != '\0'; sPtr++ ) // nenhuma inicialização
        cout << *sPtr; // exibe caractere sem modificação
} // fim da função printCharacters