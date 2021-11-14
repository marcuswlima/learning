#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

int main(){
    srand( time(0) );

    const int size=10;
    int arrei[size]={10,2,3,4,5,6,7,8,9,10};
    int desoedenados=size;
    int passagens=0;
    int trocas=0;
    int vaerificacoes=0;
    bool trocou;

    for (int i=0;i<size; i++)
        arrei[i] = gerarInteiro(1,100);
    
    mostarArray(arrei,size);

    for (int e=0; e<size; e++){
        trocou=false;

        for (int i=1; i<desoedenados; i++){
            vaerificacoes++;
            if ( arrei[i-1] > arrei[i] ){
                int temp = arrei[i];
                arrei[i] = arrei[i-1];
                arrei[i-1] = temp;
                trocou = true;
                trocas++;
            }
        }
        desoedenados--;

        passagens++;

        if (!trocou)
            break;
        

      //  mostarArray(arrei,size);
    }


    mostarArray(arrei,size);

    cout << "foram realizadas " <<  passagens << " passagens\n";
    cout << "foram realizadas " <<  trocas << " trocas\n";
    cout << "foram realizadas " <<  vaerificacoes << " vaerificacoes\n";

    return 0;

}
