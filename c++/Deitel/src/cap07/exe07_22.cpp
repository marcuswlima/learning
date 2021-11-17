#include <iostream>
using std::cout;

#include "../lib/marcusLib.h"

#include <string>
using std::string;

#include <iomanip>
using std::setw;

void mostraArr(const int arrei[][5],int linhas, int colunas, string titulo);
void mostraArr(const int arrei[][6],int linhas, int colunas, string titulo);
void mostraArr(const int arrei[][31],int linhas, int colunas, string titulo);

int main(){

    srand( time(0) );

    const int produtosSize=1+5, equipesSize=1+4, diasSize=1+30;
    int vendas[produtosSize][equipesSize][diasSize];

    //gerar os valores
    for (int p=1; p<produtosSize; p++)
        for (int e=1; e<equipesSize; e++)
            for (int d=1; d<diasSize; d++)
                vendas[p][e][d]=gerarInteiro(1,2);
    

    //produto X equipe
    int bidimensional1[produtosSize][equipesSize]={0};
    for (int p=1; p<produtosSize; p++)
        for (int e=1; e<equipesSize; e++)
            for (int d=1; d<diasSize; d++)
                bidimensional1[p][e] += vendas[p][e][d];
    
    mostraArr(bidimensional1,produtosSize,equipesSize,"produto X equipe");

    //produto X dias
    int bidimensional4[produtosSize][diasSize]={0};
    for (int p=1; p<produtosSize; p++)
        for (int d=1; d<diasSize; d++)
            for (int e=1; e<equipesSize; e++)
                bidimensional4[p][d] += vendas[p][e][d];
    mostraArr(bidimensional4,produtosSize,diasSize,"produto X dias");



    //dias X produto
    int bidimensional2[diasSize][produtosSize]={0};
    for (int d=1; d<diasSize; d++)
        for (int p=1; p<produtosSize; p++)
            for (int e=1; e<equipesSize; e++)
                bidimensional2[d][p] += vendas[p][e][d];

    mostraArr(bidimensional2,diasSize,produtosSize, "dias X produto");

    //dias X equipe
    int bidimensional3[diasSize][equipesSize]={0};
    for (int d=1; d<diasSize; d++)
        for (int e=1; e<equipesSize; e++)
            for (int p=1; p<produtosSize; p++)
                bidimensional3[d][e] += vendas[p][e][d];
    mostraArr(bidimensional3,diasSize,equipesSize, "dias X equipe");

    return 0;
}

void mostraArr(const int arrei[][5],int linhas, int colunas, string titulo){
    int totalLinha;    
    cout << titulo << "\n";
    cout << "\t";
    for ( int coluna = 1; coluna < colunas; coluna++ )
        cout << "[" << coluna << "]\t";
    cout << "Total\n";

    for ( int linha = 1; linha < linhas; linha++ ) {
        totalLinha=0;
        cout << "[" << linha << "]\t"; 
        for ( int coluna = 1; coluna < colunas; coluna++ ){
            cout << arrei[ linha ][ coluna ] << "\t";
            totalLinha += arrei[ linha ][ coluna ];
        }
        cout << totalLinha;

        cout << "\n";
    }

    // total colunas
    int totalColuna;
    cout << "Total\t";
    for ( int coluna = 1; coluna < colunas; coluna++ ){
        totalColuna=0;
        for ( int linha = 1; linha < linhas; linha++ ) {
            totalColuna += arrei[ linha ][ coluna ];
        }
        cout << totalColuna << "\t";
    }
    cout << "\n";
    cout << "\n";

}

void mostraArr(const int arrei[][6],int linhas, int colunas, string titulo){
    int totalLinha;    
    cout << titulo << "\n";
    cout << "\t";
    for ( int coluna = 1; coluna < colunas; coluna++ )
        cout << "[" << coluna << "]\t";
    cout << "Total\n";

    for ( int linha = 1; linha < linhas; linha++ ) {
        totalLinha=0;
        cout << "[" << linha << "]\t"; 
        for ( int coluna = 1; coluna < colunas; coluna++ ){
            cout << arrei[ linha ][ coluna ] << "\t";
            totalLinha += arrei[ linha ][ coluna ];
        }
        cout << totalLinha;

        cout << "\n";
    }

    // total colunas
    int totalColuna;
    cout << "Total\t";
    for ( int coluna = 1; coluna < colunas; coluna++ ){
        totalColuna=0;
        for ( int linha = 1; linha < linhas; linha++ ) {
            totalColuna += arrei[ linha ][ coluna ];
        }
        cout << totalColuna << "\t";
    }
    cout << "\n";
    cout << "\n";

}

void mostraArr(const int arrei[][31],int linhas, int colunas, string titulo){
    int totalLinha;    
    cout << titulo << "\n";
    cout << "\t";
    for ( int coluna = 1; coluna < colunas; coluna++ )
        cout << "[" << coluna << "]\t";
    cout << "Total\n";

    for ( int linha = 1; linha < linhas; linha++ ) {
        totalLinha=0;
        cout << "[" << linha << "]\t"; 
        for ( int coluna = 1; coluna < colunas; coluna++ ){
            cout << arrei[ linha ][ coluna ] << "\t";
            totalLinha += arrei[ linha ][ coluna ];
        }
        cout << totalLinha;

        cout << "\n";
    }

    // total colunas
    int totalColuna;
    cout << "Total\t";
    for ( int coluna = 1; coluna < colunas; coluna++ ){
        totalColuna=0;
        for ( int linha = 1; linha < linhas; linha++ ) {
            totalColuna += arrei[ linha ][ coluna ];
        }
        cout << totalColuna << "\t";
    }
    cout << "\n";
    cout << "\n";

}

