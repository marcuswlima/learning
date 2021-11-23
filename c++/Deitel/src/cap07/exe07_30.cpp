#include "../lib/marcusLib.h"

#include <iostream>
using std::cout;

const int arraySize=3;
int unidimensional[arraySize]={97,3,1086};
int buckets[10][arraySize]={0};

int unidade(int);
int dezena(int);
int centena(int);
int milhar(int);

void bucketSort(const int [], const int );

int main(){

    mostarArray(unidimensional,arraySize);

    for (int subscrito=0 ; subscrito<arraySize ; subscrito++){
        cout << subscrito 
             << " " 
             << milhar(unidimensional[subscrito])
             << " " 
             << centena(unidimensional[subscrito])
             << " " 
             << dezena(unidimensional[subscrito])
             << " " 
             << unidade(unidimensional[subscrito])
             ;

        cout << "\n";
    }

    bucketSort(unidimensional,arraySize);

    mostraArr2D(buckets,10,3);

}    


void bucketSort(const int arrei[], const int arraySize){
    for (int subscrito=0 ; subscrito<arraySize ; subscrito++){
        buckets[unidade(arrei[subscrito])][0] = arrei[subscrito];
    }

    for (int subscrito=0 ; subscrito<10 ; subscrito++){
        if (buckets[subscrito]!=0);

    }

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
