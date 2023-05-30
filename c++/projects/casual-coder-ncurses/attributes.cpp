#include <ncurses.h>
#include <string>
#include <vector>

int main ()
{
	//ncurses start
	initscr();
	noecho();
	cbreak();
/*
	int line=1;
	std::vector<std::string> v = {"A_STANDOUT","A_UNDERLINE","A_BLINK","A_REVERSE"};
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		move(line,0);
		printw((*it).c_str());

		move(line,50);
		attron((*it).c_str());
		printw("teste");
		attroff((*it).c_str());
		line++;
	}
*/

	const char * texto="This is some text";
	move(1,0);
	printw(texto);

	move(2,0);
	attron(A_REVERSE);
	printw(texto);
	attroff(A_REVERSE);
	
	move(3,0);
	attron(A_BOLD);
	printw(texto);
	attroff(A_BOLD);
	
	move(4,0);
	attron(A_UNDERLINE);
	printw(texto);
	attroff(A_UNDERLINE);
	
	move(5,0);
	attron(A_DIM);
	printw(texto);
	attroff(A_DIM);
	
	move(6,0);
	init_pair(1,COLOR_CYAN, COLOR_WHITE);
	attron(COLOR_PAIR(1));
	printw(texto);
	attroff(COLOR_PAIR(1));
	
	move(7,0);
	init_pair(2,COLOR_YELLOW, COLOR_MAGENTA);
	attron(COLOR_PAIR(2));
	printw(texto);
	attroff(COLOR_PAIR(2));
	
	getch();
	endwin();

	return 0;
}
