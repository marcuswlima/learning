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

int gerarInteiro(int menor, int maior);


int main()
{
    int garado;
    srand( time(0) );

    garado = gerarInteiro(1,5) ; 
    //cout << garado << endl;

    cout << garado << endl;
    cout << garado*2 << endl;
    cout << (garado*2)+1 << endl;
    cout << ((garado*2)+1)*2 << endl;

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}


int gerarInteiro(int menor, int maior) {
 
    int faixa = (maior - menor + 1);
    int gerado = (1 + rand() % faixa);

    return menor + (gerado-1);

}

