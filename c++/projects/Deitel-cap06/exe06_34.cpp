#include <iostream>
using std::cout;
using std::endl;
#include "cap06.h"

int main()
{

    srand( time(0) );

    int cara=0, coroa=0, jogada;
    for (int i=1;i<=10000;i++){
        jogada = flip();

        switch (jogada) {
            case 0:
                cara += 1;
                break;
            case 1:
                coroa += 1;
                break;
            default:
                break;
        } //switch

    } // for 100 vezes

    cout << "cara -> " << cara << endl;
    cout << "coroa -> " << coroa << endl;


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}
