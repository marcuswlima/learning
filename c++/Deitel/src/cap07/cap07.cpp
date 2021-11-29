#include <iostream>
using std::cout;
using std::cin;

#include "../lib/marcusLib.h"

#include <iomanip>
using std::setw;

#include <string>
using std::string;

int menu(int);
void exe29();
void exe31();
void exe32();
void exe33();
void exe34();
void exe35();

int main(){

    srand( time(0) );

    int opcao;  

    opcao = 34;
    opcao = menu(opcao);

    switch (opcao)
    {
        case 29: exe29(); break;
        case 31: exe31(); break;
        case 32: exe32(); break;
        case 33: exe33(); break;
        case 34: exe34(); break;
        case 35: exe35(); break;
        default:break;
    }

    return 0;

}// fim main

int menu(int opcao){

    if ( opcao == 0 ){
        int cein;
        cout << "*******************************\n";
        cout << "29 - Crivo de Eratostenes\n";
        cout << "31 - Selection Sort\n";
        cout << "32 - Polimdrimo\n";
        cout << "33 - Pesquisa Linear recursiva\n";
        cout << "34 - Oito rainhas recussivo\n";
        cout << "35 - printArray Recursive\n";
        cout << "*******************************\n";
        cout << "Indique qual exercicio: ";
        cin >> cein;
        return cein;
    }
    else
        return opcao;



}

//-------------29------------------//

void buscarMultiplos(int arrei[],int tamanho, int emAnalise){
    arrei[emAnalise]=0;

    for (int subscrito=emAnalise*2 ; subscrito<tamanho ; subscrito++)
        if   (multiple(subscrito,emAnalise))
            arrei[subscrito]=emAnalise;

}

void imprimirPrimos(int arrei[],int tamanho){
    for (int subscrito=2 ; subscrito<tamanho ; subscrito++)
        if (arrei[subscrito]==0)
            cout << "[" << subscrito << "]=" << arrei[subscrito] << " ";

    cout << "\n";

}

void exe29(){
    const int tamanhoArrei=1000;
    int primos[tamanhoArrei];

    for (int i=0; i<tamanhoArrei ; i++)
        primos[i]=0;

    buscarMultiplos(primos, tamanhoArrei,2);
    buscarMultiplos(primos, tamanhoArrei,3);
    buscarMultiplos(primos, tamanhoArrei,5);
    buscarMultiplos(primos, tamanhoArrei,7);

    mostarArray(primos, tamanhoArrei);

    imprimirPrimos(primos, tamanhoArrei);

}

//-------------31------------------//

