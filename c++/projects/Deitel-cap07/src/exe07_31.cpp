#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

#include <iomanip>

void selectionSort(int arrei[], const int tamanho, const int inicio=0);

int main(){

    srand( time(0) );

    const int tamanhoArrei=20;
    int numeros[tamanhoArrei]={0};

    for (int subscrito=0; subscrito<tamanhoArrei; subscrito++)
        numeros[subscrito]=gerarInteiro(1,999);

    cout << "unsorted...\n";
    mostarArray(numeros,tamanhoArrei);
    selectionSort(numeros,tamanhoArrei);
    cout << "sorted...\n";
    mostarArray(numeros,tamanhoArrei);

}

void selectionSort(int arrei[], const int tamanho, const int inicio){

    
    int subscritoMenor,analisado, temp;
    bool fez=false;
    analisado=arrei[inicio];

    if (inicio < tamanho){

        for (int i=inicio+1; i<tamanho; i++){
            if (arrei[i]<analisado){
                fez=true;
                subscritoMenor = i;
                analisado = arrei[i];
            }
        }

        if (fez){ 
            temp=arrei[inicio];
            arrei[inicio]=arrei[subscritoMenor];
            arrei[subscritoMenor]=temp;
        }

        selectionSort(arrei, tamanho,inicio+1);

    }
    



}
