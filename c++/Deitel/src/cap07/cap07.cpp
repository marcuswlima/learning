/*
#include <iostream>
using std::cout;
using std::cin;

#include <iomanip>
using std::setw;

#include <vector>
using std::vector;
*/

#include "../lib/marcusLib.h"


int menu(int);
void exe29();
void exe31();
void exe32();
void exe33();
void exe34();
void exe35();
void exe36();
void exe37();
void exe38();
void exe39();

int main(){

    srand( time(0) );

    int opcao;  

    opcao = 39;
    opcao = menu(opcao);

    switch (opcao)
    {
        case 29: exe29(); break;
        case 31: exe31(); break;
        case 32: exe32(); break;
        case 33: exe33(); break;
        case 34: exe34(); break;
        case 35: exe35(); break;
        case 36: exe36(); break;
        case 37: exe37(); break;
        case 38: exe38(); break;
        case 39: exe39(); break;
        default:break;
    }

    return 0;

}// fim main

int menu(int opcao){

    if ( opcao == 0 ){
        int cein;
        cout << "*****************************************\n";
        cout << "29 - Crivo de Eratostenes\n";
        cout << "31 - Selection Sort\n";
        cout << "32 - Polimdrimo\n";
        cout << "33 - Pesquisa Linear recursiva\n";
        cout << "34 - Oito rainhas recussivo\n";
        cout << "35 - printArray Recursive\n";
        cout << "36 - String Reverse\n";
        cout << "37 - Localizar o valor mínimo em um array\n";
        cout << "38 - exe07_10 com vector<>\n"; 
        cout << "39 - exe07_17com vector<>\n"; 
        cout << "*****************************************\n";
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
        return linearSearchRecursivo(arrei,key,sizeOfArray,inicio+1);
    

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

bool EhAlcancavel(int x1,int y1, int x2, int y2){
    return y1==y2 || x1==x2 || (x1+y1==x2+y2) || (x1-y1==x2-y2);
}

void posicionarDamas(){
    bool fazer;

//----------------------------------
    // macar dama no tabuleiro
    tabuleiro[currentX][currentY]=iteracao;
    
    // macar alcancados
    for(int row=0 ; row<lado ; row++)
        for(int col=0 ; col<lado ; col++)
            if (EhAlcancavel(currentX,currentY,row,col)) 
                alcancados[row][col]=iteracao;

    //buscar casa livra
    fazer=false;
    for(int x=0 ; x<lado ; x++){
        for(int y=0 ; y<lado ; y++){

            fazer = tabuleiro[x][y]==0  && !EhAlcancavel(currentX,currentY,x,y) && alcancados[x][y]==0;
            
            if (fazer){
                currentX = x;
                currentY = y;
                break;
            }

        }
        if (fazer)
            break;
    }

    if (fazer){
        iteracao++;
        posicionarDamas();
    }

}

void jogadas(){

    for(int x=0;x<lado;x++)
        for(int y=0 ; y<lado ; y++){


            for(int row=0;row<lado;row++)
                for(int col=0 ; col<lado ; col++){
                    tabuleiro[row][col]=0;
                    eliminados[row][col]=0;
                    alcancados[row][col]=0;
                }
            
            iteracao = 1;

            currentX = x;
            currentY = y;
            cout << "x " << currentX << " y " << currentY;
            posicionarDamas();
            cout << " jogadas " << iteracao << "\n";
        }

    imprimirTabuleiro(tabuleiro,"Tabuleiro");
}


void exe34(){

    cout << "*******************************\n";
    cout << "34 - Oito rainhas recursivo    \n";
    cout << "*******************************\n";

    jogadas();


//    imprimirTabuleiro(tabuleiro,"Tabuleiro");
//    imprimirTabuleiro(alcancados,"alcancados");

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

//-------------36------------------//

void stringReverse(char arrei[], int inicio=0){

    int tamanho = tamanhoArrChar(arrei); // exe07_32
    cout << arrei[tamanho - inicio - 1] ;

    if (arrei[inicio]!='\0')
        stringReverse(arrei,inicio+1);
    else    
        cout << "\n";
 
}

void exe36(){

    cout << "*******************************\n";
    cout << "36 - String Reverse\n";
    cout << "*******************************\n";

    char arrei[] = "atlas salta";

    stringReverse(arrei);

}

//-------------37------------------//

int menor=9999;

int recursiveMinimum(int arrei[], int inicial,int final){

    //cout << "******\n";
    //cout << "inicial " << inicial << "\n";
    //cout << "final " << final << "\n";

    if (inicial > final || inicial+1>final){ // se já passou do limite
        return menor;
    }
    else{
        if (arrei[inicial] <= menor || arrei[final] <= menor )
            if (arrei[inicial] < arrei[final])
                menor=arrei[inicial];
            else 
                menor=arrei[final];
    
        //cout << "menor " << menor << "\n";

        return recursiveMinimum(arrei,inicial+1,final-1);
    }
        

}

void exe37(){

    cout << "*****************************************\n";
    cout << "37 - Localizar o valor mínimo em um array\n";
    cout << "*****************************************\n";

    const int tamanho=50;
    int numeros[tamanho]={6,3,2};

    for (int subscrito=0; subscrito<tamanho; subscrito++)
        numeros[subscrito]=gerarInteiro(1,999);


    cout << "recursiveMinimum " << recursiveMinimum(numeros,0,tamanho-1) << "\n";
}

void exe38(){
    cout << "*****************************************\n";
    cout << "38 - exe07_10 com vector<>\n";
    cout << "*****************************************\n";

    // Declarações de variavies e estruturas
    const int tamanhoFaixas=11
             ,tamanhoVendas=10;
    
    int subscrito;

    vector< int > faixas( tamanhoFaixas ); 
    vector< int > vendas( tamanhoVendas ); 

    // Randomizar e gerar o vetor vendas
    for (int i=0; i<tamanhoVendas; i++)
        vendas[i]=gerarInteiro(1,1099);


    imprimirVector(vendas,"vendas");

    for (int i=0; i<tamanhoVendas; i++){
        subscrito=vendas[i]/100;
        if (subscrito>10)
            subscrito = 10;
        
        faixas[subscrito]++;
    }

    imprimirVector(faixas,"faixas");

    cout << "Inicio\tFim\tQuant\tGráfico\n";
    for (int i=0; i<tamanhoFaixas; i++){
        cout << "$" << i*100    << "\t";
        cout << "$" << i*100+99 << "\t";
        cout << faixas[i]       << "\t";

        for (int g=1; g<=faixas[i]; g++)
            cout << "*";

        cout << "\n";
    }

}

void exe39(){
    cout << "*****************************************\n";
    cout << "39 - exe07_17 com vector<>               \n"; 
    cout << "*****************************************\n";

    const int tamanhoSomas=13;
    vector< int > somas( tamanhoSomas ); 
    //int tabela[7][7]={0};
    std::vector<std::vector<int>> tabela = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

}