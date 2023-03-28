#include "Nota.h"

using namespace std;

/////////////////////////////////////////
// Declarações
/////////////////////////////////////////
bool teclaValida( int, int, int);

/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Nota::Nota()
{
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
          setOitava(GerarInteiro( 1,7));
            setGrau(GerarInteiro( 1,7));
        setAcidente(GerarInteiro(-2,2));
    }while(!teclaValida(getOitava(),getGrau(),getAcidente()));

}


/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////


bool teclaValida( int o, int g, int a ){

    /* 
       1) Sete oitavas completas em um piano [1:7]
       2) graus validos [1:7]
       3) acidentes válidos[-2:2]
    */

    bool bValido=true;

    if ( o < 1 || o > 7 )
        bValido = false;
    else 
        if ( g < 1 || g > 7 )    //faixa de nota
            bValido = false;
        else
            if ( a < -2 || a > 2 )    //acidente
                bValido = false;

    return bValido;
    //return true;
}
