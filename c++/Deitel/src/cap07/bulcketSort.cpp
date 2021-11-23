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
#define TAM 30 /*Tamanho do vetor*/
#define NUM 10000 /*base para gerador de numeros aleatorios*/

using std::cout;
using std::cin;
using std::endl;

void gerarVet(int*);
void bucketSort(int*);
void imprimaVet(int*);

int main(){
    int vet[TAM],tinicio,tfim,tempo;
   
   tinicio=time(NULL);
   
   gerarVet(vet);
   imprimaVet(vet);
   bucketSort(vet);   
   imprimaVet(vet);
        
   tfim=time(NULL);
   tempo=difftime(tfim,tinicio);
   cout<<"Tempo de execucao "<<tempo/60<<" Minutos e "<<tempo%60<<" segundos.\n";
    system("pause");
    return 0;
    
    }
/***********************************************************************/
/*******************************FUNCOES*********************************/
/***********************************************************************/
void bucketSort(int *vet){
    int mat[10][TAM],aux[TAM],cont=1,num,w=0,i,j; 
    

    do{
      for(i=0;i<TAM;i++){aux[i] = 0;}//Zerando o vetor auxiliar.
      for(i=0;i<10;i++)  {//Setando a Matriz com valores -1
	          for(j=0;j<TAM;j++){
              mat[i][j] = -1;
              }
      }
      for (i=0;i<TAM;i++) {
    	  num = (vet[i]/cont)%10;//verificando o valor da esquerda para direita
    	  mat[num][aux[num]] = vet[i];//colocando o valor na sua posicao na matriz
    	  aux[num]++; //contador de colunas da matriz
      }
      
      for(i=0;i<10;i++) {//volta com os valores da Matriz para o vetor
       	  for(j=0;j<TAM;j++){
     	      if(mat[i][j] != -1){
     	      vet[w] = mat[i][j];
     	      w++;
    	      }
          }
      }
      w = 0; 
      cont=cont*10;
      }while(aux[0] < TAM);//condicao :Enquanto vetor auxiliar < tamanho vetor
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