void selectionSort(int arrei[], const int tamanho, const int inicio=0){

    
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

void exe31(){

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

//-------------32------------------//

int tamanhoArrChar(char palavra[]){
    int tamanho=0;

    for ( int i = 0; palavra[ i ] != '\0'; i++ )
        tamanho++;

    return tamanho;

}

bool testPalindrome(char palavra[], int inicio=0){
    //cout << "*inicio "<< inicio << "\n";
    int meio = tamanhoArrChar(palavra)/2 ;
    int distancia = meio-inicio;

    if (distancia > 0){

        //cout << "meio "      << meio << "\n";
        //cout << "distancia " << distancia << "\n";

        if (palavra[inicio] == palavra[meio+distancia]){
            //cout << "testPalindrome()\n";
            return testPalindrome(palavra,inicio+1);
        }
        else {
            //cout << "false\n";
            return false;

        }

    }
    else {
        //cout << "true\n";
        return true;
    }

}

void analisaPalindrome(char palavra[]){
    cout << palavra ;
    if (!testPalindrome(palavra))
        cout << " nao";
    cout << " eh Polindromo\n" ;

}


void exe32(){

    cout << "*******************************\n";
    cout << "36 - Polimdrimo\n";
    cout << "*******************************\n";

    char string1[]="\"radar\"";
    char string2[]="\"atlas salta\"";
    char string3[]="\"erro comum ocorre\"";
    char string4[]="\"arara arara\"";

    analisaPalindrome(string1);
    analisaPalindrome(string2);
    analisaPalindrome(string3);
    analisaPalindrome(string4);

}

//-------------33------------------//

int linearSearchRecursivo( const int arrei[], int key, int sizeOfArray, int inicio=0)
{
//    cout << "*****" << inicio << "\n";

    if ( arrei[inicio]==key ) 
        return inicio;
    else if (inicio+1==sizeOfArray  )
        return -1;
    else 
        linearSearchRecursivo(arrei,key,sizeOfArray,inicio+1);
    
    return 99999;

}


void exe33(){

    cout << "*******************************\n";
    cout << "33 - Linear Search recusive    \n";
    cout << "*******************************\n";

    const int tamanho=10;
    int arrei[tamanho]={1,2,3}, key=3;

    for (int subscrito=0; subscrito<tamanho; subscrito++)
        arrei[subscrito]=gerarInteiro(1,8);
    
    cout << "key -> " << key << "\n";
    cout << linearSearchRecursivo(arrei, key, tamanho ) << "\n";
    mostarArray(arrei, tamanho);
    cout << "\n";

}


//-------------34------------------//

const int lado=8;
int currentX;
int currentY;
int iteracao=1;
int tabuleiro[lado][lado];
int alcancados[lado][lado];
int eliminados[lado][lado];


void imprimirTabuleiro(int arrei[][8], string titulo){
    cout << "\n";
    cout << titulo << "\n";
    cout <<"------------------------------------------\n"; 
    cout <<" |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |\n";
    cout <<"------------------------------------------\n"; 


    for (int x=0; x<lado; x++){
        cout << x << "| ";
        for (int y=0; y<lado; y++)
            cout << setw(2) << arrei[x][y]<< " | ";
        cout << "\n";
    }

    cout <<"------------------------------------------\n"; 

}


void marcar(int arrei[][8], int x, int y, int valor){
    arrei[x][y]=valor;
}

bool EhAlcancavel(int x1,int y1, int x2, int y2){
    return y1==y2 || x1==x2 || (x1+y1==x2+y2) || (x1-y1==x2-y2);
}


void posicionarDamas(){
    bool fazer;

//----------------------------------
    tabuleiro[currentX][currentY]=iteracao;

    //buscar casa livra
    for(int x=0 ; x<lado ; x++){
        for(int y=0 ; y<lado ; y++){

            fazer = tabuleiro[x][y]==0  && !EhAlcancavel(currentX,currentY,x,y);
            
            if (fazer){
                currentX = x;
                currentY = y;
                break;
            }

        }
        if (fazer)
            break;
    }
//-----------------------------------------------
    tabuleiro[currentX][currentY]=3;

    //buscar casa livra
    for(int x=0 ; x<lado ; x++){
        for(int y=0 ; y<lado ; y++){

            fazer = tabuleiro[x][y]==0  && !EhAlcancavel(currentX,currentY,x,y);
            
            if (fazer){
                currentX = x;
                currentY = y;
                break;
            }

        }
        if (fazer)
            break;
    }

    tabuleiro[currentX][currentY]=2;

}

void exe34(){

    cout << "*******************************\n";
    cout << "34 - Oito rainhas recursivo    \n";
    cout << "*******************************\n";


    // zerar tabuleiros
    for(int x=0;x<lado;x++)
        for(int y=0 ; y<lado ; y++){
            tabuleiro[x][y]=0;
            eliminados[x][y]=0;
        }


    currentX = 0;
    currentY = 0;
    posicionarDamas();

    imprimirTabuleiro(tabuleiro,"Tabuleiro");

}

//-------------35------------------//

void printArray (int arrei[], int inicio, int fim) {

    if (inicio==fim)
        cout << "\n";
    else{ 
        cout << "[" << inicio << "]=" << arrei[inicio] << " ";
        printArray(arrei, inicio+1, fim);
    } 
}

void exe35(){

    cout << "*******************************\n";
    cout << "35 - printArray Recursive\n";
    cout << "*******************************\n";

    const int tamanho=10;
    int arrei[tamanho];
    for (int subscrito=0; subscrito<tamanho; subscrito++)
        arrei[subscrito]=gerarInteiro(1,999);
    printArray(arrei,0,tamanho);

}

