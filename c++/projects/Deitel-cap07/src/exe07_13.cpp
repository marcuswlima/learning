#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;
using std::cin;

int main(){
    srand( time(0) );
/////// a)
    cout << "a)\n";
    const int sizeA=10;
    int a[sizeA]={0};
    mostarArray(a,sizeA);

/////// b)
    cout << "b)\n";
    const int sizeBonus=15;
    int bonus[sizeBonus]={0};
    for (int i=0; i<sizeBonus; i++)
        bonus[i] =+ 1;
    mostarArray(bonus,sizeBonus);

/////// c)
/*
    const int sizeMontlyTemperatures=12;
    double montlyTemperatures[sizeMontlyTemperatures]={0};
    for (int i=0; i<=sizeMontlyTemperatures; i++){
        cout << "[" << i << "] ";
        cin >> montlyTemperatures[i];

    }
    mostarArray(montlyTemperatures,sizeMontlyTemperatures);
*/

/////// d)
    cout << "d)\n";
    const int sizeBestScores=5;
    int bestScores[sizeBestScores]={0};
    for (int i=0;i<sizeBestScores; i++)
        bestScores[i] = gerarInteiro(1,100);

    cout << "Subscrito\tValor\n";
    for (int i=0;i<sizeBestScores; i++){
        cout << "[" << i << "]\t\t" << bestScores[i];

        cout << "\n";
    }
    //mostarArray(bestScores,sizeBestScores);

}