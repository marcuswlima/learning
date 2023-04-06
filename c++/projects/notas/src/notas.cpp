#include "Triade.h"


/////////////////////////////////////////
// Objetos Globais
/////////////////////////////////////////
Nota nota;
Intervalo intervalo;
Triade triade;

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////
int menu();
void MenuIntervalos();
void MenuTriades();
void ChamarMenu();
void Notas();
void UC01(int);
void UC02(int);
void UC03(int);
void UC04(int);
void UC05(int);
void UC06(int);

/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main ( )
{
    srand( time(0) );

    ImprimirTitulo("Gerador Exercicios");

	//UC06(10);

	ChamarMenu();

    cout << endl;
	return 0; //indica o fim do programa
}

void ChamarMenu(){
    int opcao=0;
	do{
        opcao=menu();

		switch(opcao){
			case 1:MenuIntervalos();break;
			case 2:MenuTriades();break;
			case 3:Notas();break;
		}
    }while (opcao!=0);

}

int menu(){
	int escolha;
    cout << "*********************\n";
    cout << "** 1) Intervalos   **\n";
    cout << "** 2) Triades      **\n";
    cout << "** 0) Sair         **\n";
    cout << "*********************\n";
	escolha=ObterNumeroNaFaixa("Indique qual módulo [1,2,0] -> ",0,2);
    return escolha;
}

void Notas(){
	cout << endl << endl;
	ImprimirTitulo("Notas Soltas");
	int quantNotas=ObterNumeroNaFaixa("Digite a quantidade[1:30] -> ",1,30);
	cout << endl;
     
	for (int i=1;i<=quantNotas;i++){
		nota.RandomizarNota();
		nota.ImprimirEmTela();
	}
	cout << endl << endl;
}

void MenuIntervalos(){
	cout << endl << endl;
	ImprimirTitulo("Intervalos");
    cout << "**********************************************************\n";
    cout << "** 1) Uma nota e um intervalo simples, qual outra nota? **\n";
    cout << "** 2) Duas Notas, qual intervalo simples?               **\n";
    cout << "**********************************************************\n";
	int opcao=ObterNumeroNaFaixa("Indica sua opção [1:2] -> ",1,2);
	int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);
	cout << endl;


	switch (opcao)
	{
		case 1:UC01(quantidade);break;
		case 2:UC02(quantidade);break;
	default:
		break;
	}

	cout << endl << endl;

}


void MenuTriades(){	
	cout << endl << endl;
	ImprimirTitulo("Triades");
    cout << "***********************************************************************\n";
    cout << "** 1) Uma nota e uma triade (M,m,A,d). Fundamental, terca e quinta ? **\n";
    cout << "** 2) Fundamental, terca e quinta. Qual triade (M,m,A,d)?            **\n";
    cout << "** 3) Triade Estado Fundamental. Qual 1º e 2º inversão ?             **\n";
    cout << "** 4) Uma traide invertida. Qual o Estado Fundamental?               **\n";
    cout << "***********************************************************************\n";
	int opcao=ObterNumeroNaFaixa("Indica sua opção [1:2] -> ",1,4);
	int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);
	cout << endl;

	switch (opcao)
	{
		case 1:UC03(quantidade);break;
		case 2:UC04(quantidade);break;
		case 3:UC05(quantidade);break;
	default:
		break;
	}

	cout << endl << endl;
}

void UC01(int quantidade){
	for(int i=1; i<=quantidade; i++){
		nota.RandomizarNota();
		nota.ImprimirEmTela();
		cout << intervalo.RandomizarDescricao();
		cout << " / ";
	}
}

void UC02(int quantidade){
	for(int i=1; i<=quantidade; i++){
		nota.RandomizarNota();
		intervalo.setN1(nota);
		intervalo.RandomizarSegundaNota();
		intervalo.ImprimirEmTela();
		cout << " / ";
	}
}

void UC03(int quantidade){
	for(int i=1; i<=quantidade; i++){
		triade.RandomizarTriade();
		triade.ImprimirFundamentalEmTela();
		cout << " " << triade.RandomizarTipoTriade();
		cout << " / ";
	}
}

void UC04(int quantidade){
	for(int i=1; i<=quantidade; i++){
		triade.RandomizarTriade();
		triade.ImprimirEmTela();
		cout << " / ";
	}
}

void UC05(int quantidade){

	struct tNoh {
		Triade triade;
		int diff3;
		int diff5;
	};
	tNoh nohs[quantidade];

	// Popular arrray de struct
	for(int i=0; i<=quantidade-1; i++){
		triade.RandomizarTriade();
		nohs[i].triade=triade;
		nohs[i].diff3=3;
		nohs[i].diff5=5;
	}

	// Imprimir 5 nota
	for(int i=0; i<=quantidade-1; i++){
		nohs[i].triade.getInt2().getN2().ImprimirEmTela();
		cout << "\t" << nohs[i].diff5 << "\t";
	}
	cout << endl;

	// Imprimir 3 nota
	for(int i=0; i<=quantidade-1; i++){
		nohs[i].triade.getInt1().getN2().ImprimirEmTela();
		cout << "\t" << nohs[i].diff3 << "\t";
	}
	cout << endl;

	// Imprimir fundamental
	for(int i=0; i<=quantidade-1; i++){
		nohs[i].triade.getInt1().getN1().ImprimirEmTela();
		cout << "\t\t";
	}
	cout << endl;
}


void UC06(int quantidade){

}