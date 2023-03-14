#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

int main(){
    srand( time(0) );

    const int size=10;
    int arrei[size]={4,6,3}, temp;
    int passagens=0;
    int trocas=0;
    int virificacoes=0;

    for (int i=0;i<size; i++)
        arrei[i] = gerarInteiro(1,100);
    
    mostarArray(arrei,size);

    for (int e=0; e<size; e++){

        for (int i=1;i<size; i++){
            virificacoes++;
            if ( arrei[i-1] > arrei[i] ){
                temp = arrei[i];
                arrei[i] = arrei[i-1];
                arrei[i-1] = temp;
                trocas++;
            }
        }

      //  mostarArray(arrei,size);
      passagens++;
    }


    mostarArray(arrei,size);

    cout << "foram realizadas " <<  passagens    << " passagens\n";
    cout << "foram realizadas " <<  trocas       << " trocas\n";
    cout << "foram realizadas " <<  virificacoes << " virificacoes\n";

    return 0;

}
