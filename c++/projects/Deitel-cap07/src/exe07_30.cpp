#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

#include <iomanip>

#define TAM 37000 /*Tamanho do vetor*/

int bucketSort( int [], const int );
int bubbleSort( int [], const int );
int insertionSort( int [], const int );
int selectionSort( int [], const int );

int main(){

    srand( time(0) );


    int arrSelectionSort[TAM], arrInsertionSort[TAM], arrBucketSort[TAM], arrBubbleSort[TAM], tempo;
    
    for (int subscrito=0 ; subscrito<TAM ; subscrito++){
        int numero = gerarInteiro(1,999);
        arrBucketSort[subscrito] = numero;
        arrBubbleSort[subscrito] = numero;
        arrInsertionSort[subscrito] = numero;
        arrSelectionSort[subscrito] = numero;
    }

    cout << "bucketSorting...\n";
    tempo = bucketSort(arrBucketSort,TAM);
    cout << "Tempo de execucao " << tempo/60 << " Minutos e " << tempo%60 << " segundos.\n";

    cout << "bubbleSorting...\n";
    tempo = bubbleSort(arrBubbleSort,TAM);
    cout << "Tempo de execucao " << tempo/60 << " Minutos e " << tempo%60 << " segundos.\n";

    cout << "insertSorting...\n";
    tempo = insertionSort(arrInsertionSort,TAM);
    cout << "Tempo de execucao " << tempo/60 << " Minutos e " << tempo%60 << " segundos.\n";

    cout << "selectionSorting...\n";
    tempo = selectionSort(arrSelectionSort,TAM);
    cout << "Tempo de execucao " << tempo/60 << " Minutos e " << tempo%60 << " segundos.\n";
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

    int tinicio, tfim, temp, desoedenados=arraySize;
    bool trocou;

    tinicio=time(NULL);

    for (int e=0; e<arraySize; e++){

        trocou=false;

        for (int i=1; i<desoedenados; i++){
            if ( arrei[i-1] > arrei[i] ){
                int temp = arrei[i];
                arrei[i] = arrei[i-1];
                arrei[i-1] = temp;
                trocou = true;
            }
        }
        desoedenados--;

        if (!trocou)
            break;
        
    }


    tfim=time(NULL);

    return difftime(tfim,tinicio);
}

int insertionSort( int arrei[], const int arraySize){

    int tinicio, tfim, insert;

    tinicio=time(NULL);

 
    for ( int next = 1; next < arraySize; next++ )
    {
        insert = arrei[ next ]; 

        int moveItem = next; 

        while ( ( moveItem > 0 ) && ( arrei[ moveItem - 1 ] > insert ) )
        {
            arrei[ moveItem ] = arrei[ moveItem - 1 ];
            moveItem--;
        } 
        arrei[ moveItem ] = insert; 
    } 


    tfim=time(NULL);

    return difftime(tfim,tinicio);
}


int selectionSort(int vetor[], const int tam) {

    int tinicio, tfim;

    tinicio=time(NULL);

    for (int indice = 0; indice < tam; ++indice) {
        int indiceMenor = indice;
        for (int indiceSeguinte = indice+1; indiceSeguinte < tam; ++indiceSeguinte) {
            if (vetor[indiceSeguinte] < vetor[indiceMenor]) {
                indiceMenor = indiceSeguinte;
            }
        }
        int aux = vetor[indice];
        vetor[indice] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
    }

    tfim=time(NULL);

    return difftime(tfim,tinicio);

}