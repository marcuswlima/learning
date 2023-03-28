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
}

Intervalo::Intervalo(Nota n)
{
    setN1(n);
}

/////////////////////////////////////////
// Acesso
/////////////////////////////////////////

void Intervalo::setN1(Nota n){
    n1 = n;
}

Nota Intervalo::getN1(){
    return n1;
}

void Intervalo::setN2(Nota t){
    n2 = t;
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
void Intervalo::setDescIntervalo(string di){
    descIntervalo = di;

}
string Intervalo::getDescIntervalo(){
    return descIntervalo;
}


/////////////////////////////////////////
// Implementações Externas
/////////////////////////////////////////


/*
Determinar a segunda nota de um intervalo em função de uma descrição de intervalo
*/
Nota Intervalo::CalcularSegundaNota(string descIntervalo){

    Nota temp;
    cout << "Intervalo::CalcularSegundaNota"<<endl;
    int qdtNotasNaturais, qtdSemiTons;
    Nota n1=this->getN1();
    n1.ImprimirEmTela();
    cout << endl;

    QuantidadesIntervalo(descIntervalo,qdtNotasNaturais,qtdSemiTons);
    cout << "qdtNotasNaturais -> " << qdtNotasNaturais << endl;
    cout << "qtdSemiTons -> " << qtdSemiTons << endl;

    temp=GerarSegundaNota(n1,qdtNotasNaturais,qtdSemiTons);
    temp.ImprimirEmTela();
    cout << endl;

    //this->setN2(temp);
    return temp;

}

void Intervalo::RandomizarSegundaNota(){
    Nota n;
    int g1 , g2;

    g1 = this->getN1().getGrau();

    n.RandomizarNota();
    g2 = n.getGrau();

    // tornar o intervalo simples
    if (g1 <= g2)
        n.setOitava(this->getN1().getOitava());
    else 
        n.setOitava(this->getN1().getOitava()+1);
    
    this->setN2(n);
}

string Intervalo::RandomizarDescricao(){
    string r;
	int n;

	n=GerarInteiro(2,8); // gera a nota
    r += to_string(n)+"ª";
	if ((n==4)||(n==5)||(n==8))
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
    string resposta;

    if (getN1().GerarDescricao()!=""){
        resposta += this->getN1().GerarDescricao() + " ";
        resposta += this->getN2().GerarDescricao() + " ";
    }
    else
        resposta += "Primeira nota em branco";

    return resposta;

}

void Intervalo::ImprimirEmTela(){
    cout << this->GerarDescricao();
}



/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////



void QuantidadesIntervalo(string descricao, int &qdtNotasNaturais, int &qtdSemiTons){

    if      (descricao=="2m"){qdtNotasNaturais=2;qtdSemiTons= 1;}
    else if (descricao=="2M"){qdtNotasNaturais=2;qtdSemiTons= 3;}
    else if (descricao=="3m"){qdtNotasNaturais=3;qtdSemiTons= 4;}
    else if (descricao=="3M"){qdtNotasNaturais=3;qtdSemiTons= 5;}
    else if (descricao=="4J"){qdtNotasNaturais=4;qtdSemiTons= 6;}
    else if (descricao=="5J"){qdtNotasNaturais=5;qtdSemiTons= 8;}
    else if (descricao=="6m"){qdtNotasNaturais=6;qtdSemiTons= 9;}
    else if (descricao=="6M"){qdtNotasNaturais=6;qtdSemiTons=10;}
    else if (descricao=="7m"){qdtNotasNaturais=7;qtdSemiTons=11;}
    else if (descricao=="7M"){qdtNotasNaturais=7;qtdSemiTons=12;}

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
    cout << "* GerarSegundaNota"<<endl;


	Nota relativa = referencia.qualRelativa(quantidadeNotas);
    
    relativa.ImprimirEmTela();
    cout << endl;
    int sub1, sub2, diffSemiToms, a;
    sub1=RetornarSubescrito(referencia.getGrau()); //1
    sub2=RetornarSubescrito(relativa.getGrau()); //5

    cout << "sub1-> "<<sub1<<endl;
    cout << "sub2-> "<<sub2<<endl;

    if (referencia.getGrau()<relativa.getGrau()){
        diffSemiToms = (sub2-sub1+1);
    }else{
        diffSemiToms=(12-sub1)+sub2+1;
    }
    a = quantidadeSemitons - diffSemiToms + referencia.getAcidente();

	relativa.setAcidente(a);

    relativa.ImprimirEmTela();
    cout << endl;


    cout << "Fim - GerarSegundaNota"<<endl;
	return relativa;
	
}


