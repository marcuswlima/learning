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
void TodosIntervalos();
void ToShowParameters(int , char *[]);
void Splash();
void Ncurses();

/////////////////////////////////////////
// Elelementos Globais
/////////////////////////////////////////
int gDificuldade=1;

enum Saidas{
	sucesso,
	erro_leitura,
	erro_permissao
};



/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main(int argc, char *argv[] ){
//	Iniciais
    srand( time(0) );
	ToShowParameters(argc, argv);

//	corpo
	Ncurses();

//	finais
	cout << endl;
	return 0; //indica o fim do programa2

/*
ImprimirTitulo("Gerador Exercicios");
ChamarMenu();
UC06(10);
TestarIntervalo();
TodosIntervalos();
TestarTriade();
TestarNota();
cout << agc << endl;
iicout << argv[0] << endl;
cout << argv[1] << endl;
*/

}//main

void nCursesUP(int max){
	WINDOW *barraUp = newwin(3, max,0,0);
	refresh();
	char v = '|';
	char h = '-';
	wborder(barraUp,v,v,h,h,'/','\\','\\','/');
	wrefresh(barraUp);
	string titulo="Gerador de Exercicio para os alunos";
	char *prtTitulo = &titulo[0];
	mvwprintw(barraUp,1,(max/2)-(titulo.length()/2),prtTitulo);
	wrefresh(barraUp);
}

int nCursesMenu(string choices[], int arraySize, int max){

	int maiorTamanhoItem=0;

	for (int i=0; i<arraySize; i++){
		if ( choices[i].length() > maiorTamanhoItem ){
			maiorTamanhoItem = choices[i].length();
		}

	}

	WINDOW *menuWin = newwin(arraySize+2, maiorTamanhoItem+2, 3, (max/2)-(maiorTamanhoItem/2));
	refresh();
//	box(menuWin, (int)'|', (int)'-');
	box(menuWin,0,0);
	wrefresh(menuWin);
	

	int choice;
	int highligth=0;
	while(1){
		for (int i=0; i<arraySize; i++){
			if (i==highligth)
				wattron(menuWin,A_REVERSE);
			mvwprintw(menuWin, i+1, 1, choices[i].c_str());
			wattroff(menuWin,A_REVERSE);
		}

		choice = wgetch(menuWin);

		switch (choice)
		{
			case KEY_UP:
				highligth--;
				if( highligth == -1 )
					highligth=0;
				break;
			case KEY_DOWN:
				highligth++;
				if( highligth == (arraySize+1) )
					highligth=arraySize;
				break;
			default:
				break;
		}

		if( choice == 10 )
			break;
	}


	return 0;
}



void Ncurses(){

	initscr();
	cbreak();
	
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	nCursesUP(xMax);

	const int qtdChoices = 4;
	string choices[qtdChoices]={"Intervalo","Triade","Tetrade","Configuracoes"};
	int choice=nCursesMenu(choices, qtdChoices, xMax);

	

//	WINDOW *menu = newwin(
	
	getch();
	endwin();
/*	
	WINDOW *barraUp = newwin(10, 10,1,1);
	char v = '|';
	char h = '_';
	char b = '*';
	wborder(barraUp,v,v,h,h,b,b,b,b);
	wrefresh(barraUp);
	getch();
	refresh();
	endwin();

	int height, width, start_y, start_x;
	height = 10;
	width = 20;
	start_y = start_x = 10;

	WINDOW * win = newwin(height, width, start_y, start_x);
	refresh();

	box(win,0,0);
	mvprintw(win, 1, 1, "this is mu box");
	wrefresh(win);
	printw("Hello Wordl");
	refresh();
	int c = getch();
	printw("%d",c);
	getch();
*/
}

void Splash(){
	char mesg[]="Gerados de execícios";
	int row,col;

	initscr();
	noecho();
	getmaxyx(stdscr,row,col);
	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);

