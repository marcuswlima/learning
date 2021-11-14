#include "../lib/marcusLib.h"

int main(){
    const int size=6;
    int arrei[size], temp;

    for (int i=0;i<size; i++)
        arrei[i] = gerarInteiro(1,10);
    
    mostarArray(arrei,size);

    for (int i=0;i<size; i++){

        int e=9;
        if (arrei[i] > arrei[i+1]){
            temp = arrei[i+1];
            arrei[i] = arrei[i+1];
            arrei[i+1] = temp;
        }

    }

    mostarArray(arrei,size);
}