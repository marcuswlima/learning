#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include "cap06.h"

#include <iomanip>
using std::setw;
using std::setiosflags;
using std::setprecision;


inline double circleArea(double raio);

int main(){
    double raio;
    cout << "Qual o raio do círculo ? ";
    cin >> raio;

    cout << "A área do círculo é " << circleArea(raio) << endl;


    cout << setiosflags(ios::fixed | ios::showpoint) ; 
    cout << endl;

    for (int i=1;i<=10;i++){
        raio = gerarDouble(0,10);
        cout << setw(2) << i << " ";
        cout << setw(4) << setprecision(4) << raio << " ";
        cout << setw(7) << setprecision(4) << circleArea(raio) ;

        cout << endl;
    }

}

inline double circleArea(double raio) {
    return raio*raio;
}