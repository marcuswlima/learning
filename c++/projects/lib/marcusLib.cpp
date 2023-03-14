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
//int flip() {
//    return gerarInteiro(0,1);
//}

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
** void mostarArrayInt
*********************************************************/
void imprimirVector( vector< int > vetor, string titulo ){
    if (titulo!="titulo")
        cout << titulo << "\n";
    
    for ( int i = 0; i < vetor.size(); i++ )
        cout << "[" << i << "]=" << vetor[i] << " ";

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

void mostraArr2D(const int arrei[][5],int linhas, int colunas){
    cout << "\n";
    // copia notas de gradeArray para grades
    for ( int linha = 0; linha < linhas; linha++ ) {
        for ( int coluna = 0; coluna < colunas; coluna++ )
            cout << "[" << linha << "," << coluna << "]="  << arrei[ linha ][ coluna ] << " ";

        cout << "\n";
    }

}
