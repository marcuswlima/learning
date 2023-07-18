#include "ncurses-notas.h"

NcursesNotas::NcursesNotas(){
	this->iniciar(0);
}

NcursesNotas::NcursesNotas(int dificuldade){
	this->iniciar(dificuldade);
}

void NcursesNotas::iniciar(int dificuldade){
	initscr();
	getmaxyx(stdscr, this->yMax, this->xMax);
	setDificuldade(dificuldade);
	cbreak();
	noecho();

	this->menuInicial();
}

NcursesNotas::~NcursesNotas(){
	endwin();
}


void NcursesNotas::setDificuldade(int p){
	this->dificuldade = p;
}

int NcursesNotas::getDificuldade(){
	return this->dificuldade;
}

void NcursesNotas::menuInicial(){
//	vector<string> choices;
	int choice;
	const char * choices[5]={"Intervalo","Triade","Tetrade","Configuracoes","Sair"};
	
	while( true ){
		this->clearscreen(3);
		choice=this->montaMenu(choices,3,5);

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


void NcursesNotas::clearscreen(int begin_y){
	WINDOW *clsWin = newwin((this->yMax - begin_y)-4, this->xMax, begin_y, 0);
	refresh();
	wrefresh(clsWin);
	werase(clsWin);
	clsWin=NULL;
}//nCursesClearScreen

int NcursesNotas::montaMenu(const char **prtChoices, int begin_y, const int qtdOpcoes){
	size_t maiorTamanhoItem=0;

	for (int i=0; i<qtdOpcoes; i++){
		if ( strlen(prtChoices[i]) > maiorTamanhoItem ){
			maiorTamanhoItem = strlen(prtChoices[i]);
		}
	}
	this->begin_xMainMenu = (xMax/2)-(maiorTamanhoItem/2);
	
	WINDOW *menuWin = newwin(qtdOpcoes+2, maiorTamanhoItem+2, begin_y,this->begin_xMainMenu);
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
			mvwprintw(menuWin, i+1, 1, prtChoices[i]);
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
}//montarMenu


