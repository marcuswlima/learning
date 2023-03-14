#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <iomanip>

using std::setprecision;
using std::setiosflags;


int main()
{
    int kilometros, qtdCarros = 0 ;
    double litros, kilometroPorLitro, somaFinal = 0 ;

    while ( litros != -1)
    {
        cout << "Digite os litros usados (-1 para fim) ..........: " ;
        cin >> litros ;

        if (litros == -1)
            continue;


        cout << "Digite os os kilômetros dirigidos ..............: "  ;
        cin >> kilometros ;
        kilometroPorLitro = static_cast< double > (kilometros) / litros;

        cout << "Os kilometros por litro deste tanque foram de ..: " 
            << setprecision(5) 
            << setiosflags( ios::fixed | ios::showpoint )
            << kilometroPorLitro 
            << endl << endl;

        qtdCarros ++;
        somaFinal += kilometroPorLitro;


    }
    
    
    cout << endl <<"A média final é .....: "
        << setprecision(6) 
        << setiosflags( ios::fixed | ios::showpoint )
        << somaFinal/qtdCarros
        << endl << endl;

    cout << endl << endl ;
    return 0;
}

