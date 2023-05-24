#include <ncurses.h>
#include <string>

int main(int argc, char **argv){

	std::string ola="ola string";
	char *hello = &ola[0];

	if( argc > 1 ){
		hello = argv[1];
	}


	initscr();


	printw(hello);
	
	refresh();

	getch();

	endwin();

	return 0;
}//main

