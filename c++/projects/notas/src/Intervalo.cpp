#include "Intervalo.h"

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////
void QuantidadesIntervalo(string , int &, int &);
Nota GerarSegundaNota(Nota , int , int, int );
void SimplificarIntervalo(Nota, Nota &, int=1);
bool SegundaMaior(Nota n1, Nota n2);
int RandomizaOrientacao_inner();

/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Intervalo::Intervalo()
{
}
Intervalo::Intervalo(int dificuldade)
{
    Nota n;
    n.Randomizar(dificuldade);
    this->setN1(n);
    n.Randomizar(dificuldade);
    this->setN2(n,RandomizaOrientacao_inner());
}

Intervalo::Intervalo(int dificuldade, int orientacao)
{
    Nota n;
    n.Randomizar(dificuldade = dificuldade);
    this->setN1(n);
    n.Randomizar(dificuldade);
    this->setN2(n,orientacao);
}


Intervalo::Intervalo(Nota n1, Nota n2)
{
    this->setN1(n1);
    this->setN2(n2,RandomizaOrientacao_inner());
}
    
/////////////////////////////////////////
// Sets
/////////////////////////////////////////
void Intervalo::setN1(Nota n){
    this->n1 = n;
}

void Intervalo::setN2(Nota n, int orientacao){
    n1 = this->getN1();
    SimplificarIntervalo(n1,n, orientacao);
    n2 = n;
}

void Intervalo::setN2(string descIntervalo, int orientacao){

    int qdtNotasNaturais, qtdSemiTons;
    Nota n1=this->getN1(),n2;

    QuantidadesIntervalo(descIntervalo,qdtNotasNaturais,qtdSemiTons);

    n2=GerarSegundaNota(n1,qdtNotasNaturais,qtdSemiTons, orientacao);

    this->setN2(n2,orientacao);

}

void Intervalo::SetIntervalo(Nota n1, Nota n2,int orientacao){
    this->setN1(n1);
    this->setN2(n2,orientacao);
}


/////////////////////////////////////////
// Gets
/////////////////////////////////////////

Nota Intervalo::getN1(){
    return n1;
}

Nota Intervalo::getN2(){
    return n2;
}


/////////////////////////////////////////
// Padrão
/////////////////////////////////////////
void Intervalo::Randomizar(int dificuldade){
    Nota n;
    int orientacao = RandomizaOrientacao_inner();

    n.Randomizar(dificuldade);
    this->setN1(n);
    n.Randomizar(dificuldade);
    this->setN2(n,orientacao);
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
// Implementações Externas
/////////////////////////////////////////
void Intervalo::RandomizarSegundaNota(int dificuldade){
    int orientacao = RandomizaOrientacao_inner();
    Nota n2;
    n2.Randomizar(dificuldade);
    this->setN2(n2,orientacao);
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
        (n==1) ? r += "m" : r += "M";
    }

    return r;
}

string Intervalo::RandomizaOrientacao(){
    return (RandomizaOrientacao_inner()==1) ? "Asc" : "Desc" ;
}

/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////

int RandomizaOrientacao_inner(){
    return (GerarInteiro(1,2)==1) ? 1 : -1 ;
}

void QuantidadesIntervalo(string descricao, int &qdtNotasNaturais, int &qtdSemiTons){

    if      (descricao=="1J"){qdtNotasNaturais=1;qtdSemiTons= 1;}
    else if (descricao=="2m"){qdtNotasNaturais=2;qtdSemiTons= 2;}
    else if (descricao=="2M"){qdtNotasNaturais=2;qtdSemiTons= 3;}
    else if (descricao=="3m"){qdtNotasNaturais=3;qtdSemiTons= 4;}
    else if (descricao=="3M"){qdtNotasNaturais=3;qtdSemiTons= 5;}
    else if (descricao=="4D"){qdtNotasNaturais=4;qtdSemiTons= 5;}
    else if (descricao=="4J"){qdtNotasNaturais=4;qtdSemiTons= 6;}
    else if (descricao=="4A"){qdtNotasNaturais=4;qtdSemiTons= 7;}
    else if (descricao=="5D"){qdtNotasNaturais=5;qtdSemiTons= 7;}
    else if (descricao=="5J"){qdtNotasNaturais=5;qtdSemiTons= 8;}
    else if (descricao=="5A"){qdtNotasNaturais=5;qtdSemiTons= 9;}
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


/////////////////////////////////////////////////////
// Implementar intervalo descrescente
/////////////////////////////////////////////////////
Nota GerarSegundaNota(Nota referencia, int quantidadeNotas, int quantidadeSemitons, int orientacao){

	Nota relativa = referencia.qualRelativa(quantidadeNotas);
    
    int sub1, sub2, diffSemiToms, a;
    sub1=RetornarSubescrito(referencia.getGrau()); //1
    sub2=RetornarSubescrito(relativa.getGrau()); //5

    if (referencia.getGrau()<relativa.getGrau()){
        diffSemiToms = (sub2-sub1+1);
    }else{
        diffSemiToms = (12-sub1)+sub2+1;
    }
    a = quantidadeSemitons - diffSemiToms + referencia.getAcidente();

	relativa.setAcidente(a);

	return relativa;
	
}

void SimplificarIntervalo(Nota n1, Nota &n2, int orientacao){

    if (orientacao==1)
        (n1.getGrau() < n2.getGrau()  ) ? 
         n2.setOitava(n1.getOitava()  ) : 
         n2.setOitava(n1.getOitava()+1) ;
    else 
        (n1.getGrau() > n2.getGrau()  ) ? 
         n2.setOitava(n1.getOitava()  ) : 
         n2.setOitava(n1.getOitava()-1) ;

}

////////////////////////////////////
// Transformar em operação em Nota
////////////////////////////////////
bool PrimeiraMaior(Nota n1, Nota n2){
    bool resposta = false;

    if (n1.getOitava() != n2.getOitava())   
        resposta = n1.getOitava() > n2.getOitava();
    else if (n1.getGrau() != n2.getGrau())
        resposta = n1.getGrau() > n2.getGrau();
    else if (n1.getAcidente() != n2.getAcidente()) 
        resposta = n1.getAcidente() > n2.getAcidente();

    return resposta;

}

bool NotasIguais(Nota n1, Nota n2){
    return (n1.getOitava()   == n2.getOitava()  )&&
           (n1.getGrau()     == n2.getGrau()    )&&
           (n1.getAcidente() == n2.getAcidente());

}

bool SegundaMaior(Nota n1, Nota n2){
    return !PrimeiraMaior(n1,n2) && !NotasIguais(n1,n2);
}
