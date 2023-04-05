#include "Intervalo.h"

/////////////////////////////////////////
// Declarations
/////////////////////////////////////////
void QuantidadesIntervalo(string , int &, int &);
Nota GerarSegundaNota(Nota , int , int );

/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Intervalo::Intervalo()
{
    string intervaloSimples=this->RandomizarDescricao();
    this->CalcularSegundaNota(intervaloSimples);
}

Intervalo::Intervalo(Nota n)
{
    this->setN1(n);
    string intervaloSimples=this->RandomizarDescricao();
    this->CalcularSegundaNota(intervaloSimples);
}

Intervalo::Intervalo(Nota n1, Nota n2)
{
    this->setN1(n1);
    this->setN2(n2);
}

/////////////////////////////////////////
// Acesso
/////////////////////////////////////////

void Intervalo::setN1(Nota n){
    this->n1 = n;
}

Nota Intervalo::getN1(){
    return n1;
}

void Intervalo::setN2(Nota n){
    n2 = n;
}

Nota Intervalo::getN2(){
    return n2;
}

void Intervalo::setQtdNotasNaturais(int qnn){
    this->qtdNotasNaturais = qnn;

}
int Intervalo::getQtdNotasNaturais(){
    return qtdNotasNaturais;

}
void Intervalo::setQtdSemiTons(int qst){
    qtdSemiTons = qst;

}
int Intervalo::GetQtdSemiTons(){
    return qtdSemiTons;

}

/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////

void Intervalo::SetIntervalo(Nota n1, Nota n2){
    SimplificarIntervalo(n1, n2);
    this->setN1(n1);
    this->setN2(n2);
}

/*
Determinar a segunda nota de um intervalo em função de uma descrição de intervalo
*/
void Intervalo::CalcularSegundaNota(string descIntervalo){

    int qdtNotasNaturais, qtdSemiTons;
    Nota n1=this->getN1(),n2;

    QuantidadesIntervalo(descIntervalo,qdtNotasNaturais,qtdSemiTons);

    n2=GerarSegundaNota(n1,qdtNotasNaturais,qtdSemiTons);

    this->setN2(n2);

}

void Intervalo::RandomizarSegundaNota(){
    Nota n1,n2;

    n1 = this->getN1();
    n2.RandomizarNota();
    SimplificarIntervalo(n1, n2);
    this->setN2(n2);

}

string Intervalo::RandomizarDescricao(){
    string r;
	int n;

	n=GerarInteiro(1,8); // gera a nota
    r += to_string(n);
    //r += "ª";
	if ((n==4)||(n==5)||(n==8)||(n==1))
		r += "J";
    else {
        n=GerarInteiro(1,2); 
        if (n==1)
            r += "m";
        else
            r += "M";
    }

    return r;
}

string Intervalo::GerarDescricao(){
    string resposta="";

    if (getN1().GerarDescricao()!=""){
        resposta += this->getN1().GerarDescricao() + "-";
        resposta += this->getN2().GerarDescricao() + " ";
    }
    else
        resposta += "Primeira nota em branco";

    return resposta;

}

void Intervalo::ImprimirEmTela(){
    cout << this->GerarDescricao() << " ";
}

/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////


void QuantidadesIntervalo(string descricao, int &qdtNotasNaturais, int &qtdSemiTons){

    if      (descricao=="1J"){qdtNotasNaturais=1;qtdSemiTons= 0;}
    else if (descricao=="2m"){qdtNotasNaturais=2;qtdSemiTons= 1;}
    else if (descricao=="2M"){qdtNotasNaturais=2;qtdSemiTons= 3;}
    else if (descricao=="3m"){qdtNotasNaturais=3;qtdSemiTons= 4;}
    else if (descricao=="3M"){qdtNotasNaturais=3;qtdSemiTons= 5;}
    else if (descricao=="4J"){qdtNotasNaturais=4;qtdSemiTons= 6;}
    else if (descricao=="5J"){qdtNotasNaturais=5;qtdSemiTons= 8;}
    else if (descricao=="6m"){qdtNotasNaturais=6;qtdSemiTons= 9;}
    else if (descricao=="6M"){qdtNotasNaturais=6;qtdSemiTons=10;}
    else if (descricao=="7m"){qdtNotasNaturais=7;qtdSemiTons=11;}
    else if (descricao=="7M"){qdtNotasNaturais=7;qtdSemiTons=12;}
    else if (descricao=="8J"){qdtNotasNaturais=8;qtdSemiTons=13;}

}

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


Nota GerarSegundaNota(Nota referencia, int quantidadeNotas, int quantidadeSemitons){

	Nota relativa = referencia.qualRelativa(quantidadeNotas);
    
    int sub1, sub2, diffSemiToms, a;
    sub1=RetornarSubescrito(referencia.getGrau()); //1
    sub2=RetornarSubescrito(relativa.getGrau()); //5

    if (referencia.getGrau()<relativa.getGrau()){
        diffSemiToms = (sub2-sub1+1);
    }else{
        diffSemiToms=(12-sub1)+sub2+1;
    }
    a = quantidadeSemitons - diffSemiToms + referencia.getAcidente();

	relativa.setAcidente(a);

	return relativa;
	
}

void SimplificarIntervalo(Nota n1, Nota &n2){

    if (n1.getGrau() <= n2.getGrau())
        n2.setOitava(n1.getOitava());
    else 
        n2.setOitava(n1.getOitava()+1);

}


