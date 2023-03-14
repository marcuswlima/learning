#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int nMaior, nMenor, resto;
    cout << "Informe o maior número  : " ;
    cin >> nMaior ; 

    cout << "Informe o menor número  : " ;
    cin >> nMenor ; 

    resto = (nMaior % nMenor );

    if ( resto == 0 )
        cout << "O número " << nMaior << " é multiplo de " << nMaior << endl;

    if ( resto != 0 )
        cout << "O número " << nMaior << " ñ é multiplo de " << nMenor << endl;

    return 0;
}

