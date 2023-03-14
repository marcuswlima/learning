#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;

#include <cmath>

using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()

void testeMultiplicacao();

int main()
{
    srand( time(0) );

    testeMultiplicacao();

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

int gerarInteiro(int menor, int maior) {
 
    int faixa  = (maior - menor + 1);
    int gerado = (1 + rand() % faixa);

    return menor + (gerado-1);

}

void testeMultiplicacao(){
    int a = gerarInteiro(1,9), b = gerarInteiro(1,9), resultado;

    cout << "Quanto é " << a <<" vezes " << b << " ? ";
    cin >> resultado ; 

    if (resultado == (a*b))
        cout << "acertou !!!";
    else    {
        cout << "errou !!!" << endl;
        testeMultiplicacao();
    }

}


