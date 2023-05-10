#include "Intervalo.h"

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////
void QuantidadesIntervalo(string , int &, int &);
void SimplificarIntervalo(Nota, Nota &);
bool SegundaMaior(Nota n1, Nota n2);
bool PrimeiraMaior(Nota n1, Nota n2);
int distanciaEmSemiTons(Nota,Nota);
bool NotasIguais(Nota n1, Nota n2);

/////////////////////////////////////////
// Elementos Globais
/////////////////////////////////////////
struct tRecDadosIntervalo {
    string tipoIntervalo;
    int qtdNotasNaturais;
    int qtdSemiTons;
};

tRecDadosIntervalo DadosIntervalo[]={  //0-15
                                        {"1J",1, 1},
                                        {"2m",2, 2},
                                        {"2M",2, 3},
                                        {"3m",3, 4},
                                        {"3M",3, 5},
                                        {"4D",4, 5},
                                        {"4J",4, 6},
                                        {"4A",4, 7},
                                        {"5D",5, 7},
                                        {"5J",5, 8},
                                        {"5A",5, 9},
                                        {"6m",6, 9},
                                        {"6M",6,10},
                                        {"7m",7,11},
                                        {"7M",7,12},
                                        {"8J",8,13}
                                    };


/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Intervalo::Intervalo()
{
}

Intervalo::Intervalo(int dificuldade){
	this->Randomizar(dificuldade);
}

Intervalo::Intervalo(Nota n1, Nota n2)
{
    this->setN1(n1);
    this->setN2(n2);
}
    
/////////////////////////////////////////
// Sets
/////////////////////////////////////////
void Intervalo::setN1(Nota n){
    this->n1 = n;
}

void Intervalo::setN2(Nota in_n2){
    SimplificarIntervalo(this->n1,in_n2);
    this->n2 = in_n2;
}

void Intervalo::setN2(string descIntervalo, int orientacao){

    Nota n1,n2;
    int qdtNotasDoIntervaloDesejado, qtdSemiTonsDoIntervaloDesejado,qtdSemiTonsEntreAsDuasNotas, novoAcidente;

    /// dados do intervalo desejado
    QuantidadesIntervalo(descIntervalo,qdtNotasDoIntervaloDesejado,qtdSemiTonsDoIntervaloDesejado);

    /// encontrar nova nota
    n1 = this->getN1();
    n2 = n1.qualRelativa(qdtNotasDoIntervaloDesejado,orientacao);
    //n2.ImprimirEmTela();

    /// encontrar novo acidente
    qtdSemiTonsEntreAsDuasNotas = distanciaEmSemiTons(n1,n2);
	//cout << endl << "qtdSemiTonsEntreAsDuasNotas:"<<qtdSemiTonsEntreAsDuasNotas<<endl;
    //cout << "qtdSemiTonsDoIntervaloDesejado:"<<qtdSemiTonsDoIntervaloDesejado<<endl;
    (orientacao==1)                                                                    ?
        novoAcidente = qtdSemiTonsDoIntervaloDesejado - qtdSemiTonsEntreAsDuasNotas    :
        novoAcidente = qtdSemiTonsEntreAsDuasNotas    - qtdSemiTonsDoIntervaloDesejado ;

    novoAcidente += n1.getAcidente();

    n2.setAcidente(novoAcidente);
    //cout << "novoAcidente:"<<novoAcidente<<endl;

    this->setN2(n2);

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

    n.Randomizar(dificuldade);
    this->setN1(n);
    n.Randomizar(dificuldade);
    this->setN2(n);
}

