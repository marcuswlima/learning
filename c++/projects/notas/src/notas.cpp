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

/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main ( )
{
    srand( time(0) );

    ImprimirTitulo("Gerador Exercicios");

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


	for (int i=1; i<=quantidade; i++){	
		if (opcao==1){
			nota.RandomizarNota();
			nota.ImprimirEmTela();
			cout << intervalo.RandomizarDescricao();
		}
		else {
			nota.RandomizarNota();
			intervalo.setN1(nota);
			intervalo.RandomizarSegundaNota();
			intervalo.ImprimirEmTela();
		}

		cout << " / ";
	}

	cout << endl << endl;

}


void MenuTriades(){	
	cout << endl << endl;
	ImprimirTitulo("Triades");
    cout << "***********************************************************************\n";
    cout << "** 1) Uma nota e uma triade (M,m,A,d). Fundamental, terca e quinta ? **\n";
    cout << "** 2) Fundamental, terca e quinta. Qual triade (M,m,A,d)?            **\n";
    cout << "***********************************************************************\n";
	int opcao=ObterNumeroNaFaixa("Indica sua opção [1:2] -> ",1,2);
	int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);
	cout << endl;

	for(int i=1; i<=quantidade; i++){

		triade.RandomizarTriade();

		if (opcao==1){
			triade.ImprimirFundamentalEmTela();
			cout << " " << triade.RandomizarTipoTriade();
		}
		else
			triade.ImprimirEmTela();

		cout << " / ";

	}
	
	cout << endl << endl;
}
