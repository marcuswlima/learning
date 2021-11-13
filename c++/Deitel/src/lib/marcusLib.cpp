#include <iostream>
using std::cout;
using std::endl;
#include <string> 
#include <cmath>
#include "marcusLib.h"

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
** int power
**********************************/
int power(int base, int expoent){

    if (expoent==0) 
        return 1;
    else
        return base * power(base,expoent-1);

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

/********************************************************
** separarAndInverter (int entrou)
*********************************************************/
void separarAndInverter (int entrou){

    cout << entrou%10 << " ";
    if ( entrou/10 != 0 )
        separarAndInverter(entrou/10);

} 


/********************************************************
** bool prime(int entrou)
*********************************************************/
bool prime(int entrou){
    bool isPrime=true;

    if (entrou!= 0 && entrou!=1){
        for (int i=2 ; i<=entrou/2 ; ++i){

            if (entrou%i==0){ 
                isPrime = false;
                break;
            }
        };
    }
    return isPrime;
} 

/********************************************************
** int mdc(int pri, int seg)
*********************************************************/
int mdc(int pri, int seg){
    int maior,menor;

    if (pri>seg){
        maior=pri;
        menor=seg;
    }
    else
        if (pri<seg){
            maior=seg;
            menor=pri;
        };

    for (int i=menor/2;i>=1;i--){
        if (multiple(maior,i) && multiple(menor,i))
            return i;
    }

    return 0;
}

/********************************************************
** int qualityPoints
*********************************************************/
int qualityPoints (double media){

    if (media>=90 && media <=100)
        return 4;
    
    if (media>=80 && media <=89)
        return 3;

    if (media>=70 && media <=79)
        return 2;

    if (media>=60 && media <=69)
        return 1;
    
    return 0;
}

/********************************************************
** int flip()
*********************************************************/
int flip() {
    return gerarInteiro(0,1);
}

/********************************************************
** int mdc_r(int pri, int seg)
*********************************************************/
int mdc_r(int x, int y){
    int maior,menor;

    if (x>y){
        maior=x;
        menor=y;
    }else if (x<y){
        maior=y;
        menor=x;
    };

    if (menor==0)
        return maior;
    else {
        return mdc_r(menor, maior % menor);
    }

}


/********************************************************
** int mdc_r(int pri, int seg)
*********************************************************/
void mostarArray( const int arrei[], int sizeOfArray ){

    for (int i=0;i<sizeOfArray;i++)
        cout << "[" << i << "]=" << arrei[i] << " ";

    cout << "\n";

}

/********************************************************
** void mostarArrayInt
*********************************************************/
void mostarArray( const double arrei[], int sizeOfArray ){

    for (int i=0;i<sizeOfArray;i++)
        cout << "[" << i << "]=" << arrei[i] << " ";

    cout << "\n";

}


void mostraArr2D(const int arrei[][2],int linhas, int colunas){
    cout << "\n";
    // copia notas de gradeArray para grades
    for ( int linha = 0; linha < linhas; linha++ ) {
        for ( int coluna = 0; coluna < colunas; coluna++ )
            cout << "[" << linha << "," << coluna << "]="  << arrei[ linha ][ coluna ] << " ";

        cout << "\n";
    }

}

void mostraArr2D(const int arrei[][3],int linhas, int colunas){
    cout << "\n";
    // copia notas de gradeArray para grades
    for ( int linha = 0; linha < linhas; linha++ ) {
        for ( int coluna = 0; coluna < colunas; coluna++ )
            cout << "[" << linha << "," << coluna << "]="  << arrei[ linha ][ coluna ] << " ";

        cout << "\n";
    }

}