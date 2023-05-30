#include <ncurses.h>
using namespace std;

int main(int argc, char ** argv)
{
	initscr();
	cbreak();
	//raw();
//	noecho();

	int height, width, start_y, start_x;
	height = 10;
	width = 20;
	start_y = start_x = 10;

	WINDOW * win = newwin(height, width, start_y, start_x);
	refresh();

	char v = '|';
	char h = '-';
	char b = '#';

//	box(win,(int)v,(int)h);
	wborder(win,v,v,h,h,b,b,b,b);
	mvwprintw(win,1,1,"This is my box");
	wrefresh(win);

	getch();
	getch();

//	int c=getch();
	endwin();

	return 0;
}//main


