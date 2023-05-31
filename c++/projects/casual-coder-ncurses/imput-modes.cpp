#include <ncurses.h>
#include <string>
using namespace std;

int main (int argc, char ** argv)
{
	//ncurses start
	initscr();
	noecho();

	//ImputsMOdes
	cbreak();
	//halfdelay(tenths)
	//nodelay(stdscr,true)
	//timeout(deplay)

	int c;
	while( (c=getch()) != 'x' )
	{
		printw("%d\n",c);
	}
	
	endwin();
	
	return 0;
}