string Intervalo::GerarDescricao(){
    string resposta="";

    if (getN1().GerarDescricao()!=""){
        resposta += this->getN1().GerarDescricao();
        resposta += ":";
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

int Intervalo::DeduzirOrientacao(){
    return (SegundaMaior(this->getN1(),this->getN2()))
                 ? 1
                 : -1;
}

int Intervalo::DeduzirQdtNotas(){
    int resposta,
		g1 = this->getN1().getGrau(),
		g2 = this->getN2().getGrau()
		;

	bool ascendente = SegundaMaior(n1,n2) ,
		 mesmaOitava = this->getN1().getOitava() == this->getN2().getOitava()
		 ;


	if      ( (ascendente) && (mesmaOitava) ){
		resposta = g2 - g1 + 1;
	}else if( (ascendente) &&!(mesmaOitava) ){
//		cout << "acertou" << endl;
		if (g1==g2){
			resposta = 8;
		}
		else{
			resposta = (7 - g1) +  g2 +1 ;
		}
	}else if(!(ascendente) && (mesmaOitava) ){
		resposta = g1 - g2 + 1;
	}else if(!(ascendente) &&!(mesmaOitava) ){
		resposta = (7 - g2) +  g1 + 1;
	}

    return resposta;
}

int Intervalo::DeduzirQtdSemiTons(){
    return distanciaEmSemiTons(
                               this->getN1()
                              ,this->getN2()
                              );
}

string Intervalo::DeduzirTipoIntervalo(){
    string resposta="er";
    int qtdNotas = this->DeduzirQdtNotas();
    int qtdSemiTons = this->DeduzirQtdSemiTons();

//	cout << endl;
//    cout << "qtdNotas->"<< qtdNotas<< endl;
//    cout << "qdtSemitons->"<< qtdSemiTons<< endl;

    for (int i=0; i<=15; i++){
        if ((DadosIntervalo[i].qtdNotasNaturais==qtdNotas) && (DadosIntervalo[i].qtdSemiTons==qtdSemiTons)){
            resposta = DadosIntervalo[i].tipoIntervalo;
            break; 
        }
    }
    return resposta;
}

void Intervalo::ImprimirOrientacaoEmTela(){
    if (NotasIguais(this->getN1(),this->getN2())){
		cout << "Unissono";
    }else{
		(this->DeduzirOrientacao()==1) ? 
			cout << "Asc"              : 
			cout << "Desc"             ;
    }
}

void Intervalo::ImprimirTipoIntervaloEmTela(){
	cout << this->DeduzirTipoIntervalo() ;
}

void Intervalo::ImprimirQdtNotasEmTela(){
    cout << this->DeduzirQdtNotas() << " ";
}

void Intervalo::ImprimirQtdSemiTonsEmTela(){
    cout << this->DeduzirQtdSemiTons() << " ";
}

/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////

void QuantidadesIntervalo(string descricao, int &qdtNotasNaturais, int &qtdSemiTons){
    
	for (int i=0; i<=15; i++){
        if (DadosIntervalo[i].tipoIntervalo==descricao){
			qdtNotasNaturais=DadosIntervalo[i].qtdNotasNaturais;
			qtdSemiTons=DadosIntervalo[i].qtdSemiTons;
            break; 
        }
    }
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

void SimplificarIntervalo(Nota n1, Nota &n2){
	
    if (n1.getOitava()!=n2.getOitava()){

		if (SegundaMaior(n1,n2)){//Ascendente
			if (n2.getGrau()>n1.getGrau()){
				n2.setOitava(n1.getOitava());
			}else{
				n2.setOitava(n1.getOitava()+1);
			}
		}else{//Decrscente
			if (n2.getGrau()>n1.getGrau()){
				n2.setOitava(n1.getOitava()-1);
			}else{
				n2.setOitava(n1.getOitava());
			}
		}
	}

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
////////////////////////////////////////////////////////


int distanciaEmSemiTons(Nota n1,Nota n2){
    int g1   = n1.getGrau()          ,
        g2   = n2.getGrau()          ,
        i1   = RetornarSubescrito(g1),
        i2   = RetornarSubescrito(g2),
        resp = 0                     ;

//	cout << endl;
//    cout << "i1:" << i1 << endl;
//    cout << "i2:" << i2 << endl;
//    n1.ImprimirEmTela();
//    n2.ImprimirEmTela();
   
   	if (SegundaMaior(n1,n2)){ // intervalo ascendente
        if(g1 < g2){          // primeira nota com grau menor
            resp = (i2-i1+1);
        }
        else if(g1 > g2) {    // segunda nota com grau menor
            resp = (12-i1+1)+i2 ;
		}
		else if(g1=g2){
			resp=13;
        };
    }else if (PrimeiraMaior(n1,n2)){ // intervalo descendente
        if(g1 < g2){           // primeira nota com grau menor
            resp = (12-i2+1)+i1 ;
        }
        else if(g1 > g2) {     // segunda nota com grau menor
            resp = (i1-i2+1);
        };
    }else {  // notas idênticas
        resp=1;

    }
    return resp;
}

Intervalo RadomizarIntervalo(int dificuldade){
	Intervalo resp;
	Nota n;

	n.Randomizar();
	resp.setN1(n);
	n.Randomizar();
	resp.setN2(n);

	return resp;
}



