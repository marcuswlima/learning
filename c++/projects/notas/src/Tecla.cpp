#include "Tecla.h"
#include "../../lib/Mathematics.h"

using namespace std;

/////////////////////////////////////////
// Declarações
/////////////////////////////////////////
bool teclaValida( int o, int n, int a );

/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Tecla::Tecla()
{
    //setOitava(0);
    //setNota(1);
    //setAcidente(0);
} 

Tecla::Tecla(int o, int n, int a)
{
    setTecla( o, n, a );
} 

/////////////////////////////////////////
// Acesso Propriedades
/////////////////////////////////////////

void Tecla::setOitava(int o){
    oitava = o;
}

void Tecla::setNota(int n){
    nota = n;
    //cout<<"setNota"<<n<<"\t";
}

void Tecla::setAcidente(int a){
    acidente = a;
}

int Tecla::getOitava(){
    return oitava;
}

int Tecla::getNota(){
    return nota;
}

int Tecla::getAcidente(){
    return acidente;
}

/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////


Tecla Tecla::qualRelativa(int relativa){
    Tecla resposta;

    int o=this->getOitava()
       ,n=this->getNota()
       ,a=this->getAcidente();

    n = n + relativa - 1;
    if (n>=8){
        n -= 7;
        o++;
    }

    resposta.setOitava(o);
    resposta.setNota(n);
    resposta.setAcidente(a);

    return resposta;

}

// atribuir novos valores oitava, nota e acidente
void Tecla::setTecla( int o, int n, int a )
{
    if (teclaValida(o,n,a)){
        setOitava(o);
        setNota(n);
        setAcidente(a);
    }
    else{
        cout << "Oitava   -> " << o 
             << "Nota     -> " << n
             << "Acidente -> " << a;

        throw invalid_argument("Oitava, nota e/ou acidente inválido");
    }

}

string Tecla::GerarDescricao(){
    string strNota;

    strNota = to_string(this->getOitava());

    switch (this->getNota())
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

void Tecla::ImprimirEmTela(){

    cout << this->GerarDescricao()<< " ";

}

void Tecla::Aleatorio(){

    do{
          setOitava(GerarInteiro( 0,9));
            setNota(GerarInteiro( 1,7));
        setAcidente(GerarInteiro(-1,1));
    }while(!teclaValida(getOitava(),getNota(),getAcidente()));

}


/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////
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
