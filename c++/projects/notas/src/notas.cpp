#include "Triade.h"
#include "Janela.h"

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////
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

enum Saidas{
	sucesso,
	erro_leitura,
	erro_permissao
};

int gDificuldade = 1, xMax, yMax, begin_xMainMenu;
Janela jUp, jDown;

struct tIntervaloResposta {
	Intervalo intervalo;
	string questao;
	string resposta;
};

void SetagensIniciais(){
    srand( time(0) );
	initscr();
	getmaxyx(stdscr, yMax, xMax);
	jUp.Instanciar(3,xMax,0,0);
	jUp.Centralizar("Exercicios para os alunos da EMUFPA");
//	jDown.Instanciar(3,xMax,yMax-3,0);
//	jDown.Imprimir(1,1,"Escolha a sua opcao");
//	jDown.Imprimir(1,xMax-15,"Dificuldade: "+to_string(gDificuldade));
}


/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main(int argc, char *argv[] ){
//	Iniciais
	ToShowParameters(argc, argv);
//	SetagensIniciais();

//	corpo
	TestarNota();
//	Ncurses();
//	TesteJanela();

//	finais
	cout << endl;
	return 0; //indica o fim do programa2

}//main


int nCursesMenu(const vector <string> &choices, int begin_y){
	int maiorTamanhoItem=0;
	const int qtdOpcoes=choices.size();

	for (int i=0; i<qtdOpcoes; i++){
		if ( choices[i].length() > maiorTamanhoItem ){
			maiorTamanhoItem = choices[i].length();
		}
	}

	begin_xMainMenu = (xMax/2)-(maiorTamanhoItem/2);
	
	WINDOW *menuWin = newwin(qtdOpcoes+2, maiorTamanhoItem+2, begin_y,begin_xMainMenu);
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

void nCursesClearScreen(int begin_y){
	WINDOW *clsWin = newwin((yMax - begin_y)-4, xMax, begin_y, 0);
	refresh();
	wrefresh(clsWin);
	werase(clsWin);
	clsWin=NULL;
}//nCursesClearScreen

string nCursesObterString(string mensagem, int begin_y, int begin_x, int n){	
	// mensagem - mensagem a ser apresentada
	// begin_y - posicao y que inicial a winodws
	// begin_x - posicao x que inicial a winodws. se 0, será centralizado
	// n - quantiade de caracteres que poderao ser digitado
	int tamanhoMensagem = mensagem.length();
	int tamanhoJanela = tamanhoMensagem+n+3;
	int iBegin_x;
	char *prtMensagem = &mensagem[0];
	char digitado[80];

	if( begin_x == 0){
		iBegin_x=(xMax/2)-(tamanhoJanela/2);
	}else{
		iBegin_x=begin_x;
	}
/*	
	WINDOW *limparWin = newwin(3, xMax, begin_y, iBegin_x);
	box(limparWin,0,0);
	werase(limparWin);
	wrefresh(limparWin);
	refresh();
//	limparWin=NULL;
*/
	WINDOW *obterNumeroWin = newwin(3, tamanhoJanela, begin_y, iBegin_x); 
	box(obterNumeroWin,0,0);
	mvwprintw(obterNumeroWin,1,1,prtMensagem);
	refresh();
	wrefresh(obterNumeroWin);
	echo();
	wgetnstr(obterNumeroWin,digitado,n);
	noecho();
	obterNumeroWin=NULL;

	return digitado;
}//nCursesObterString

int nCursesObterNumero(string mensagem, int begin_y, int begin_x, int n){	
	string resposta=nCursesObterString(mensagem, begin_y, begin_x, n);
	char *ptrResposta=&resposta[0];
	return atoi(ptrResposta);
}

void UC01(int quantidade){
	Intervalo intervalo;
	string questao, resposta;
	int qtdCertas=0, qtdErradas=0;
	string linha;
	
	nCursesClearScreen(10);
	int tamanhoJanela=40;
	Janela jResultado(quantidade+6,tamanhoJanela,10,(xMax/2)-(tamanhoJanela/2));
	jResultado.Imprimir(1,1,"Questoes:");

	//perguntas
	for(int i=0; i<=(quantidade-1); i++){
		intervalo.Randomizar(gDificuldade);
		questao = intervalo.getN1().Descricao();
		questao += " e ";
		questao += intervalo.getN2().Descricao();
		questao += " : ";

		linha = to_string(i+1)+") "+questao;

		jResultado.Imprimir(i+2,1,linha);
		do{
			resposta = jResultado.CapturarPalavra(2);
		}while (!intervalo.strEhIntervalo(resposta));

		if( resposta == intervalo.DeduzirTipoIntervalo() ){
			linha = " Certa";
			qtdCertas++;
		}else{
			linha = " Errada";
			linha += "->";
			linha += intervalo.DeduzirTipoIntervalo();
			qtdErradas++;
		}

		jResultado.Imprimir(i+2,20,linha);
	}
	
	//resumo resultado
	jResultado.Imprimir(quantidade+3,1,"Certas: "+to_string(qtdCertas));
	jResultado.Imprimir(quantidade+4,1,"Erradas: "+to_string(qtdErradas));
	getch();
}//UC01

void UC02(int quantidade){
	Intervalo intervalo;
	string questao, resposta;
	int qtdCertas=0, qtdErradas=0;
	string linha;
	
	nCursesClearScreen(10);
	int tamanhoJanela=45;
	Janela jResultado(quantidade+6,tamanhoJanela,10,(xMax/2)-(tamanhoJanela/2));
	jResultado.Imprimir(1,1,"Questoes:");

	//perguntas
	for(int i=0; i<=(quantidade-1); i++){
		intervalo.Randomizar(gDificuldade);
		questao = intervalo.getN1().Descricao();
		questao += "-? ";
		questao += intervalo.DeduzirTipoIntervalo()+" ";
		questao += intervalo.OrientacaoEmString();
		questao += ":";

		linha = to_string(i+1)+") "+questao;

		jResultado.Imprimir(i+2,1,linha);
		do{
			resposta = jResultado.CapturarPalavra(6);
		}while (!intervalo.getN1().strEhNota(resposta));

		if( resposta == intervalo.getN2().Descricao() ){
			linha = " Certa";
			qtdCertas++;
		}else{
			linha = " Errada";
			linha += "->";
			linha += intervalo.getN2().Descricao();
			qtdErradas++;
		}

		jResultado.Imprimir(i+2,30,linha);
	}
	
	//resumo resultado
	jResultado.Imprimir(quantidade+3,1,"Certas: "+to_string(qtdCertas));
	jResultado.Imprimir(quantidade+4,1,"Erradas: "+to_string(qtdErradas));
	getch();
}//UC02

void UC03(int quantidade){
	Intervalo intervalo;
	string questao, resposta;
	int qtdCertas=0, qtdErradas=0;
	string linha;
	
	nCursesClearScreen(10);
	int tamanhoJanela=48;
	Janela jResultado(quantidade+6,tamanhoJanela,10,(xMax/2)-(tamanhoJanela/2));
	jResultado.Imprimir(1,1,"Questoes:");

	//perguntas
	for(int i=0; i<=(quantidade-1); i++){
		intervalo.Randomizar(gDificuldade);
		questao = "? - ";
		questao += intervalo.getN2().Descricao()+" ";
		questao += intervalo.DeduzirTipoIntervalo()+" ";
		questao += intervalo.OrientacaoEmString();
		questao += ": ";

		linha = to_string(i+1)+") "+questao;

		jResultado.Imprimir(i+2,1,linha);
		do{
			resposta = jResultado.CapturarPalavra(6);
		}while (!intervalo.getN1().strEhNota(resposta));

		if( resposta == intervalo.getN1().Descricao() ){
			linha = " Certa";
			qtdCertas++;
		}else{
			linha = " Errada";
			linha += "->";
			linha += intervalo.getN1().Descricao();
			qtdErradas++;
		}

		jResultado.Imprimir(i+2,33,linha);
	}
	
	//resumo resultado
	jResultado.Imprimir(quantidade+3,1,"Certas: "+to_string(qtdCertas));
	jResultado.Imprimir(quantidade+4,1,"Erradas: "+to_string(qtdErradas));
	getch();
}//uc03

void UC04(int quantidade){
	int tamanhoJanela=60;
	string linha, resposta;
	Nota nota;
	Intervalo intervalo;

	nCursesClearScreen(10);
	Janela jResultado(quantidade+6,tamanhoJanela,10,(xMax/2)-(tamanhoJanela/2));
	jResultado.Imprimir(1,1,"Montagens:");
	
	for(int i=0; i<=(quantidade-1); i++){
		linha = to_string(i+1)+") Nota: ";
		jResultado.Imprimir(i+2,1,linha);

		do{
			resposta = jResultado.CapturarPalavra(6);
		}while (!Nota::strEhNota(resposta));

		nota.setNota(resposta);
		intervalo.setN1(nota);

		linha = " Intervalo: ";
		jResultado.Imprimir(i+2,15," Intervalo:");
		
		do{
			resposta = jResultado.CapturarPalavra(2);
		}while (!intervalo.strEhIntervalo(resposta));
		
		intervalo.setN2(resposta,1); //intervalo ascendente
		jResultado.Imprimir(i+2,30,"Asc:"+intervalo.getN2().Descricao());
		
		intervalo.setN2(resposta,-1); //intervalo descendente
		jResultado.Imprimir(i+2,40,"Desc:"+intervalo.getN2().Descricao());
	}
	getch();
}//UC04


void nCursesMenuIntervalo(){
	//jDown.Limpar();
	//jDown.Imprimir(1,1,"Intervalos");
	vector<string> choices;
	int choice, quantidade;
	
	choices.push_back("Duas Notas. Qual orientação? Qual o intervalo simples?");
	choices.push_back("Primeira Nota, uma orientacao(asc, desc) e um intervalo simples. Qual a segunda nota?");
	choices.push_back("Segunda Nota, uma orientacao(asc, desc) e um intervalo simples. Qual a primeira nota?");
	choices.push_back("Montagem de Intervalo");
	choices.push_back("Voltar!");

	while( true ){
		nCursesClearScreen(3);
		choice=nCursesMenu(choices,3);
		if (choice==4){
			//jDown.Limpar();
			//jDown.Imprimir(1,1,"Escolha a sua opção");
			break;
		}

		// perguntar a quantidade
		do
		{
			quantidade = nCursesObterNumero("Digite a quantidade de exercicios [1-10]: ",10,0, 2);
		}while( (quantidade < 1) || (quantidade > 10) );

		switch( choice ){	
			case 0:UC01(quantidade);break;
			case 1:UC02(quantidade);break;
			case 2:UC03(quantidade);break;
			case 3:UC04(quantidade);break;
			default:
				   break;
		}

	}

}//nCursesMenuIntervalo

void UC05(int quantidade){
	int tamanhoJanela=60;
	Janela jResultado(quantidade+6,tamanhoJanela,14,(xMax/2)-(tamanhoJanela/2));
	jResultado.Imprimir(1,1,"Perguntas:");
	getch();
}

void nCursesMenuTriade(){
	int choice, quantidade;
	vector<string> choices;
	
	choices.push_back("Uma nota e uma triade (M,m,A,d). Qual a terca e a quinta?");
	choices.push_back("Uma fundamental e uma triada(M,m,A,d). Qual a terça e quinta?");
	choices.push_back("Uma terça e uma triade(M,m,A,d). Qual a fundamental e quinta?");
	choices.push_back("Uma quinta e uma triade(M,m,A,d). Qual a fundamental e quinta?");
	choices.push_back("Triade estado fundamental. Qual 1º e 2º inversão?");
	choices.push_back("Uma traide invertida. Qual o Estado Fundamental?");
	choices.push_back("Montagem de Triade");
	choices.push_back("Voltar!");
	
	while( true ){
		nCursesClearScreen(3);
		choice=nCursesMenu(choices,3);
		if (choice==5){
			break;
		}

		// perguntar a quantidade
		do
		{
			quantidade = nCursesObterNumero("Digite a quantidade de exercicios [1-10]: ",11,0, 2);
		}while( (quantidade < 1) || (quantidade > 10) );
		
		switch( choice ){	
			case 0:UC05(quantidade);break;
			default:
				   break;
		}
	}
}//nCursesMenuTriade


void Ncurses(){

	cbreak();
	noecho();
	
	vector<string> choices;
	int choice;
	
	while( true ){
		nCursesClearScreen(3);
		choices={"Intervalo","Triade","Tetrade","Configuracoes","Sair"};
		choice=nCursesMenu(choices,3);

		if( choice==4 )
			break;

		switch( choice )
		{
			case 0:
				nCursesMenuIntervalo();
				break;
			case 1:
				nCursesMenuTriade();
				break;
			case 3:
				int dificuldade;
				do
				{
					dificuldade = nCursesObterNumero("Informe a nova dificulade: " ,11,10,1);
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

/*
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
*/
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
    Nota n1;
	n1.setNota("3Do*");
	cout << n1.Descricao();
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
