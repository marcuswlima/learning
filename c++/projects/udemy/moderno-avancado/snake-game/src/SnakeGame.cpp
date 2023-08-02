#include "SnakeGame.h"

//---------------------------------------
// Constructors/destructors
//---------------------------------------
SnakeGame::SnakeGame(){
	initscr();
	nodelay(stdscr, true); // para snake nap parar
	keypad(stdscr, true);
	noecho();
	curs_set( 0 );	
	
	this->m_snake_char='o';

	srand(time(NULL));

	this->m_food_char='x';

	this->m_bordas();

	// desenha o tamanho inicial da snake
	for (int i=0; i < 13 ; ++i){
		this->snake.push_back( SnakeType( 20 + i, 10));
	}

	//logica para posicionar/desenhar a cobra
	for ( size_t i=0; i < snake.size(); ++i){
		move( snake[i].s_y, snake[i].s_x);
		addch( m_snake_char );
	}
}

SnakeGame::~SnakeGame(){
	nodelay( stdscr, false);
	getch();
	endwin();
}

//---------------------------------------
// Privates
//---------------------------------------
void SnakeGame::m_bordas(){
	this->m_maxheight = getmaxy (stdscr) / 2;
	this->m_maxwidth = getmaxx (stdscr) / 2 ;

//	m_maxheight = 15;
//	m_maxwidth = 13;

	for ( int i=0; i < this->m_maxwidth; i++){
		move(0,i);
		if ((i==0) || (i == this->m_maxwidth-1 ))
			addch('+');
		else
			addch('-');
	}

	for ( int i=1; i < this->m_maxheight-1; i++){
		move(i,0);
		addch('|');
		move(i,this->m_maxwidth-1);
		addch('|');
	}

	for ( int i=0; i < this->m_maxwidth; i++){
		move(this->m_maxheight-1,i);
		if ((i==0) || (i == this->m_maxwidth-1 ))
			addch('+');
		else
			addch('-');
	}
}

void SnakeGame::m_insert_food(){
	while( true ){
		int tempx = GerarInteiro(1,this->m_maxwidth);
		int tempy = GerarInteiro(1,this->m_maxheight);

	}
}

int SnakeGame::GerarInteiro(int menor, int maior) {

    if (maior > menor){
        int faixa  = (maior - menor + 1);
        int gerado = (1 + rand() % faixa);
        return menor + (gerado-1);
    }
    else
        return 0;

}


