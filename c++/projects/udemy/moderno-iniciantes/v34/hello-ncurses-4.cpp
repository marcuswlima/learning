#include <ncurses.h>
#include <string>

int main(int argc, char **argv){

	std::string ola="ola string";
	char *hello = &ola[0];

	if( argc > 1 ){
		hello = argv[1];
	}


	initscr();

	move(5,5);
	printw(hello);
	
	move(15,15);
	printw(hello);
	
	refresh();

	getch();

	endwin();

	return 0;
}//main

