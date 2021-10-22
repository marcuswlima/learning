#include <iostream>
using std::cout;
using std::endl;
#include <string> 
#include <cmath>
#include "cap06.h"


/**********************************
 ** calculateCharges
**********************************/
double calculateCharges (double in_horas) {

    int    iHorasTaxaMinima=3;
    double dTaxaMinima=2, dResposta, dExcedido;

    if ( in_horas < 24 ) {

        dResposta = dTaxaMinima;
        if ( in_horas > iHorasTaxaMinima ) {
            dExcedido = (in_horas - iHorasTaxaMinima);
            dResposta += (dExcedido*0.5);
        }
    }
    else
       dResposta = 10 ;

    return dResposta;
}


/**********************************
 ** gerarInteiro
**********************************/
int gerarInteiro(int menor, int maior) {

    if (maior > menor){
        int faixa  = (maior - menor + 1);
        int gerado = (1 + rand() % faixa);
        return menor + (gerado-1);
    }
    else
        return 0;

}

/**********************************
 ** ehPar(int entrada)
**********************************/
bool ehPar(int entrada){
    int resto = entrada % 2;

    if (resto == 0)
        return true;
    else
        return false;
}


/**********************************
** int integerPower
**********************************/
int integerPower(int base, int expoent){
    int resposta=1;

    if (expoent==0)
        resposta = 1;
    else 
        for (int i=1; i<=expoent; i++)
            resposta *= base;
    
    return resposta;

}


/**********************************
** double hypotenuse
**********************************/
double hypotenuse (double c1, double c2){

    return sqrt ( integerPower(c1,2) + integerPower(c2,2) );

}

/**********************************
** bool multiple (int n1, int n2)
**********************************/
bool multiple (int n1, int n2){
    int resto;
    // n1 é multiplo de n2 ???
    if ( n2 > n1 )
        return false;
    else {
        resto = n1 % n2 ;
        if ( resto == 0 )
            return true;
        else    
            return false;
    }
}

/**********************************
** void imprimirQuadrado
**********************************/
void imprimirQuadrado(int lado, char caracterDePreenchimento){
    cout << endl;
    for(int x=1;x<=lado;x++){
        for (int y=1;y<=lado;y++)
            cout << caracterDePreenchimento;
        cout << endl;
    }
    cout << endl;
}

