#include "Triade.h"
#include "Janela.h"

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////
int menu();
void MenuConfiguracoes();
void MenuIntervalos();
void MenuTriades();
void ChamarMenu();
void Notas();
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
void TesteJanela();

/////////////////////////////////////////
// Elelementos Globais
/////////////////////////////////////////
int gDificuldade=1;

enum Saidas{
	sucesso,
	erro_leitura,
	erro_permissao
};

int xMax, yMax;
//Janela jDown(3,xMax,yMax-3,0);

struct tIntervaloResposta {
	Intervalo intervalo;
	string questao;
	string resposta;
};

/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main(int argc, char *argv[] ){
//	Iniciais
    srand( time(0) );
	ToShowParameters(argc, argv);

//	corpo
//	TestarIntervalo();
	Ncurses();
//	TesteJanela();

//	finais
	cout << endl;
	return 0; //indica o fim do programa2

/*
ImprimirTitulo("Gerador Exercicios");
ChamarMenu();
UC06(10);
TodosIntervalos();
TestarTriade();
TestarNota();
cout << agc << endl;
iicout << argv[0] << endl;
cout << argv[1] << endl;
*/

}//main


int nCursesMenu(const vector <string> &choices, int xMax, int begin_y){
	int maiorTamanhoItem=0;
	const int qtdOpcoes=choices.size();

	for (int i=0; i<qtdOpcoes; i++){
		if ( choices[i].length() > maiorTamanhoItem ){
			maiorTamanhoItem = choices[i].length();
		}
	}
	
	WINDOW *menuWin = newwin(qtdOpcoes+2, maiorTamanhoItem+2, begin_y, (xMax/2)-(maiorTamanhoItem/2));
	refresh();
//	box(menuWin, (int)'|', (int)'-');
	box(menuWin,0,0);
	wrefresh(menuWin);
	keypad(menuWin,true);
	

	int choice;
	int highligth=0;
	while(1){
		for (int i=0; i<qtdOpcoes; i++){
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
				if( highligth == (qtdOpcoes) )
					highligth = qtdOpcoes - 1;
				break;
			default:
				break;
		}

		if( choice == 10 )
			break;
	}

	menuWin=NULL;

	return highligth;

}//nCursesMenu

void nCursesClearScreen(int yMax, int xMax,int begin_y){
	WINDOW *clsWin = newwin((yMax - begin_y)-4, xMax, begin_y, 0);
	refresh();
	wrefresh(clsWin);
	werase(clsWin);
	clsWin=NULL;
}//nCursesClearScreen

string nCursesObterString(string mensagem, int begin_y, int xMax, int n){	
	// mensagem - mensagem a ser apresentada
	// begin_y - posicao y que inicial a winodws
	// xMax - extensao horizintal onde a window sera criada
	// n - quantiade de caracteres que poderao ser digitado
	int tamanhoMensagem = mensagem.length();
	char *prtMensagem = &mensagem[0];

	char digitado[80];

	echo();
	WINDOW *obterNumeroWin = newwin(3, xMax, begin_y, xMax);
	werase(obterNumeroWin);
	refresh();
	wrefresh(obterNumeroWin);
	obterNumeroWin=NULL;

	obterNumeroWin = newwin(3, tamanhoMensagem+n+3, begin_y, (xMax/2)-(tamanhoMensagem/2));
	box(obterNumeroWin,0,0);
	mvwprintw(obterNumeroWin,1,1,prtMensagem);
	refresh();
	wrefresh(obterNumeroWin);
	wgetnstr(obterNumeroWin,digitado,n);
	obterNumeroWin=NULL;
	noecho();

	return digitado;
}//nCursesObterString

int nCursesObterNumero(string mensagem, int begin_y, int xMax, int n){	
	string resposta=nCursesObterString(mensagem, begin_y, xMax, n);
	char *ptrResposta=&resposta[0];
	return atoi(ptrResposta);
}

void UC01(int quantidade){
	//exercicios
	Intervalo intervalo;
	string questao, resposta;
	int colunas, qtdCertas=0, qtdErradas=0;
	struct tIntervaloResposta {
		Intervalo intervalo;
		string questao;
		string resposta;
	};
	tIntervaloResposta intervalosRespostas[quantidade];
	colunas=10;
	Janela jContagem(3,colunas,9,(xMax/2)-(colunas/2));

	jContagem.Centralizar("0 de "+to_string(quantidade));

	//perguntas
	for(int i=0; i<=(quantidade-1); i++){
		intervalo.Randomizar(gDificuldade);
		questao = intervalo.getN1().Descricao();
		questao += "/";
		questao += intervalo.OrientacaoEmString();
		questao += "/";
		questao += intervalo.DeduzirTipoIntervalo();
		questao += ": ";

		do{
			resposta = nCursesObterString(questao,6,xMax,6);
		}while (!intervalo.getN1().strEhNota(resposta));

		intervalosRespostas[i].intervalo = intervalo;
		intervalosRespostas[i].resposta = resposta;
		intervalosRespostas[i].questao = questao;

		jContagem.Centralizar(to_string(i+1)+" de "+to_string(quantidade));
	}

	//resultado
	colunas=40;
	Janela jResultado(quantidade+6,colunas,12,(xMax/2)-(colunas/2));
	jResultado.Imprimir(1,1,"Resultados :");
	string linha;
	for( int i=0; i<=quantidade-1; i++){
		linha = to_string(i+1)+") "+intervalosRespostas[i].questao;
		if( intervalosRespostas[i].resposta==intervalosRespostas[i].intervalo.getN2().Descricao() ){
			linha += intervalosRespostas[i].resposta;
			linha += " Certa";
			qtdCertas++;
		}
		else{
			linha += intervalosRespostas[i].resposta;
			linha += "->";
			linha += intervalosRespostas[i].intervalo.getN2().Descricao();
			qtdErradas++;
		}
		jResultado.Imprimir(i+2,1,linha);
	}
	//resumo resultado
	jResultado.Imprimir(quantidade+3,1,"Certas: "+to_string(qtdCertas));
	jResultado.Imprimir(quantidade+4,1,"Erradas: "+to_string(qtdErradas));
	getch();
}

