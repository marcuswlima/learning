#include "Triade.h"

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////

Nota GerarSegundaNota(Nota, string);
Nota GerarSegundaNota(Nota , int , int );
int RandomizarIdTipoTriade();
void MontarTriade(Nota, int, Intervalo &, Intervalo &);

/////////////////////////////////////////
// construtores
/////////////////////////////////////////

Triade::Triade(){
}

Triade::Triade(int dificuldade){
	this->Randomizar(dificuldade);
}

Triade::Triade(Nota n,int tipoTriade){
	this->setTriade(n,tipoTriade);
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

void Triade::setTriade(Nota n,int tipoTriade){
	Intervalo i1, i2;

	MontarTriade(n,tipoTriade,i1,i2);
    
	this->setInt1(i1);
    this->setInt2(i2);
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
	
	MontarTriade(n,tipoTriade,i1,i2);
    
	this->setInt1(i1);
    this->setInt2(i2);

}//Randomizar

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
	string tipoIntervalo, resp;

//	tipoIntervalo = this->getInt1().DeduzirTipoIntervalo();
//	resp += this->getInt1().GerarDescricao();
	resp += this->getInt1().DeduzirTipoIntervalo();
//	resp += tipoIntervalo;
	
//	tipoIntervalo = this->getInt2().DeduzirTipoIntervalo();
//	resp += tipoIntervalo;

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

int RandomizarIdTipoTriade(){
    return GerarInteiro(1,4);
}

void MontarTriade(Nota n, int tipoTriade, Intervalo &i1, Intervalo &i2){

	Nota temp;

//	cout << "tipoTriade->"<< tipoTriade<< endl;

	i1.setN1(n);
	if (tipoTriade==1){
		i1.setN2("3M");
		temp.setOitava(i1.getN2().getOitava());
		temp.setGrau(i1.getN2().getGrau());
		temp.setAcidente(i1.getN2().getAcidente());
		i2.setN1(temp);
		i2.setN2("3m");
	}else if (tipoTriade==2){
//		cout << "acertou" << endl;
		i1.setN2("3m");
//		i1.ImprimirEmTela();
		temp.setOitava(i1.getN2().getOitava());
		temp.setGrau(i1.getN2().getGrau());
		temp.setAcidente(i1.getN2().getAcidente());
//		temp.ImprimirEmTela();
		i2.setN1(temp);
		i2.setN2("3M");
	}else if (tipoTriade==3){
		i1.setN2("3M");
		temp.setOitava(i1.getN2().getOitava());
		temp.setGrau(i1.getN2().getGrau());
		temp.setAcidente(i1.getN2().getAcidente());
		i2.setN1(temp);
		i2.setN2("3M");
	}else if (tipoTriade==4){
		i1.setN2("3m");
		temp.setOitava(i1.getN2().getOitava());
		temp.setGrau(i1.getN2().getGrau());
		temp.setAcidente(i1.getN2().getAcidente());
		i2.setN1(temp);
		i2.setN2("3m");
	}

}

