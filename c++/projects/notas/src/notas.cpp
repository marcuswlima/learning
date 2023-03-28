#include <iostream>
#include <string>
using namespace std;

#include "Nota.h"
#include "Intervalo.h"
#include "Triade.h"
#include "../../lib/BarraTitulo.h"
#include "../../lib/ObterNumero.h"
#include "../../lib/Mathematics.h"

int menu();
void Notas();
void Intervalos();
void Acordes();
void Acordes_um();
void TesteTodosAcordes();
void ChamarMenu();

Nota n;
/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main ( )
{
    srand( time(0) );


    ImprimirTitulo("Nota Musicais");

	//TesteTodosAcordes();
	ChamarMenu();

	//Tecla t;
	//Triade tri(t);
	//t.setTecla(3,6,0);
	//tri.GerarTriade(t,"M");
	//tri.ImprimirEmTela();

    return 0; //indica o fim do programa
}

void ChamarMenu(){
    int opcao=0;
	do{
        opcao=menu();

		switch(opcao){
			case 1:Intervalos();break;
			case 2:Acordes();break;
		}
    }while (opcao!=0);

}

void TesteTodosAcordes(){
	Triade tri(n);
	cout << "Maiores"    << "\t\t\t\t" 
	     << "Menores"    << "\t\t\t\t"  
	     << "Aumentados" << "\t\t\t"  
	     << "Diminutos"  
		 << endl;
	for (int i=1;i<=7;i++){
		n.setNota(7,i,0);
		tri.GerarTriade(n,"M");
		tri.ImprimirEmTela();
		cout << "\t\t";
		tri.GerarTriade(n,"m");
		tri.ImprimirEmTela();
		cout << "\t\t";
		tri.GerarTriade(n,"A");
		tri.ImprimirEmTela();
		cout << "\t\t";
		tri.GerarTriade(n,"d");
		tri.ImprimirEmTela();
		cout << endl;
	}
}

/*
void EncontrarQualificacao(int n, int a){
	Intervalo i(3,n,a);
	Nota t;
	}
*/

int menu(){
	int escolha;
    cout << "**********************\n";
    cout << "** 1 - Intervalos   **\n";
    cout << "** 2 - Triades      **\n";
    cout << "** 0 - Sair         **\n";
    cout << "***********************\n";
	escolha=ObterNumeroNaFaixa("Indique qual módulo [1,2,0] -> ",0,2);
    return escolha;
}

void Notas(){	
	cout << endl << endl;
	ImprimirTitulo("Notas Soltas");
	int quantNotas=ObterNumeroNaFaixa("Digite a quantidade[1:30] -> ",1,30);
	cout << endl;
     
	for (int i=1;i<=quantNotas;i++){
		n.Aleatorio();
		n.ImprimirEmTela();
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

	Intervalo inte;
	Nota n;

	for (int i=1; i<=quantidade; i++){	
		if (opcao==1){
			n.Aleatorio();
			n.ImprimirEmTela();
			cout <<  inte.GerarDescricaoAleatoria();
		}
		else {
			n.Aleatorio();
			n.ImprimirEmTela();
			inte.setN1(n);
			n = inte.GerarSegundaNotaAleatoria();
			n.ImprimirEmTela();
		}

		cout << " / ";
	}

	cout << endl;
	cout << endl;

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
	n.Aleatorio();
	n.ImprimirEmTela();

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
