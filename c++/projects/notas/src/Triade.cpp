#include "Triade.h"

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////

Nota GerarSegundaNota(Nota, string);
Nota GerarSegundaNota(Nota , int , int );
int RandomizarIdTipoTriade();
void MontarTriade(int TipoTriade, Intervalo &, Intervalo &);

/////////////////////////////////////////
// construtores
/////////////////////////////////////////

// Construtor sem arguentos
Triade::Triade(){
    this->RandomizarTriade();
}

Triade::Triade(Intervalo i1){

    int TipoTriade=RandomizarIdTipoTriade();
    Intervalo i2; // 4 notas randomizadas

    MontarTriade(TipoTriade, i1, i2);

    this->setInt1(i1);
    this->setInt2(i2);

}

Triade::Triade(Intervalo i1, Intervalo i2){
    this->setInt1(i1);
    this->setInt2(i2);
}

/////////////////////////////////////////
// Gets&Sets
/////////////////////////////////////////

// setar Int1
void Triade::setInt1(Intervalo i){
    i1 = i;
}

Intervalo Triade::getInt1(){
    return i1;
}

void Triade::setInt2(Intervalo i){
    i2 = i;
}

Intervalo Triade::getInt2(){
    return i2;
}

void Triade::setTipoTriade(char tt){
    tipoTriade = tt;

}
char Triade::getTipoTriade(){
    return tipoTriade;
}
/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////

// ImprimirEmTela
string Triade::GerarDescricao(){
	string resposta="[", temp; 

    temp = this->getInt1().getN1().GerarDescricao() + "-";
    if (temp!="") resposta+=temp;

    temp = this->getInt1().getN2().GerarDescricao() + "-";
    if (temp!="") resposta+=temp;

    temp = this->getInt2().getN2().GerarDescricao();
    if (temp!="") resposta+=temp;

    resposta+="]";

	return resposta;
}


void Triade::ImprimirEmTela(){
	cout << this->GerarDescricao();
}

void Triade::ImprimirFundamentalEmTela(){
	cout << this->getInt1().getN1().GerarDescricao();
}


string Triade::RandomizarTipoTriade(){
	int idTriade=RandomizarIdTipoTriade();
	string descTriade; 

	switch (idTriade){
    	case 1:descTriade="M";break;
    	case 2:descTriade="m";break;
    	case 3:descTriade="A";break;
    	case 4:descTriade="d";break;
	}

	return descTriade;

}

void Triade::RandomizarTriade(){

    int TipoTriade=RandomizarIdTipoTriade();
    Intervalo i1,i2; // 4 notas randomizadas

    MontarTriade(TipoTriade, i1, i2);

    this->setInt1(i1);
    this->setInt2(i2);

}

/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////

void MontarTriade(int TipoTriade, Intervalo &i1, Intervalo &i2){
    Nota n;

    if ((TipoTriade==1)||(TipoTriade==3)) // maior ou aumentada
        i1.setN2("3M");
    else
        i1.setN2("3m");     // menor ou diminuta
    
    n=i1.getN2();

    i2.setN1(n);

    if ((TipoTriade==2)||(TipoTriade==3)) // menor ou aumentada
        i2.setN2("3M");
    else
        i2.setN2("3m");     // maior ou diminuta
}

int RandomizarIdTipoTriade(){
    return GerarInteiro(1,4);
}

