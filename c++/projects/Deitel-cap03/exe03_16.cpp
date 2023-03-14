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
    srand( time(0) );

    cout << "1<=n<=2" << endl ;
    for (int i=1; i<=10; i++ ) {
        cout << gerarInteiro(1,2) << " " ;
    }
    cout << endl ;

    cout << "1<=n<=100" << endl ;
    for (int i=1; i<=10; i++ ) {
        cout << gerarInteiro(1,100) << " " ;
    }
    cout << endl ;

    cout << "998<=n<=1003" << endl ;
    for (int i=1; i<=20; i++ ) {
        cout << gerarInteiro(998,1003) << " " ;
    }
    cout << endl ;


    cout << "0<=n<=9" << endl ;
    for (int i=1; i<=30; i++ ) {
        cout << gerarInteiro(0,9) << " " ;
    }
    cout << endl ;

    cout << "-1<=n<=1" << endl ;
    for (int i=1; i<=10; i++ ) {
        cout << gerarInteiro(-1,1) << " " ;
    }
    cout << endl ;

    cout << "-3<=n<=1" << endl ;
    for (int i=1; i<=20; i++ ) {
        cout << gerarInteiro(-3,1) << " " ;
    }
    cout << endl ;

    cout << "-1<=n<=11" << endl ;
    for (int i=1; i<=30; i++ ) {
        cout << gerarInteiro(-1,11) << " " ;
    }
    cout << endl ;

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

int gerarInteiro(int menor, int maior) {
 
    int faixa  = (maior - menor + 1);
    int gerado = (1 + rand() % faixa);

    return menor + (gerado-1);

}
