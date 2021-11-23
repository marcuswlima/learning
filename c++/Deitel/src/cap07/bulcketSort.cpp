/*************************INICIO*****************************************/
//==================================================================
//
//   Projeto: Bucket Sort
//   Data de Criacao: 27/02/09
//   Autor: Albany Timbo Mesquita
//   Colaboracao:Pedro Henrique Fernandes Marques Leitao         
//   https://pt.wikipedia.org/wiki/Bucket_sort
//
//==================================================================

#include <iomanip>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "..\lib\marcusLib.h"

#define TAM 10 /*Tamanho do vetor*/
#define NUM 100 /*base para gerador de numeros aleatorios*/

// Protótipos
void gerarVet(int*);
void bucketSort(int*);
void imprimaVet(int*);

// main
int main(){

    int vet[TAM]={32,18,31,49,73,93,91,46,78,61},tinicio,tfim,tempo;

    tinicio=time(NULL);

    //gerarVet(vet);
    imprimaVet(vet);
    bucketSort(vet);   
    //imprimaVet(vet);

    tfim=time(NULL);
    tempo=difftime(tfim,tinicio);
    cout << "Tempo de execucao " << tempo/60 << " Minutos e " << tempo%60 << " segundos.\n";
    //system("pause");
    return 0;

}

/***********************************************************************/
/*******************************FUNCOES*********************************/
/***********************************************************************/
void bucketSort(int *vet){

    int buckets[10][TAM],bucket[TAM],cont=1,unidade,w=0,i,j; 

    do{

        //Zerando o vetor auxiliar.
        for(i=0 ; i<TAM ; i++){
            bucket[i] = 0;
        }

        //Setando a Matriz com valores -1
        for(i=0;i<10;i++)  {
            for(j=0;j<TAM;j++){
                buckets[i][j] = -1;
            }
        }

        for (int subscrito=0 ; subscrito<10 ; subscrito++) {
            unidade = (vet[subscrito]/cont)%10;//verificando o valor da esquerda para direita
            buckets[unidade][bucket[unidade]] = vet[subscrito];//colocando o valor na sua posicao na matriz
            bucket[unidade]++; //contador de colunas da matriz
        }

        cout << "\n";
        for ( int linha = 0; linha < 10; linha++ ) {
            for ( int coluna = 0; coluna < TAM; coluna++ )
                cout << "[" << linha << "," << coluna << "]="  << buckets[ linha ][ coluna ] << " ";

            cout << "\n";
        }


        //volta com os valores da Matriz para o vetor
        for(i=0 ; i<10 ; i++) {
            for(j=0 ; j<TAM ; j++){
                if(buckets[i][j] != -1){
                    vet[w] = buckets[i][j];
                    w++;
                }
            }
        }

        for (int i=0;i<10;i++)
            cout << "[" << i << "]=" << vet[i] << " ";

        cout << "\n";

        cout << "bucket[0] -> " << bucket[0] << "\n";

        if (cont==100)
            break;

        w = 0; 
        cont=cont*10;

    }while(bucket[0] < TAM);//condicao :Enquanto vetor auxiliar < tamanho vetor
}                          //         

/******************GERADOR DE NUMEROS ALEATORIOS**************************/
void gerarVet(int *vet){
     
     srand(time(NULL));
     for (int i=0;i<TAM;i++){
         vet[i]=rand()%NUM;
         }
     }
/*******************FUNCAO PARA IMPRIMIR VETOR************************/
void imprimaVet(int *vet){
     for (int i=0;i<TAM;i++){
         cout<<vet[i]<<"|";
         }
     cout<<"**************************************************************\n";     
     }
/********************************FIM*************************************/