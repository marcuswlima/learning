#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "MarcusTools.h"

#include <ctime>

#include <iomanip>
using std::setw; // permite que o programa configure a largura de um campo
using std::setprecision;

int countSecondFromZero(int hora, int minuto, int segundo);
int diferencaEmSegundos(int h1, int m1, int s1, int h2, int m2, int s2);

int main(){

    srand( time(0) );

    int hora1, minuto1, segundo1,
        hora2, minuto2, segundo2,
        cfz1, cfz2;

    //cout << "Informe a quatidade de vezes :" << endl;
    //cin >> quantidade ;

    cout << "Hora1\t\tcsfz1\tHora2\tcsfz1\tDiff" << endl;
    
    for (int i=1; i<=30; i++){

        hora1 = gerarInteiro(0,11);
        minuto1 = gerarInteiro(0,59);
        segundo1 = gerarInteiro(0,59);
        cfz1 = countSecondFromZero(hora1,minuto1,segundo1);

        hora2 = gerarInteiro(0,11);
        minuto2 = gerarInteiro(0,59);
        segundo2 = gerarInteiro(0,59);
        cfz2 = countSecondFromZero(hora2,minuto2,segundo2);

        cout << setw(2) << hora1    << ":" 
             << setw(2) << minuto1  << ":" 
             << setw(2) << segundo1 << "\t" 
             << setw(6) << cfz1     << " " 
             << setw(2) << hora2    << ":" 
             << setw(2) << minuto2  << ":" 
             << setw(2) << segundo2 << "\t"
             << setw(6) << cfz2     << "\t"
             << setw(6) << diferencaEmSegundos(hora1, minuto1, segundo1, hora2, minuto2, segundo2) 
             << endl ;
             //<< setw(5) << countSecondFromZero(hora,minuto,segundo) << endl;
    }


}

int countSecondFromZero(int hora, int minuto, int segundo){
    return (hora*60*60) + (minuto*60) + segundo;
}

int diferencaEmSegundos(int h1, int m1, int s1, int h2, int m2, int s2){
    return abs(countSecondFromZero(h1, m1, s1) - countSecondFromZero(h2, m2, s2));
}