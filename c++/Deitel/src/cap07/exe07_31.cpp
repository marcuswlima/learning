#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

#include <iomanip>

void selectionSort(int arrei[], const int tamanho);

int main(){

    //srand( time(0) );

    const int tamanhoArrei=3;
    int numeros[tamanhoArrei]={3,2,1};

//    for (int subscrito=0; subscrito<tamanhoArrei; subscrito++)
//        numeros[subscrito]=gerarInteiro(1,1000);

    mostarArray(numeros,tamanhoArrei);
    selectionSort(numeros,tamanhoArrei);
    mostarArray(numeros,tamanhoArrei);

}

void selectionSort(int arrei[], const int tamanho){

    cout << "selectionSorting...\n";

    int maior=0, subscrito;

    for(int subscrito=0; subscrito<tamanho; subscrito++)
        if (arrei[subscrito]>maior)
            maior=arrei[subscrito];
    
    int menor=maior;
    for(int subscrito=0; subscrito<tamanho; subscrito++)
        if (arrei[subscrito]<menor)
            menor=arrei[subscrito];

    cout << "maior -> " << maior << "\n";
    cout << "menor -> " << menor << "\n";
//-------------------------------------//

    
    int inicio, subscritoMenor,analisado, temp;

    inicio = tamanho-tamanho;
    analisado=arrei[inicio];

    for (int i=1; i<tamanho; i++){
        if (arrei[i]<analisado){
            subscritoMenor = i;
        }
    }

    temp=arrei[inicio];
    arrei[inicio]=arrei[subscritoMenor];
    arrei[subscritoMenor]=temp;

    inicio = 1;
    analisado=arrei[inicio];

    for (int i=1; i<tamanho; i++){
        if (arrei[i]<analisado){
            subscritoMenor = i;
        }
    }

    temp=arrei[inicio];
    arrei[inicio]=arrei[subscritoMenor];
    arrei[subscritoMenor]=temp;
}
