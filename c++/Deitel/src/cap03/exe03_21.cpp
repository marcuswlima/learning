
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
bool multiple (int n1, int n2);

int main()
{

    int n1 ;
    srand( time(0) );

    for (int i=1;i<=50;i++){ 

        n1 = gerarInteiro(1,10);

        cout << n1 << " " << multiple(n1,2) << endl;
    }



//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

int gerarInteiro(int menor, int maior) {
 
    int faixa  = (maior - menor + 1);
    int gerado = (1 + rand() % faixa);

    return menor + (gerado-1);

}

bool multiple (int n1, int n2){
    int resto;
    // n1 é multiplo de n2 ???
    if ( n2 > n1 )
        return false;
    else {
        resto = n1 % n2 ;
        if ( resto == 0 )
            return true;
        else    
            return false;
    }
}

