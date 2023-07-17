#include "Ncurses.h"

Ncurses::Ncurses(){
	initscr();
	cbreak();
	noecho();
}

Ncurses::~Ncurses(){
	endwin();
}

void MenuInicial(){
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
}
