#include <ncurses.h>			  
#include <cstring> 

int main(){
  char mesg[]="Alguma string";		
  int row,col;				

  initscr();				
  getmaxyx(stdscr,row,col);		
  mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);

  mvprintw(row-2,0,"Essa tela tem %d linhas e %d colunas\n",row,col);
  printw("Tente redimensionar sua janela (se possível) e execute este programa novamente.");
  refresh();
  getch();
  endwin();

  return 0;
}
