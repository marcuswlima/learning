#include <ncurses.h>
#include <string>
using namespace std;

int main (int argc, char ** argv)
{
	initscr();
	noecho();
	cbreak();

	//get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	//create a windows got our imputs
	WINDOW * menuwin = newwin(6, xMax-12, yMax-8, 5);
	box(menuwin, (int)'|', (int)'-');
	refresh();
	wrefresh(menuwin);
	keypad(menuwin, true);

	string choices[3] = {"Walk", "Jog", "Run"};
	int choice;
	int highlight = 0;

	while(1)
	{
		for( int i=0; i<3; i++)
		{
			if( i==highlight)
				wattron(menuwin, A_REVERSE);
			mvwprintw(menuwin, i+1, 1, choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}

		choice = wgetch(menuwin);
		
		if( choice == 10 )
			break;

		switch (choice)
		{
			case KEY_UP:
				highlight--;
				if ( highlight == -1 )
					highlight=0;
				break;
			case KEY_DOWN:
				highlight++;
				if( highlight == 3 )
					highlight = 2;
				break;
			default:
				break;
		}

	}

	printw("Your chice was: %s", choices[highlight].c_str());
	getch();
	endwin();

	return 0;
}
