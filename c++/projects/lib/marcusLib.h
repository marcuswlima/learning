#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//using std::cout;
//using std::cin;
//using std::endl;
//using std::setw;
//using std::string;
//using std::vector;


/*
Calcula o valor a ser cobrado do cliente de um estacionamento
*/
double calculateCharges (double);

/*
Realiza a potencia
*/
int integerPower(int, int);

/*
Realiza a potencia (recursivo)
*/
int power(int, int);

/*
Calcula o comprimento da hipotenusa de um triangulo retangulo
*/
double hypotenuse (double, double);

/*
Bolean - Indica se o primeiro inteiro é multiplo do segundo
*/
bool multiple (int, int);

/*
Imprime um quadrado no cout
*/
void imprimirQuadrado(int, char);

/*
Projeta em cout uma versão do inteiro onde cada algarismo estará separado por espaço em branco
*/
void separaInteiro (int);

/*
Recebe 3 valores double e indica qual é o menor
*/
double menorDe3 (double, double, double);

/*
Projeta em cout uma versão do inteiro onde cada algarismo estará separado por espaço em branco, 
porém invertido
*/
void separarAndInverter (int);

/*
Calcula o MDC de dois numeros inteiros
*/
int Mdc(int pri, int seg);


/*
Informa a faixa de media de uma media de nota
90>=nota<=100 -> 4
80>=nota<= 89 -> 3
70>=nota<= 79 -> 2
60>=nota<= 69 -> 1
    nota<  60 -> 0
*/
int qualityPoints (double);

/* Simula uma jogada de moeda caraXcoroa*/
int flip();

/*
Calcula o MDC de dois numeros inteiros por recursão
*/
int mdc_r(int, int);

/*
Imprime os valores de um array de inteiros e de uma dimensão
*/
void mostarArray( const int [], int , string="titulo" );

/*
Imprime os valores de um array de double e de uma dimensão
*/
void mostarArray( const double [], int , string="titulo");

/*
Imprime os valores de um array de int e de 2 dimensões 2 coluna
*/
void mostraArr2D(const int arrei[][2],int , int );
/*
Imprime os valores de um array de int e de 2 dimensões 3 coluna
*/
void mostraArr2D(const int arrei[][3],int , int );
/*
Imprime os valores de um array de int e de 2 dimensões 3 coluna
*/
void mostraArr2D(const int arrei[][5],int , int );

/*
Imprime os valores de um vector
*/
void imprimirVector( vector< int >, string="titulo");
