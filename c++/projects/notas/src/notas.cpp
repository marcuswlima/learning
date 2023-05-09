#include "Triade.h"

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////
int menu();
void MenuConfiguracoes();
void MenuIntervalos();
void MenuTriades();
void ChamarMenu();
void Notas();
void UC01();
void UC02();
void UC03();
void UC04();
void UC05();
void UC06();
void TestarIntervalo();
void TestarTriade();
void TestarNota();

/////////////////////////////////////////
// Elelementos Globais
/////////////////////////////////////////
int gDificuldade=1;

/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main(){
    srand( time(0) );

    ImprimirTitulo("Gerador Exercicios");

//    ChamarMenu();
//    UC06(10);
    TestarIntervalo();
//    TestarTriade();
//    TestarNota();

    cout << endl;
    return 0; //indica o fim do programa2
}

void ChamarMenu(){
    int opcao=0;
    do{
		opcao=menu();

		switch(opcao){
			case 1:Notas();break;
			case 2:MenuIntervalos();break;
			case 3:MenuTriades();break;
			case 4:MenuConfiguracoes();break;
		}
    }while (opcao!=0);
}

int menu(){
    int escolha;


    cout << "*********************\n";
    cout << "** 1) Notas        **\n";
    cout << "** 2) Intervalos   **\n";
    cout << "** 3) Triades      **\n";
    cout << "** 4) Condigrações **\n";
    cout << "** 0) Sair         **\n";
    cout << "*********************\n";
    escolha=ObterNumeroNaFaixa("Indique qual módulo [1,2,3,4,0] -> ",0,4);
    return escolha;
}

void Notas(){

    Nota nota;
    int quantNotas=ObterNumeroNaFaixa("Digite a quantidade[1:30] -> ",1,30);

    cout << endl << endl;
    ImprimirTitulo("Notas Soltas");
    cout << endl;

    for (int i=1;i<=quantNotas;i++){
		nota.Randomizar(gDificuldade);
		nota.ImprimirEmTela();
    }
    cout << endl << endl;
}

void MenuConfiguracoes(){
    cout << endl << endl;
    ImprimirTitulo("Configuracoes");
    cout << "A dificuladed atualmetnte eh "<<gDificuldade<< endl;
    gDificuldade=ObterNumeroNaFaixa("Indique o nivel de dificuldade -> [1-facil, 2-medio ou 3-dificil] ->",1,3);
}

void MenuIntervalos(){
    cout << endl << endl;
    ImprimirTitulo("Intervalos");
    cout << "**********************************************************\n";
    cout << "** 1) Uma nota e um intervalo simples, qual outra nota? **\n";
    cout << "** 2) Duas Notas, qual intervalo simples?               **\n";
    cout << "**********************************************************\n";
    int opcao=ObterNumeroNaFaixa("Indica sua opção [1:2] -> ",1,2);
    cout << endl;


    switch (opcao)
    {
		case 1:UC01();break;
		case 2:UC02();break;
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
    int opcao=ObterNumeroNaFaixa("Indica sua opção [1:4] -> ",1,4);
    cout << endl;

    switch (opcao)
    {
		case 1:UC03();break;
		case 2:UC04();break;
		case 3:UC05();break;
		case 4:UC06();break;
		default:
		break;
    }

    cout << endl << endl;
}

void UC01(){
    Intervalo intervalo;
    int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);

    for(int i=1; i<=quantidade; i++){
		intervalo.Randomizar(gDificuldade);
		intervalo.ImprimirEmTela();//alterar para mostrar apenas a primeira nota
		cout << intervalo.DeduzirTipoIntervalo() << " ";
		intervalo.ImprimirOrientacaoEmTela();
		cout << " / ";
    }
}

void UC02(){
    Intervalo intervalo;
    int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);

    for(int i=1; i<=quantidade; i++){
		intervalo.Randomizar(gDificuldade);
		intervalo.ImprimirEmTela();
		cout << " / ";
    }
}

void UC03(){
    Triade triade;
    int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);

    for(int i=1; i<=quantidade; i++){
		triade.Randomizar(gDificuldade);
		triade.ImprimirFundamentalEmTela();
		cout << " " << triade.RandomizarTipoTriade();
		cout << " / ";
    }
}

void UC04(){
    Triade triade;
    int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:30] -> ",1,30);

    for(int i=1; i<=quantidade; i++){
		triade.Randomizar(gDificuldade);
		triade.ImprimirEmTela();
		cout << " / ";
    }
}

