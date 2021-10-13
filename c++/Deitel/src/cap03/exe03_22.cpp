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

void imprimirQuadrado(int lado, char caracterDePreenchimento);

int main()
{
    int lado;
    char caracterDePreenchimento;

    cout << "Qual o lado do quandrado ? ";
    cin >> lado ; 

    cout << "Qual o lado caracter a ser utilizador ? ";
    cin >> caracterDePreenchimento ; 

    imprimirQuadrado(lado, caracterDePreenchimento);


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

void imprimirQuadrado(int lado, char caracterDePreenchimento){
    for(int x=1;x<=lado;x++){
        for (int y=1;y<=lado;y++)
            cout << caracterDePreenchimento;
        cout << endl;
    }

}

