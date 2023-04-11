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
    this->Randomizar();
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
// Sets
/////////////////////////////////////////

// setar Int1
void Triade::setInt1(Intervalo i){
    i1 = i;
}

void Triade::setInt2(Intervalo i){
    i2 = i;
}


/////////////////////////////////////////
// Gets
/////////////////////////////////////////

Intervalo Triade::getInt1(){
    return i1;
}

Intervalo Triade::getInt2(){
    return i2;
}

Nota Triade::getFundamental(){
    return this->getInt1().getN1();
}
Nota Triade::getTerca(){
    return this->getInt1().getN2();

}
Nota Triade::getQuinta(){
    return this->getInt2().getN2();
}

/////////////////////////////////////////
// Padrão
/////////////////////////////////////////

void Triade::Randomizar(){

    int TipoTriade=RandomizarIdTipoTriade();
    Intervalo i1,i2; // 4 notas randomizadas

    MontarTriade(TipoTriade, i1, i2);

    this->setInt1(i1);
    this->setInt2(i2);

}

// ImprimirEmTela
string Triade::GerarDescricao(){
	string resposta="[", temp; 

    temp = this->getFundamental().GerarDescricao() + "-";
    if (temp!="") resposta+=temp;

    temp = this->getTerca().GerarDescricao() + "-";
    if (temp!="") resposta+=temp;

    temp = this->getQuinta().GerarDescricao();
    if (temp!="") resposta+=temp;

    resposta+="]";

	return resposta;
}

void Triade::ImprimirEmTela(){
	cout << this->GerarDescricao();
}



/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////



void Triade::ImprimirFundamentalEmTela(){
	cout << this->getFundamental().GerarDescricao();
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

