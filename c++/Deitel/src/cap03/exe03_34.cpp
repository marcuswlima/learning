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

int flip();

int main()
{

    srand( time(0) );

    int cara=0, coroa=0, jogada;
    for (int i=1;i<=100;i++){
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

int gerarInteiro(int menor, int maior) {
 
    int faixa  = (maior - menor + 1);
    int gerado = (1 + rand() % faixa);

    return menor + (gerado-1);

}

int flip() {
    return gerarInteiro(0,1);
}
