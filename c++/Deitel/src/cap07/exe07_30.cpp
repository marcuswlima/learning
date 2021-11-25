#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

#include <iomanip>

#define TAM 40000 /*Tamanho do vetor*/

int bucketSort( int [], const int );
int bubbleSort( int [], const int );
int insertionSort( int [], const int );

int main(){

    srand( time(0) );


    int arrInsertionSort[TAM], arrBucketSort[TAM], arrBubbleSort[TAM], tempo;
    
    for (int subscrito=0 ; subscrito<TAM ; subscrito++){
        int numero = gerarInteiro(1,999);
        arrBucketSort[subscrito] = numero;
        arrBubbleSort[subscrito] = numero;
        arrInsertionSort[subscrito] = numero;
    }

    tempo = bucketSort(arrBucketSort,TAM);
    cout << "bucketSort - Tempo de execucao " << tempo/60 << " Minutos e " << tempo%60 << " segundos.\n";

    tempo = bubbleSort(arrBubbleSort,TAM);
    cout << "bubbleSort - Tempo de execucao " << tempo/60 << " Minutos e " << tempo%60 << " segundos.\n";

    tempo = insertionSort(arrInsertionSort,TAM);
    cout << "insertionSort - Tempo de execucao " << tempo/60 << " Minutos e " << tempo%60 << " segundos.\n";
}    

int unidade(int valor){
    return valor % 10;
}

int dezena(int valor){
    return unidade(valor/10);
}

int centena(int valor){
    return unidade(valor/100);
}

int milhar(int valor){
    return unidade(valor/1000);
}

void zerarBuckets(int arrei [10][TAM], const int arraySize){
    for (int x=0 ; x < 10 ; x++ )
        for (int y=0 ; y < arraySize ; y++ )
            arrei[x][y]=0;

}

void passagemColeta(int buckets[10][TAM], int arrei[]) {
    int subscrito=0;
    for (int x=0 ; x < 10 ; x++ )
        for (int y=0 ; y < TAM ; y++ )
            if (buckets[x][y]>0) {
                arrei[subscrito]= buckets[x][y] ;
                subscrito ++;
            }

}

int bucketSort( int arrei[], const int arraySize){

    int subscrito, buckets[10][TAM]={0}, tinicio, tfim;

    tinicio=time(NULL);


    for (int volta=1; volta<=3; volta++){
        
        zerarBuckets(buckets, arraySize);

        // passagem de distribuição
        switch (volta)
        {
            case 1:
                for (subscrito=0 ; subscrito<arraySize ; subscrito++)
                    buckets[unidade(arrei[subscrito])][subscrito] = arrei[subscrito];
                break;
            case 2:
                for (subscrito=0 ; subscrito<arraySize ; subscrito++)
                    buckets[dezena(arrei[subscrito])][subscrito] = arrei[subscrito];
                break;
            case 3:
                for (subscrito=0 ; subscrito<arraySize ; subscrito++)
                    buckets[centena(arrei[subscrito])][subscrito] = arrei[subscrito];
                break;
        }

        passagemColeta(buckets, arrei);
    }

    tfim=time(NULL);

    return difftime(tfim,tinicio);
}


int bubbleSort( int arrei[], const int arraySize){

    int tinicio, tfim, temp;

    tinicio=time(NULL);


    for (int e=0; e<arraySize; e++){

        for (int i=1;i<arraySize; i++){
            if ( arrei[i-1] > arrei[i] ){
                temp = arrei[i];
                arrei[i] = arrei[i-1];
                arrei[i-1] = temp;
            }
        }

    }


    tfim=time(NULL);

    return difftime(tfim,tinicio);
}

int insertionSort( int arrei[], const int arraySize){

    int tinicio, tfim, insert;

    tinicio=time(NULL);

 
    for ( int next = 1; next < arraySize; next++ )
    {
        insert = arrei[ next ]; // armazena o valor no elemento atual

        int moveItem = next; // inicializa a localização para colocar elemento

        // procura a localização em que colocar o elemento atual
        while ( ( moveItem > 0 ) && ( arrei[ moveItem - 1 ] > insert ) )
        {
            // desloca o elemento uma posição para a direita
            arrei[ moveItem ] = arrei[ moveItem - 1 ];
            moveItem--;
        } // fim do while
        arrei[ moveItem ] = insert; // lugar em que o elemento é inserido no array
    } // fim do for


    tfim=time(NULL);

    return difftime(tfim,tinicio);
}