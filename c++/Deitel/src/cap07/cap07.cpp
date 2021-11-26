#include <iostream>
using std::cout;
using std::cin;

#include "../lib/marcusLib.h"

#include <iomanip>


int menu(int);
void exe29();
void exe31();
void exe32();
void exe35();

int main(){

    srand( time(0) );

    int opcao;  

    opcao = 0;
    opcao = menu(opcao);

    switch (opcao)
    {
        case 29: exe29(); break;
        case 31: exe31(); break;
        case 32: exe32(); break;
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
        cout << "35 - printArray\n";
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
    char string2[]="\"at5as salta\"";
    char string3[]="\"erro comum ocorre\"";
    char string4[]="\"arara\"";

    analisaPalindrome(string1);
    analisaPalindrome(string2);
    analisaPalindrome(string3);
    analisaPalindrome(string4);

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
    const int tamanho=10;
    int arrei[tamanho];
    for (int subscrito=0; subscrito<tamanho; subscrito++)
        arrei[subscrito]=gerarInteiro(1,999);
    printArray(arrei,0,tamanho);

}

