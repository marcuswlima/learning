#include "Nota.h"

using namespace std;

/////////////////////////////////////////
// Declarações
/////////////////////////////////////////
bool notaValida( int, int, int);
string in_GerarDescricao( int, int, int);
void MensagemErro( int,int, int, bool);
/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Nota::Nota()
{
    this->Randomizar();
} 

Nota::Nota(int o, int g, int a)
{
    this->setNota( o, g, a );
} 

/////////////////////////////////////////
// Sets
/////////////////////////////////////////

// Setar atributo oitava
void Nota::setOitava(int o){
    oitava = o;
}

void Nota::setGrau(int g){
    grau = g;
}

void Nota::setAcidente(int a){
    acidente = a;
}

/////////////////////////////////////////
// Gets
/////////////////////////////////////////

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
// Padrão
/////////////////////////////////////////

// Randomizar uma nota
void Nota::Randomizar(){

    do{
          setOitava(GerarInteiro( 1,7));
            setGrau(GerarInteiro( 1,7));
        setAcidente(GerarInteiro(-2,2));
        setAcidente(GerarInteiro(-1,1));
        setAcidente(0);
    }while(!notaValida(this->getOitava(),this->getGrau(),this->getAcidente()));

}

string Nota::GerarDescricao(){
    string strNota;
    int o = this->getOitava();
    int g = this->getGrau();
    int a = this->getAcidente();

    if (notaValida(o,g,a))
        strNota = in_GerarDescricao(o,g,a);
    else
        MensagemErro(o,g,a,false);

    return strNota;

}

void Nota::ImprimirEmTela(){

    cout << this->GerarDescricao()<< " ";

}


/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////


// Retornar a relativa
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
    if (notaValida(o,g,a)){
        setOitava(o);
        setGrau(g);
        setAcidente(a);
    }
    else
        MensagemErro(o,g,a, true);

}




/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////

// Validar uma nota
bool notaValida( int o, int g, int a ){

    /* 
       1) Sete oitavas completas em um piano [1:7]
       2) graus validos [1:7]
       3) acidentes válidos[-2:2]
    */

    bool bValido=true;

    if ( o < 1 || o > 8 ) //oitava
        bValido = false;
    else 
        if ( g < 1 || g > 7 )    //grau
            bValido = false;
        else
            if ( a < -2 || a > 2 )  //acidente
                bValido = false;

    return bValido;
}


string in_GerarDescricao( int o, int g, int a ){
    string strNota;

    strNota = to_string(o);

    switch (g)
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

    switch (a)
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

void MensagemErro( int o, int g, int a, bool mostraValores ){
        cout << "Oitava, nota e/ou acidente invalido\t";
        if (mostraValores){
             cout << "Oitava -> "   << o << "\t";
             cout << "Nota -> "     << g << "\t";
             cout << "Acidente -> " << a;
        }
        cout << endl;
}
