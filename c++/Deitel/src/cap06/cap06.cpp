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
 ** gerarDouble
**********************************/
double gerarDouble(int menor, int maior){

    return gerarInteiro(menor, maior)+ static_cast< double >(gerarInteiro(0,9999))/10000;

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


/********************************************************
** double menorDe3 (double d1, double d2, double d3)
*********************************************************/
double menorDe3 (double d1, double d2, double d3) {
    double resposta ;

    if ((d1 < d2) && (d1 < d3))
        resposta = d1;

    if ((d2 < d1) && (d2 < d3))
        resposta = d2;

    if ((d3 < d1) && (d3 < d2))
        resposta = d3;
    
    return resposta;

}

void separarAndInverter (int entrou){

    cout << entrou%10 << " ";
    if ( entrou/10 != 0 ){ 
        separarAndInverter(entrou/10);
    }

} 