#include "Janela.h"

void Moldurar(WINDOW *);

Janela::Janela(int lines, int cols, int begin_y, int begin_x){
	this->janela = newwin(lines, cols, begin_y, begin_x);
	refresh();
	Moldurar(this->janela);
	refresh();

}//construtor

void Janela::Centralizar(string mensagem){

	int yMax, xMax, tamanhoMensagem;
	char *prtMensagem = &mensagem[0];
	getmaxyx(this->janela,yMax, xMax);
	tamanhoMensagem=mensagem.length();


	werase(this->janela);
	Moldurar(this->janela);
	wmove(this->janela,yMax/2, (xMax/2)-(tamanhoMensagem/2));
	wprintw(this->janela,prtMensagem);
	wrefresh(this->janela);

}

void Janela::Imprimir(int y, int x, string str){
	wmove(this->janela,y, x);
	wprintw(this->janela,&str[0]);
	wrefresh(this->janela);
}


void Moldurar(WINDOW *janela){
	char v = '|';
	char h = '-';
	wborder(janela,v,v,h,h,'/','\\','\\','/');
	wrefresh(janela);
}

char* StrToPtr(string str){
}


