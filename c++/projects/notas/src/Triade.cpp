#include "Triade.h"

/////////////////////////////////////////
// Declarações
/////////////////////////////////////////

Nota GerarSegundaNota(Nota, string);
Nota GerarSegundaNota(Nota , int , int );
int RandomizarIdTipoTriade();

/////////////////////////////////////////
// construtores
/////////////////////////////////////////

// Construtor sem arguentos
Triade::Triade(){
}

Triade::Triade(Intervalo i){
    this->setInt1(i);
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

void Triade::setN1(Nota n){
    this-> getInt1().setN1(n);
}

Nota Triade::getN1(){
    return getInt1().getN1();
}

void Triade::setN3(Nota n){
    this-> getInt1().setN2(n);
    this-> getInt2().setN1(n);
}

Nota Triade::getN3(){
    return getInt1().getN2();
}

/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////

// ImprimirEmTela
void Triade::ImprimirEmTela(){
	cout << this->GerarDescricao();
}

string Triade::GerarDescricao(){
	string resposta=""; 
    resposta += this->getInt1().GerarDescricao()+ "\t";
    resposta += this->getInt2().getN2().GerarDescricao()+ "\t";
	return resposta;
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
    int tt=RandomizarIdTipoTriade();
    Nota novaNota;

    tt = 1;
    switch (tt)
    {
    case 1:
        {
            cout << "Randomizar Maior"<< endl;
            this->getInt1().getN1().ImprimirEmTela();
            cout << endl;
            novaNota=this->getInt1().CalcularSegundaNota("3M");
            novaNota.ImprimirEmTela();
            this->setN3(novaNota);
            cout << endl;
            //this->getInt2().setN1(this->getInt1().getN2());
            //this->getInt2().CalcularSegundaNota("3m");
        }
        break;
    case 2:
        {
            cout << "Randomizar Menor"<< endl;
            this->getInt1().CalcularSegundaNota("3m");
            this->getInt2().setN1(this->getInt1().getN2());
            this->getInt2().CalcularSegundaNota("3M");
        }
        break;
    
    default:
        break;
    }
}


/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////

int RandomizarIdTipoTriade(){
    return GerarInteiro(1,4);
}

/*

// GerarSegundaNota
Nota GerarSegundaNota(Nota t, string ti){
    int quantidadeNotas, quantidadeSemitons;

    if (ti=="2m"){
        quantidadeNotas=2;
		quantidadeSemitons=1;
    }else if (ti=="2M"){
        quantidadeNotas=2;
		quantidadeSemitons=3;
    }else if (ti=="3m"){
        quantidadeNotas=3;
		quantidadeSemitons=4;
    }else if (ti=="3M"){
        quantidadeNotas=3;
		quantidadeSemitons=5;
    }

    return GerarSegundaNota(t, quantidadeNotas, quantidadeSemitons);

}

void Triade::GerarTriade(Nota t, string tipoIntervalo){
    this->setN1(t);

    if (tipoIntervalo=="M"){
        this->setN3(GerarSegundaNota(t,"3M"));
        this->setN5(GerarSegundaNota(this->getN3(),"3m"));
    }else if (tipoIntervalo=="m"){
        this->setN3(GerarSegundaNota(t,"3m"));
        this->setN5(GerarSegundaNota(this->getN3(),"3M"));
    }else if (tipoIntervalo=="d"){
        this->setN3(GerarSegundaNota(t,"3m"));
        this->setN5(GerarSegundaNota(this->getN3(),"3m"));
    }else if (tipoIntervalo=="A"){
        this->setN3(GerarSegundaNota(t,"3M"));
        this->setN5(GerarSegundaNota(this->getN3(),"3M"));
    }

}

*/

/////////////////////////////////////////
// Lixao
/////////////////////////////////////////


/*
int umaoitava[]={0,1,0,2,0,3,4,0,5,0,6,0,7};
int RetornarSubescrito(int n){
    int resposta;
    for (int i=1;i<=12;i++){
        if (umaoitava[i]==n){
            resposta = i;
            break; 
        }
    }
    return resposta;
}


Nota GerarSegundaNota(Nota t, int quantidadeNotas, int quantidadeSemitons){
	Nota r;

    r = t.qualRelativa(quantidadeNotas);
    int sub1, sub2, diffSemiToms, a;
    sub1=RetornarSubescrito(t.getGrau()); //1
    sub2=RetornarSubescrito(r.getGrau()); //5

    if (t.getGrau()<r.getGrau()){
        diffSemiToms = (sub2-sub1+1);
    }else{
        diffSemiToms=(12-sub1)+sub2+1;
    }
    a = quantidadeSemitons - diffSemiToms + t.getAcidente();

	r.setAcidente(a);

	return r;
	
}
*/



/*

Tecla i3m(Tecla t){  //4 semitons
	Tecla r;
	int quantidadeNotas=3,
		quantidadeSemitons=4,
		o = t.getOitava(),
		n = t.getNota(),
		a = t.getAcidente();

	n += (quantidadeNotas-1);
	if (n>7){
		n -= 7;
		o++;
	}

    cout << "n " << n << endl;

    // t.getNota() x n
    int sub1=RetornarSubescrito(t.getNota()); //1
    int sub2=RetornarSubescrito(n);           //5
    int diffSemiToms = (sub2-sub1+1);
    a = quantidadeSemitons - diffSemiToms;

    //cout << "sub1 " << sub1 << endl;
    //cout << "sub2 " << sub2 << endl;
    //cout << "diffSemiToms " << diffSemiToms << endl;

	r.setOitava(o);
	r.setNota(n);
	r.setAcidente(a);

	return r;
	
}
Tecla i3M(Tecla t){
	Tecla r;
	int quantidadeNotas=3,
		quantidadeSemitons=5,
		o = t.getOitava(),
		n = t.getNota(),
		a = t.getAcidente();

    //cout << "n " << n << endl;

	//n += (quantidadeNotas-1);
	if (n>7){
		n -= 7;
		o++;
	}

    // t.getNota() x n
    int sub1=RetornarSubescrito(t.getNota()); //1
    int sub2=RetornarSubescrito(n);           //5
    int diffSemiToms = (sub2-sub1+1);
    a = quantidadeSemitons - diffSemiToms;

    //cout << "sub1 " << sub1 << endl;
    //cout << "sub2 " << sub2 << endl;
    //cout << "diffSemiToms " << diffSemiToms << endl;

	r.setOitava(o);
	r.setNota(n);
	r.setAcidente(a);

	return r;
}
 
Tecla gerar3M_2(Tecla t){
    Tecla r;

    r.setOitava(t.getOitava());
    r.setNota(t.getNota());
    r.setAcidente(t.getAcidente());

    aumentarAlturaEmUmTom_2(r);
    aumentarAlturaEmUmTom_2(r);
    return r;
}

void aumentarAlturaEmUmTom_2(Tecla &t){
    aumentarAlturaEmMeioTom_2(t);
    aumentarAlturaEmMeioTom_2(t);
}


// aumentar a tecla em 1/2 tom
void aumentarAlturaEmMeioTom_2(Tecla &t){

    if (t.getOitava()!=9){

        if (t.getAcidente()==0) {// teclas bancas 
            if (t.getNota() == 3)
                t.setNota(4);
            else if (t.getNota() == 7 ){
                t.setNota(1);
                t.setOitava(t.getOitava()+1);
            }
            else
                t.setAcidente(1);

        }
        else if (t.getAcidente()==1) {// notas sustenidas
            t.setNota(t.getNota()+1);
            t.setAcidente(0);
        }
        else if (t.getAcidente()==-1){

            //cout << "*" << getNota() << "-" << getAcidente() <<"*";
            t.setAcidente(0);
        }
    }
    else
        cout << "Ultima tecla";

}

*/