void UC05(){

    Triade triade;
    int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:10] -> ",1,10);

    struct tNoh {
		Triade triade;
		int diff3;
		int diff5;
    };
    tNoh nohs[quantidade];

    // Popular arrray de struct
    for(int i=0; i<=quantidade-1; i++){
		triade.Randomizar();
		nohs[i].triade=triade;
		nohs[i].diff3=3;
		nohs[i].diff5=5;
    }

    // Imprimir 5 nota
    for(int i=0; i<=quantidade-1; i++){
		nohs[i].triade.getQuinta().ImprimirEmTela();
		cout << "\t" << nohs[i].diff5 << "\t";
    }
    cout << endl;

    // Imprimir 3 nota
    for(int i=0; i<=quantidade-1; i++){
		nohs[i].triade.getTerca().ImprimirEmTela();
		cout << "\t" << nohs[i].diff3 << "\t";
    }
    cout << endl;

    // Imprimir fundamental
    for(int i=0; i<=quantidade-1; i++){
		nohs[i].triade.getFundamental().ImprimirEmTela();
		cout << "\t\t";
    }
    cout << endl;
}


void UC06(){

    Triade triade;
    int quantidade=ObterNumeroNaFaixa("Informe a quantidade[1:10] -> ",1,10), inversao;

    struct tNoh {
		Triade triade;
		int inversao;
		int diff3;
		int diff5;
    };
    tNoh nohs[quantidade];

    // Popular arrray de struct
    for(int i=0; i<=quantidade-1; i++){
		triade.Randomizar();
		nohs[i].triade=triade;

		nohs[i].inversao = GerarInteiro(1,2);

		if (nohs[i].inversao == 1){
			nohs[i].diff5=6;
			nohs[i].diff3=3;
		}
		else if (nohs[i].inversao == 2){
			nohs[i].diff5=6;
			nohs[i].diff3=4;
		}
    }

    cout << endl;
    cout << endl;

    // Imprimir 5 nota
    for(int i=0; i<=quantidade-1; i++){
		(nohs[i].inversao == 1) ? 
			nohs[i].triade.getFundamental().ImprimirEmTela() : 
			nohs[i].triade.getTerca().ImprimirEmTela();
		cout << "\t" << nohs[i].diff5 << "\t";
	    
    }
    cout << endl;

    // Imprimir 3 nota
    for(int i=0; i<=quantidade-1; i++){
		(nohs[i].inversao == 1) ?
			nohs[i].triade.getQuinta().ImprimirEmTela() : 
			nohs[i].triade.getFundamental().ImprimirEmTela();
		cout << "\t" << nohs[i].diff3 << "\t";
	    
    }
    cout << endl;

    // Imprimir o baixo 
    for(int i=0; i<=quantidade-1; i++){
		(nohs[i].inversao == 1) ? 
			nohs[i].triade.getTerca().ImprimirEmTela() : 
			nohs[i].triade.getQuinta().ImprimirEmTela();
		cout << "\t\t";
    }


}

void TestarIntervalo(){
    Nota n1,n2;
    Intervalo i;
    int orientacao=-1;
    n1.setNota(5,2,0);
    n2.setNota(4,7,0);
	n1.ImprimirEmTela();
	n2.ImprimirEmTela();
    i.setN1(n1);
    i.setN2(n2);
    i.ImprimirEmTela();
    cout << i.DeduzirTipoIntervalo();
/*
    n1.setNota(4,1,0);

    string intervalos[]={"","2m","2M","3m","3M","4J","4A","5D","5J","6m","6M","7m","7M"};

    cout << "Nota\t2m\t2M\t3m\t3M\t4J\t4A\t5D\t5J\t6m\t6M\t7m\t7M" << endl;
    for (int ii=1; ii<=12; ii++){
	n1.ImprimirEmTela();
	cout << '\t' ;
	i.setN1(n1);

	for (int iii=1;iii<=12;iii++){
	    i.setN2(intervalos[iii],orientacao);
	    i.getN2().ImprimirEmTela();
	    cout << '\t' ;
		
	}

	cout << endl;
	n1.up1Semitom();

    }

    n1.setNota(4,7,-1);
    for (int ii=1; ii<=11; ii++){
	n1.ImprimirEmTela();
	cout << '\t' ;
	i.setN1(n1);

	for (int iii=1;iii<=12;iii++){
	    i.setN2(intervalos[iii],orientacao);
	    i.getN2().ImprimirEmTela();
	    cout << '\t' ;
		
	}

	cout << endl;
	n1.down1Semitom();
    }
*/
}

void TestarTriade(){
    Triade t;
    for (int z=1; z<=60; z++){
		t.Randomizar();
		t.ImprimirEmTela();
		cout << " ";
    }
}

void TestarNota(){
    Nota n(3,7,0);
    for (int i=1;i<30;i++){
		n.ImprimirEmTela();
		cout << n.getId()<< " ";
		n.up1Semitom();
    }
}
