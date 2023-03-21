#include <iostream>
#include <string>
using namespace std;

#include "Tecla.h"
#include "Intervalo.h"
#include "../../lib/BarraTitulo.h"
#include "../../lib/ObterNumero.h"
#include "../../lib/Mathematics.h"

void IntervalosGerarSegundaNota();
void IntervalosGerarIntervalo();
int menu();
void Notas();
void Intervalos();
void Acordes();
void Acordes_um();

Tecla t;
/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main ( )
{
    //srand( time(0) );


    ImprimirTitulo("Nota Musicais");

	Tecla t1(3,7,0), t2;
	t1.Imprimir();
	for (int i=2;i<=7; i++){
		t2=t1.qualRelativa(i);
		t2.Imprimir();
	}



/*

	Intervalo i(3,1,0);
	Tecla t;

	t.setTecla(3,2,0);
	i.EncontrarQualificacao(t);
	i.Imprimir();
	cout << endl;

	t.setTecla(3,3,0);
	i.EncontrarQualificacao(t);
	i.Imprimir();
	cout << endl;

    int opcao=0;

    do{
        opcao=menu();

		switch(opcao){
			case 1:Notas();break;
			case 2:Intervalos();break;
			case 3:Acordes();break;
		}
    }while (opcao!=0);
*/
    return 0; //indica o fim do programa
}

void EncontrarQualificacao(int n, int a){
	Intervalo i(3,n,a);
	Tecla t;


}

int menu(){
	int escolha;
    cout << "**********************\n";
    cout << "** 1 - Notas Soltas **\n";
    cout << "** 2 - Intervalos   **\n";
    cout << "** 3 - Acordes      **\n";
    cout << "** 0 - Sair         **\n";
    cout << "***********************\n";
	escolha=ObterNumeroNaFaixa("Indique qual módulo [1,2,3,0] -> ",0,3);
    return escolha;
}

void Notas(){	
	cout << endl << endl;
	ImprimirTitulo("Notas Soltas");
	int quantNotas=ObterNumeroNaFaixa("Digite a quantidade[1:30] -> ",1,30);
	cout << endl;
     
	for (int i=1;i<=quantNotas;i++){
		t.Aleatorio();
		t.Imprimir();
	}

	cout << endl << endl;
}

void Intervalos(){	
	cout << endl << endl;
	ImprimirTitulo("Intervalos");
    cout << "****************************************\n";
    cout << "** A partir de uma nota aleatória     **\n";
    cout << "** 1) Apresentar um intervalo simples **\n";
    cout << "** 2) Apresentar uma segunda nota     **\n";
    cout << "****************************************\n";
	int opcao=ObterNumeroNaFaixa("Indica sua opção [1:2] -> ",1,2);
	int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);

	cout << endl;
	for (int i=1; i<=quantidade; i++){	
		if (opcao==1)
			IntervalosGerarIntervalo();
		else 
            IntervalosGerarSegundaNota();
	}

	cout << endl;
	cout << endl;

}

void IntervalosGerarIntervalo(){

	int numero;
	t.Aleatorio();
	t.Imprimir();

	cout << "- ";
	numero=GerarInteiro(2,8);
	cout << numero;
	if ((numero==4)||(numero==5)||(numero==8))
		cout << "J";
	else{
		numero=GerarInteiro(1,2);
		if (numero==1) 
			cout << "m";
		else 
			cout << "M";
	}

    cout << " / ";
}

int GerarNovaNota(int inferior,int superior,int antiga){	
	int resposta;
	do{	
		resposta = GerarInteiro(inferior,superior);
	}while(resposta==antiga);
	return resposta;
}

void IntervalosGerarSegundaNota(){
	int notaN1, novaN2;
	t.Aleatorio();
	t.Imprimir();

    notaN1 = t.getNota();
	novaN2 = GerarNovaNota(1,7,notaN1);

	if(novaN2 < notaN1) 
		t.setOitava(t.getOitava()+1);
	
	t.setNota(novaN2);
	t.setAcidente(GerarInteiro(-1,1));
	t.Imprimir();
	

    cout << " / ";
}

void Acordes(){	
	cout << endl << endl;
	ImprimirTitulo("Acordes");
    cout << "****************************************************\n";
    cout << "** A partir de uma nota aleatória                 **\n";
    cout << "** 1) Apresentar um acorde(M,m,A,d)               **\n";
    cout << "** 2) Apresentar uma terça nota e uma quinta nota **\n";
    cout << "****************************************************\n";
	int opcao=ObterNumeroNaFaixa("Indica sua opção [1:2] -> ",1,2);

	if (opcao==1){
	    int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);
		for(int i=1; i<quantidade; i++){
			Acordes_um();
		}
	}
	else
		cout << "Não implementado";

	cout << endl << endl;
}

void Acordes_um(){
	int idAcorde=GerarInteiro(1,4);
	string descAcorde; 
	t.Aleatorio();
	t.Imprimir();

	switch (idAcorde){
    	case 1:descAcorde="Maior";break;
    	case 2:descAcorde="Menor";break;
    	case 3:descAcorde="Aumentado";break;
    	case 4:descAcorde="Diminuto";break;
	}

	cout << descAcorde;

	cout << " / ";
}

/*
    Tecla t1(3,4,0), t2;
    t1.imprimirTecla();
    t2 = i2m(t1);
    t2.imprimirTecla();
    t2 = i2M(t1);
    t2.imprimirTecla();
    t2 = i3m(t1);
    t2.imprimirTecla();
    t2 = i3M(t1);
    t2.imprimirTecla();
    t2 = i4J(t1);
    t2.imprimirTecla();
	cout << endl;

Tecla i2m(Tecla t){
    Tecla temp;
    int deslocamentoTecla=1,deslocamentoSemitom=1,distanciaDeNotas=2;
    copiaTecla(t,temp);

    temp.setNota(temp.getNota()+deslocamentoTecla);
    temp.setAcidente(deslocamentoSemitom-distanciaDeNotas);
    return temp;
}

Tecla i2M(Tecla t){
    Tecla temp;
    int deslocamentoTecla=1,deslocamentoSemitom=2,distanciaDeNotas=2;
    copiaTecla(t,temp);

    temp.setNota(temp.getNota()+deslocamentoTecla);
    temp.setAcidente(deslocamentoSemitom-distanciaDeNotas);
    return temp;
}

Tecla i3m(Tecla t){
    Tecla temp;
    int deslocamentoTecla=2,deslocamentoSemitom=3,distanciaDeNotas=4;
    copiaTecla(t,temp);

    temp.setNota(temp.getNota()+deslocamentoTecla);
    temp.setAcidente(deslocamentoSemitom-distanciaDeNotas);
    return temp;
}

Tecla i3M(Tecla t){
    Tecla temp;
    int deslocamentoTecla=2,deslocamentoSemitom=4,distanciaDeNotas=4;
    copiaTecla(t,temp);

    temp.setNota(temp.getNota()+deslocamentoTecla);
    temp.setAcidente(deslocamentoSemitom-distanciaDeNotas);
    return temp;
}

Tecla i4J(Tecla t){
    Tecla temp;
    int deslocamentoTecla=3,deslocamentoSemitom=5,distanciaDeNotas=6;
    copiaTecla(t,temp);

    temp.setNota(temp.getNota()+deslocamentoTecla);
    temp.setAcidente(deslocamentoSemitom-distanciaDeNotas);
    return temp;
}

void copiaTecla(Tecla t1,Tecla &t2){
    t2.setTecla(t1.getOitava(), t1.getNota(), t1.getAcidente());
}

*/