void UC02(int quantidade){
	int colunas=10;
	Intervalo intervalo;
	string questao, resposta;
	tIntervaloResposta intervalosRespostas[quantidade];
	
	Janela jContagem(3,colunas,9,(xMax/2)-(colunas/2));

	jContagem.Centralizar("0 de "+to_string(quantidade));


	//perguntas
	for(int i=0; i<=(quantidade-1); i++){
		intervalo.Randomizar(gDificuldade);
		questao = intervalo.getN1().Descricao();
		questao += " e ";
		questao += intervalo.getN2().Descricao();
		questao += " : ";

		do{
			resposta = nCursesObterString(questao,6,xMax,2);
		}while (!intervalo.strEhIntervalo(resposta));

		intervalosRespostas[i].intervalo = intervalo;
		intervalosRespostas[i].resposta = resposta;
		intervalosRespostas[i].questao = questao;

		jContagem.Centralizar(to_string(i+1)+" de "+to_string(quantidade));
	}

	//resultado
	colunas=40;
	int qtdCertas=0, qtdErradas=0;
	Janela jResultado(quantidade+6,colunas,12,(xMax/2)-(colunas/2));
	jResultado.Imprimir(1,1,"Resultados :");
	string linha;
	for( int i=0; i<=quantidade-1; i++){
		linha = to_string(i+1)+") "+intervalosRespostas[i].questao;
		if( intervalosRespostas[i].resposta==intervalosRespostas[i].intervalo.DeduzirTipoIntervalo() ){
			linha += intervalosRespostas[i].resposta;
			linha += " Certa";
			qtdCertas++;
		}
		else{
			linha += intervalosRespostas[i].resposta;
			linha += "->";
			linha += intervalosRespostas[i].intervalo.DeduzirTipoIntervalo();
			qtdErradas++;
		}
		jResultado.Imprimir(i+2,1,linha);
	}
	
	//resumo resultado
	jResultado.Imprimir(quantidade+3,1,"Certas: "+to_string(qtdCertas));
	jResultado.Imprimir(quantidade+4,1,"Erradas: "+to_string(qtdErradas));
	getch();
}

void nCursesMenuIntervalo(int yMax,int xMax){
	vector<string> choices;
	int choice, quantidade;
	
	choices.push_back("Uma nota, uma orientacao(asc, desc) e um intervalo simples. Qual outra nota?");
	choices.push_back("Duas Notas. Qual o intervalo simples?");
	choices.push_back("Voltar!");
	while( true )
	{
		nCursesClearScreen(yMax, xMax, 3);
		choice=nCursesMenu(choices,xMax,3);
		if (choice==2)
			break;

		// perguntar a quantidade
		do
		{
			nCursesClearScreen(yMax, xMax, 3);
			quantidade = nCursesObterNumero("Digite a quantidade de exercicios [1-10]: " ,3,xMax,2);
		}while( (quantidade < 1) || (quantidade > 10) );

		switch( choice ){	
			case 0:UC01(quantidade);break;
			case 1:UC02(quantidade);break;
			default:
				   break;
		}


	}
}//nCursesMenuIntervalo

void nCursesMenuTriade(int xMax){
	vector<string> choices;
	choices.push_back("Uma nota e uma triade (M,m,A,d). Qual a terca e a quinta?");
	choices.push_back("Fundamental, terca e quinta. Qual triade (M,m,A,d)?");
	choices.push_back("Triade estado fundamental. Qual 1º e 2º inversão?");
	choices.push_back("Uma traide invertida. Qual o Estado Fundamental?");
	choices.push_back("Voltar!");
}//nCursesMenuTriade


void Ncurses(){

	initscr();
	cbreak();
	noecho();
	
	//int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	Janela jUP(3,xMax,0,0);
	jUP.Centralizar("Exercicios para os alunos da EMUFPA");
	
	
	vector<string> choices;
	int choice;
	
	while( true ){
		nCursesClearScreen(yMax, xMax, 3);
		choices={"Notas","Intervalo","Triade","Tetrade","Configuracoes","Sair"};
		choice=nCursesMenu(choices,xMax,3);

		if( choice==5 )
			break;

		switch( choice )
		{
			case 1:
				nCursesMenuIntervalo(yMax,xMax);
				break;
			case 2:
				nCursesMenuTriade(xMax);
				break;
			case 4:
				int dificuldade;
				do
				{
					dificuldade = nCursesObterNumero("Informe a nova dificulade: " ,11,xMax,1);
				}while( (dificuldade < 1) || (dificuldade>3) );
				gDificuldade = dificuldade;
				break;
			default:
				break;
		}

	}
	endwin();

}//Ncurses

void Splash(){
	char mesg[]="Gerados de execícios";
	int row,col;

	initscr();
	noecho();
	getmaxyx(stdscr,row,col);
	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);

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
//		case 1:UC01();break;
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
	i.ImprimirEmTela();
	cout <<	i.DeduzirTipoIntervalo() << endl;
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

void TesteJanela(){
	initscr();
	Janela jBarraUP(3,100,0,0);
	jBarraUP.Centralizar("1");
	getch();
	jBarraUP.Centralizar("11111111");
	getch();
	jBarraUP.Centralizar("2222");
	getch();
	endwin();

}
