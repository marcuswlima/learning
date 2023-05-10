#include "Triade.h"

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////

Nota GerarSegundaNota(Nota, string);
Nota GerarSegundaNota(Nota , int , int );
int RandomizarIdTipoTriade();

/////////////////////////////////////////
// construtores
/////////////////////////////////////////

Triade::Triade(){
}

Triade::Triade(int dificuldade){
	this->Randomizar(dificuldade);
}

Triade::Triade(Intervalo i1, Intervalo i2){
    this->setInt1(i1);
    this->setInt2(i2);
}

/////////////////////////////////////////
// Sets
/////////////////////////////////////////
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

void Triade::Randomizar(int dificuldade){

	int       tipoTriade=RandomizarIdTipoTriade();
	Nota      n(dificuldade);
	Intervalo i1,i2;

	i1.setN1(n);	
	(tipoTriade==1)||(tipoTriade==3) 
        ? i1.setN2("3M",1) 
        : i1.setN2("3m",1);

    n=i1.getN2();

    i2.setN1(n);
    (tipoTriade==2)||(tipoTriade==3) 
        ? i2.setN2("3M",1) 
        : i2.setN2("3m",1);
    
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


string Triade::DeduzirTipoTriade(){
	string tipoIntervalo1, tipoIntervalo2, resp;

	tipoIntervalo1 = this->getInt1().DeduzirTipoIntervalo();
	tipoIntervalo2 = this->getInt2().DeduzirTipoIntervalo();

	resp += tipoIntervalo1;
	resp += tipoIntervalo2;
/*
	if      (resp=="3M3m") resp = "M";
	else if (resp=="3m3M") resp = "m";
	else if (resp=="3M3M") resp = "A";
	else if (resp=="3m3m") resp = "d";
*/
	return resp;

}


void Triade::ImprimirTipoTriadeEmTela(){
	cout << this->DeduzirTipoTriade();
}


/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////

void MontarTriade(int TipoTriade, Intervalo &i1, Intervalo &i2){

    (TipoTriade==1)||(TipoTriade==3) 
        ? i1.setN2("3M",1) 
        : i1.setN2("3m",1);

    Nota n;
    n=i1.getN2();

    i2.setN1(n);
    (TipoTriade==2)||(TipoTriade==3) 
        ? i2.setN2("3M",1) 
        : i2.setN2("3m",1);
}

int RandomizarIdTipoTriade(){
    return GerarInteiro(1,4);
}

