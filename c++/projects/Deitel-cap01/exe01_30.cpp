#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int v1, v2, v3, v4, v5, maior, menor;

    maior = 0;
    menor = 999999;


    cout << "Informe o primeiro número (menor que 999999): ";
    cin >> v1 ; 

    if ( v1 > maior )
        maior = v1 ;

    if ( v1 <  menor )
        menor = v1 ;

    cout << "Informe o segundo número: (menor que 999999): ";
    cin >> v2 ; 

    if ( v2 > maior )
        maior = v2 ;

    if ( v2 <  menor )
        menor = v2 ;

    cout << "Informe o terceiro número: (menor que 999999): ";
    cin >> v3 ; 

    if ( v3 > maior )
        maior = v3 ;

    if ( v3 <  menor )
        menor = v3 ;

    cout << "Informe o quarto número: (menor que 999999): ";
    cin >> v4 ; 

    if ( v4 > maior )
        maior = v4 ;

    if ( v4 <  menor )
        menor = v4 ;

    cout << "Informe o quinto número: (menor que 999999): ";
    cin >> v5 ; 

    if ( v5 > maior )
        maior = v5 ;

    if ( v5 <  menor )
        menor = v5 ;


    cout << "O maior valor de todos é : " << maior << endl;
    cout << "O menor valor de todos é : " << menor << endl;

    return 0;
}

