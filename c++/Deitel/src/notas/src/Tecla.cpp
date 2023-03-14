#include <iostream>
#include <iomanip>
#include <stdexcept> // for invalid_argument exception class
#include "Tecla.h"
#include "/home/marcus/Developer/github/learning/c++/Deitel/src/lib/marcusLib.h"
//#include "marcusLib.h"

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
    setOitava(4);
    setNota(1);
    setAcidente(0);
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

void Tecla::imprimirTecla(){

    string strNota;

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

    if (this->getAcidente() == -1)
        strNota += "b";
    else if (this->getAcidente()==1)
        strNota += "#";
    else if (this->getAcidente()==-2)
        strNota += "bb";
    else if (this->getAcidente()==2)
        strNota += "*";
    

    //if      (strNota == "Do#")  strNota="Reb";
    //else if (strNota == "Re#")  strNota="Mib";
    //else if (strNota == "Sol#") strNota="Lab";
    //else if (strNota == "La#")  strNota="Sib";
    //else if (strNota == "Solb") strNota="Fa#";

    cout << this->getOitava() << strNota << "\t";

}

void Tecla::aleatorio(){

    do{

        //setOitava(gerarInteiro(0,9));
          setOitava(gerarInteiro( 3,4));
            setNota(gerarInteiro( 1,7));
        setAcidente(gerarInteiro(-2,2));

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