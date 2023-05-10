#include "Nota.h"

/////////////////////////////////////////
// Prototipacoes
/////////////////////////////////////////
bool notaValida( int, int, int);
string in_GerarDescricao( int, int, int);
void MensagemErro( int,int, int, bool);
/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Nota::Nota()
{
} 

Nota::Nota(int dificauldade)
{
    this->Randomizar(dificauldade);
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

double Nota::getId(){
    return (this->getOitava()*10)+
            this->getGrau()+
            (this->getAcidente()/2);
}

/////////////////////////////////////////
// Padrão
/////////////////////////////////////////

// Randomizar uma nota
void Nota::Randomizar(int in_dificuldade){

    int acidente;

    do{
        setOitava(GerarInteiro(1,7));
        setGrau(GerarInteiro(1,7));
        
        switch (in_dificuldade)
        {
            case 1:acidente = 0;break;
            case 2:acidente = GerarInteiro(-1,1);break;
            case 3:acidente = GerarInteiro(-2,2);break;
            default:break;
        }
        this->setAcidente(acidente);
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
        MensagemErro(o,g,a,true);

    return strNota;

}

void Nota::ImprimirEmTela(){

    cout << this->GerarDescricao()<< " ";

}

/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////


// Retornar a relativa
Nota Nota::qualRelativa(int relativa, int orientacao){
    Nota resposta;

    int o=this->getOitava()
       ,g=this->getGrau()
       ,a=this->getAcidente();

    if (orientacao==1){
        g = g + relativa - 1;
        if (g>=8){
            g -= 7;
            o++;
        }
    }else if (orientacao==-1){
        g = g - relativa + 1;
        if (g<=0){
            g += 7;
            o--;
        }

    }

    resposta.setOitava(o);
    resposta.setGrau(g);
    resposta.setAcidente(a);

    return resposta;

}

void Nota::up1Semitom(){
    int acidente=this->getAcidente();
    int grau=this->getGrau();
    int oitava=this->getOitava();

    if (acidente==-1){
        this->setAcidente(0);
    }else if((acidente==0)){
        if (grau==3){
            this->setGrau(++grau);
        }else if (grau==7){
            this->setOitava(++oitava);
            this->setGrau(1);
        }else{
            this->setAcidente(1);
        }
    }else if((acidente==1)){
        this->setAcidente(0);
        this->setGrau(++grau);
    }

}

void Nota::down1Semitom(){
    int acidente=this->getAcidente();
    int grau=this->getGrau();
    int oitava=this->getOitava();
    if (acidente==1){
        this->setAcidente(0);
    }else if((acidente==0)){
        if (grau==4){
            this->setGrau(--grau);
        }else if (grau==1){
            this->setOitava(--oitava);
            this->setGrau(7);
        }else{
            this->setAcidente(-1);
        }
    }else if((acidente==-1)){
        this->setAcidente(0);
        this->setGrau(--grau);
    }
}

void Nota:: up1Tom(){
    this->up1Semitom();
    this->up1Semitom();
}
void Nota::down1Tom(){
    this->down1Semitom();
    this->down1Semitom();
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
//        cout << "Oitava, nota e/ou acidente invalido\t";
        if (mostraValores){
             cout << o << '/';
             cout << g << '/';
             cout << a;
        }
//        cout << endl;
}
