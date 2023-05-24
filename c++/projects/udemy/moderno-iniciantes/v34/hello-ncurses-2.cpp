#include <ncurses.h>
#include <string>

int main(){

	std::string ola="ola string";
	char *hello = &ola[0];
	initscr();


	printw(hello);
	
	refresh();

	getch();

	endwin();

	return 0;
}//main

