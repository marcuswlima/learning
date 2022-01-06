// Figura 8.12: fig08_12.cpp
// Tentando modificar dados por meio de um
// ponteiro não-constante para dados constantes.

void f( const int * ); // protótipo

int main()
{
    int y;

    f( &y ); // f tenta modificação não-válida
    return 0; // indica terminação bem-sucedida
} // fim de main

// xPtr não pode modificar o valor da variável constante para a qual ele aponta
void f( const int *xPtr )
{
    //*xPtr = 100; // erro: não é possível modificar objeto const
} // fim da função f