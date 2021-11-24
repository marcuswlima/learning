#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

#include <iomanip>

#define TAM 5000 /*Tamanho do vetor*/

int unidimensional[TAM];

void bucketSort( int [], const int );

int main(){

    srand( time(0) );

    
    for (int subscrito=0 ; subscrito<TAM ; subscrito++){
        unidimensional[subscrito] = gerarInteiro(1,999);
    }

    mostarArray(unidimensional,TAM);
    bucketSort(unidimensional,TAM);
    mostarArray(unidimensional,TAM);

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

void bucketSort( int arrei[], const int arraySize){

    int subscrito, buckets[10][TAM]={0};

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
}

