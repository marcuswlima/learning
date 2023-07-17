#include "ncurses-notas.h"

ncursesNotas::ncursesNotas(){
	initscr();
	getmaxyx(stdscr, this->yMax, this->xMax);
	cbreak();
	noecho();
}

ncursesNotas::~ncursesNotas(){
	endwin();
}


void ncursesNotas::setDificuldade(int p){
	this->dificuldade = p;
}

int ncursesNotas::getDificuldade(){
	return this->dificuldade;
}

void ncursesNotas::MenuInicial(){
	vector<string> choices;
	int choice;
	
	while( true ){
		this->clearscreen(3);
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
				this->setDificuldade(dificuldade);
				break;
			default:
				break;
		}

	}
}


void ncursesNotas::clearscreen(int begin_y){
	WINDOW *clsWin = newwin((this->yMax - begin_y)-4, this->xMax, begin_y, 0);
	refresh();
	wrefresh(clsWin);
	werase(clsWin);
	clsWin=NULL;
}//nCursesClearScreen

int ncursesNotas::montaMenu(const string *prtChoices, int begin_y, const int qtdOpcoes){
	size_t maiorTamanhoItem=0;

	for (int i=0; i<qtdOpcoes; i++){
		if ( prtChoices[i].length() > maiorTamanhoItem ){
			maiorTamanhoItem = prtChoices[i].length();
		}
	}
/*
	begin_xMainMenu = (xMax/2)-(maiorTamanhoItem/2);
	
	WINDOW *menuWin = newwin(qtdOpcoes+2, maiorTamanhoItem+2, begin_y,begin_xMainMenu);
	refresh();
	*/
	return 0;
}


