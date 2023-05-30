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

	keypad(inputwin,true);
	
	int c = wgetch(inputwin);

	if( c == KEY_UP )
	{
		//mvwprintw(inputwin, 1, 1, "You pressed j");
		mvwprintw(inputwin, 1, 1, "voce preosionou UP");
	}else if (c == KEY_DOWN)
	{
		mvwprintw(inputwin, 1, 1, "voce preosionou DOWN");
	}
	wrefresh(inputwin);

	getch();
	endwin();

	return 0;
}