//	mvprintw(row-2,0,"Essa tela tem %d linhas e %d colunas\n",row,col);
//	printw("Tente redimensionar sua janela (se possível) e execute este programa novamente.");
	refresh();
	getch();
	endwin();
};

void ToShowParameters(int argc, char *argv[]){
	if (argc > 1){
		for (size_t i=0 ; i<argc ; i++){
			cout << "[" << i << "]=" << argv[i] << endl;
		}
	}
	else
		cout << "sem parametros" << endl;

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
		intervalo.getN1().ImprimirEmTela();//alterar para mostrar apenas a primeira nota
		intervalo.ImprimirTipoIntervaloEmTela();
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

void TestarTriade(){
	Nota n(3,1,0);
    Triade t;
	for (int i=1; i<=12; i++){

		for (int tt=1; tt<=4; tt++){
			t.setTriade(n,tt);
			t.ImprimirEmTela();
			t.ImprimirTipoTriadeEmTela();
			cout << "\t\t";
		}
		n.up1SemiTom();
		cout << endl;
	}

	cout << endl;
	for (int i=1; i<=13; i++){

		for (int tt=1; tt<=4; tt++){
			t.setTriade(n,tt);
			t.ImprimirEmTela();
			t.ImprimirTipoTriadeEmTela();
			cout << "\t\t";
		}
		n.down1SemiTom();
		cout << endl;
	}

}//TestarTriade

void TestarNota(){
    Nota n1(3,1,-1);
    Nota n2(3,1,0);
	if ((n1<n2))
		cout << "sim-then" << endl;
	else
		cout << "nao-else" << endl;

}


void TestarIntervalo(){
    Nota n1,n2;
    Intervalo i;

	n1.setNota(3,1,0);
	i.setN1(n1);
	i.setN2("2M");
	i.getN2().ImprimirEmTela();
	i.ImprimirEmTela();
}


void TodosIntervalos(){
    Nota n1,n2;
    Intervalo i;
    string intervalos[]={"","2m","2M","3m","3M","4J","4A","5D","5J","6m","6M","7m","7M"};

	cout << "Nota\t2m\t2M\t3m\t3M\t4J\t4A\t5D\t5J\t6m\t6M\t7m\t7M" << endl;

	cout<<endl;
	n1.setNota(3,1,0);
    for (int ii=1; ii<=12; ii++){
		i.setN1(n1);
		n1.ImprimirEmTela();
		cout << '\t' ;

		for (int iii=1;iii<=12;iii++){
			i.setN2(intervalos[iii]);
			i.getN2().ImprimirEmTela();
			cout << '\t' ;
		}
		cout << endl;
		n1.up1SemiTom();
	}

	cout<<endl;
	n1.setNota(3,7,0);
    for (int ii=1; ii<=12; ii++){
		i.setN1(n1);
		n1.ImprimirEmTela();
		cout << '\t' ;

		for (int iii=1;iii<=12;iii++){
			i.setN2(intervalos[iii]);
			i.getN2().ImprimirEmTela();
			cout << '\t' ;
		}
		cout << endl;
		n1.down1SemiTom();
	}


	cout<<endl;
	n1.setNota(3,1,0);
    for (int ii=1; ii<=12; ii++){
		i.setN1(n1);
		n1.ImprimirEmTela();
		cout << '\t' ;

		for (int iii=1;iii<=12;iii++){
			i.setN2(intervalos[iii],-1);
			i.getN2().ImprimirEmTela();
			cout << '\t' ;
		}
		cout << endl;
		n1.up1SemiTom();
	}

	cout<<endl;
	n1.setNota(3,7,0);
    for (int ii=1; ii<=12; ii++){
		i.setN1(n1);
		n1.ImprimirEmTela();
		cout << '\t' ;

		for (int iii=1;iii<=12;iii++){
			i.setN2(intervalos[iii],-1);
			i.getN2().ImprimirEmTela();
			cout << '\t' ;
		}
		cout << endl;
		n1.down1SemiTom();
	}
}
