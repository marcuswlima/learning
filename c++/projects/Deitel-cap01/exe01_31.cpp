#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int numero, resto;
    cout << "Informe o número a ser analisado : " ;
    cin >> numero ; 

    resto = (numero % 2 );

    if ( resto == 0 )
        cout << "O númeoro " << numero << " é par" << endl;

    if ( resto != 0 )
        cout << "O número " << numero << " ñ é par" << endl;

    return 0;
}

