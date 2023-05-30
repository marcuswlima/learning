#include <ncurses.h>
#include <string>

int main (int argc, char ** argv)
{
	//ncurses start
	initscr();
	noecho();
	cbreak();

	//get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	//create a windows got our imputs
	WINDOW * inputwin = newwin(3, xMax-12, yMax-5, 5);
//	box(inputwin, (int)'|', (int)'-');
	wborder(inputwin,'|','|','-','-','#','#','#','#');
	refresh();
	wrefresh(inputwin);

	int y, x, yBegm , xBeg;

	getyx(stdscr, y, x);

	move(0,0);
	printw("aqui");
	printw("%d %d %d %d",y, x, yMax, xMax);



	getch();
	endwin();

	return 0;
}
