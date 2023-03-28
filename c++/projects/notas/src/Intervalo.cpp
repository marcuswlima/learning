#include "Intervalo.h"
#include "../../lib/Mathematics.h"




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
    int qdtNotasNaturais, qtdSemiTons;
    Nota n1=this->getN1();

    QuantidadesIntervalo(descIntervalo,qdtNotasNaturais,qtdSemiTons);

    return GerarSegundaNota(n1,qdtNotasNaturais,qtdSemiTons);


}

Nota Intervalo::GerarSegundaNotaAleatoria(){
    Nota n;
    int g1 , g2;

    g1 = this->getN1().getGrau();

    n.Aleatorio();
    g2 = n.getGrau();

    // tornar o intervalo simples
    if (g1 <= g2)
        n.setOitava(this->getN1().getOitava());
    else 
        n.setOitava(this->getN1().getOitava()+1);
    
    return n;
}




string Intervalo::GerarDescricaoAleatoria(){
    string r;
	int n;

	n=GerarInteiro(2,8); // gera a nota
    r += to_string(n);
	if ((n==4)||(n==5)||(n==8))
		r += "J";
    else {
        n=GerarInteiro(2,8); // gera a nota
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




/*
/////////////////////////////////////////
// Lixao
/////////////////////////////////////////


int teclado[]={0,1,0,2,0,3,4,0,5,0,6,0,7};

string QualificarIntervalo(int diff){
    string resposta = "";

    if (diff==1) resposta = "2m";
    
    return " ";

}


void Intervalo::EncontrarQualificacao(Nota t){
    int n1, n2, distancia;

    this->setN2(t);
    n1=this->getN1().getGrau();
    n2=this->getN2().getGrau();

//    if (n1<n2) //intervalo ascendente
//        distancia = RetornarSubescrito(n2) - RetornarSubescrito(n1) + 1;
//    else // intervalo descendente
//        distancia = (7 - RetornarSubescrito(n1))  + RetornarSubescrito(n2) ;
    this->setQuantidadeNotas(distancia);

//    cout << "ido" << RetornarSubescrito(this->getT1().getNota()) << endl;
//    cout << "ire" << RetornarSubescrito(this->getT2().getNota()) << endl;
//    cout << "distancia" << distancia << endl;

    int numero=0;
    char qualidade=' ';
    if (distancia==1){
        numero = 2;
        qualidade = 'm';
    }else if (distancia==2){
        numero = 2;
        qualidade = 'M';
    }else if (distancia==3){
        numero = 3;
        qualidade = 'm';
    }
    this->setQuantidadeNotas(numero);
'    this->setQualidade(qualidade);

}
*/


/*

Nota notaMenor(Nota t1, Nota t2){
    if (t1.getOitava() < t2.getOitava())
        return t1;
    else if (t1.getOitava() > t2.getOitava())
        return t2;
    else //mesma oitava
        if (t1.getGrau() < t2.getGrau())
            return t1;
        if (t1.getGrau() > t2.getGrau())
            return t2;
        else // mesma nota
            if (t1.getAcidente() < t2.getAcidente())
                return t1;
            else if (t1.getAcidente() > t2.getAcidente())
                return t2;
            else    
                return t1; //teclas identicas
}

bool notasIguais(Nota t1, Nota t2){
    return t1.getOitava()   == t2.getOitava()  &&
           t1.getGrau()     == t2.getGrau()    &&
           t1.getAcidente() == t2.getAcidente();
}

int tipoIntervalor(Nota t1, Nota t2){
    int quantNotas = abs( t1.getGrau() - t2.getGrau() ), quantSemitons;
    
    return quantNotas+1;
}

*/
