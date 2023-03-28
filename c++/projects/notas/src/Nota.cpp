#include "Nota.h"
#include "../../lib/Mathematics.h"

using namespace std;

/////////////////////////////////////////
// Declarações
/////////////////////////////////////////
bool teclaValida( int, int, int);
void Aleatorio(Nota n);

/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Nota::Nota()
{
    this->setNota( 
                   GerarInteiro( 0,9), // oitava
                   GerarInteiro( 1,7), // grau
                   GerarInteiro(-1,1)  // acidente
                 );
} 

Nota::Nota(int o, int g, int a)
{
    this->setNota( o, g, a );
} 

/////////////////////////////////////////
// Acesso Propriedades
/////////////////////////////////////////

void Nota::setOitava(int o){
    oitava = o;
}

void Nota::setGrau(int g){
    grau = g;
}

void Nota::setAcidente(int a){
    acidente = a;
}

int Nota::getOitava(){
    return oitava;
}

int Nota::getGrau(){
    return grau;
}

int Nota::getAcidente(){
    return acidente;
}

/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////


Nota Nota::qualRelativa(int relativa){
    Nota resposta;

    int o=this->getOitava()
       ,g=this->getGrau()
       ,a=this->getAcidente();

    g = g + relativa - 1;
    if (g>=8){
        g -= 7;
        o++;
    }

    resposta.setOitava(o);
    resposta.setGrau(g);
    resposta.setAcidente(a);

    return resposta;

}

// atribuir novos valores oitava, nota e acidente
void Nota::setNota( int o, int g, int a )
{
    if (teclaValida(o,g,a)){
        setOitava(o);
        setGrau(g);
        setAcidente(a);
    }
    else{
        cout << "Oitava   -> " << o 
             << "Nota     -> " << g
             << "Acidente -> " << a;

        throw invalid_argument("Oitava, nota e/ou acidente inválido");
    }

}

string Nota::GerarDescricao(){
    string strNota;

    strNota = to_string(this->getOitava());

    switch (this->getGrau())
    {
        case 1:strNota+="Do" ;break;
        case 2:strNota+="Re" ;break;
        case 3:strNota+="Mi" ;break;
        case 4:strNota+="Fa" ;break;
        case 5:strNota+="Sol";break;
        case 6:strNota+="La" ;break;
        case 7:strNota+="Si" ;break;
    default:
        break;
    }

    switch (this->getAcidente())
    {
        case -2:strNota += "bb";break;
        case -1:strNota += "b";break;
        case  1:strNota += "#";break;
        case  2:strNota += "*";break;
    default:
        break;
    }

    return strNota;

}

void Nota::ImprimirEmTela(){

    cout << this->GerarDescricao()<< " ";

}

void Nota::Aleatorio(){

    do{
          setOitava(GerarInteiro( 0,9));
            setGrau(GerarInteiro( 1,7));
        setAcidente(GerarInteiro(-1,1));
    }while(!teclaValida(getOitava(),getGrau(),getAcidente()));

}


/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////


void Aleatorio(Nota n){

    do{
          n.setOitava(GerarInteiro( 0,9));
            n.setGrau(GerarInteiro( 1,7));
        n.setAcidente(GerarInteiro(-1,1));
    }while(!teclaValida(n.getOitava(),n.getGrau(),n.getAcidente()));

}

bool teclaValida( int o, int n, int a ){

    /* 
       1) Sete oitavas(1-7) completas em um piano
       2) a oitava de ID 0 tem apenas 3 teclas (6 e 7)
       3) a últiam tecla percente a oitava oitava de apenas uma nota (1)
    */

    bool valido=true;

    if ( o < 0 || o > 8 )
        valido = false;
    else 
        if (
            ( o == 0 && n <= 5 ) || //inicio do teclado
            ( o == 8 && n != 1 ) || //final do teclado
            ( n <= 0 || n >= 8 )    //faixa de nota
        )
            valido = false;
        else
            if (
                    ((n == 1) && (a ==-1)) || // do-bemol
                    ((n == 3) && (a == 1)) || // mi-sustenido
                    ((n == 4) && (a ==-1)) || // fa-bemol
                    ((n == 7) && (a == 1))    // si-sustenido
            )
                valido = false;

    return valido;
}
