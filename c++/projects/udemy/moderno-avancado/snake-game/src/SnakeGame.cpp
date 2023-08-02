#include "SnakeGame.h"

//---------------------------------------
// Prototipations
//---------------------------------------
int GerarInteiro(const int, const int);

//---------------------------------------
// Constructors/destructors
//---------------------------------------
SnakeGame::SnakeGame(){
	initscr();
	nodelay(stdscr, true); // para snake nap parar
	keypad(stdscr, true);
	noecho(); //para nao exibir as teclas na tela
	curs_set( 0 );	//desliga cursor
	srand(time(NULL));
	

	//bodas
	this->m_bordas();

	// iniciar cobra  
	int tempx = GerarInteiro(1,this->m_maxwidth-2);
	int tempy = GerarInteiro(1,this->m_maxheight-2);
	this->snake.push_back( SnakeType( tempx, tempy));
	move( snake[0].s_y, snake[0].s_x);
	addch( m_snake_char );

	//comida
	this->m_insert_food();
	move( v_food.s_y, v_food.s_x);
	addch(this->m_food_char);
	
}

//---------------------------------------
// publics 
//---------------------------------------
void SnakeGame::start(){
	m_movesnake();
	usleep( m_delay );
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
		int tempx = GerarInteiro(1,this->m_maxwidth-2);
		int tempy = GerarInteiro(1,this->m_maxheight-2);

		//nao utiliar pontos ocupados pela cobra
		for (size_t i=0; i < this->snake.size(); ++i){

			if ( snake[i].s_x == tempx && snake[i].s_y == tempy){
				continue;
			}
		}

		this->v_food.s_x = tempx;
		this->v_food.s_y = tempy;
		break;
	}
}

void SnakeGame::m_movesnake(){
	int tmp = getch();
	switch( tmp ){
		case KEY_LEFT:
			if( this->m_direction != 'R'){
				this->m_direction = 'L';
			}
			break;
		case KEY_UP:
			if( this->m_direction != 'D'){
				this->m_direction = 'U';
			}
			break;
		case KEY_DOWN:
			if( this->m_direction != 'U'){
				this->m_direction = 'D';
			}
			break;
		case KEY_RIGHT:
			if( this->m_direction != 'L'){
				this->m_direction = 'R';
			}
			break;
		case 'q':
			m_direction = 'Q';
			break;
	}

	if (!m_tail_stop){
		move( snake[snake.size()-1].s_y, snake[snake.size() - 1].s_x);
		printw(" ");
		refresh();
		snake.pop_back();
	}

	if ( m_direction == 'L' ){
		snake.insert( snake.begin(), SnakeType( snake[0].s_x - 1, snake[0].s_y     ));
	}

	if ( m_direction == 'R' ){
		snake.insert( snake.begin(), SnakeType( snake[0].s_x + 1, snake[0].s_y     ));
	}

	if ( m_direction == 'U' ){
		snake.insert( snake.begin(), SnakeType( snake[0].s_x    , snake[0].s_y - 1 ));
	}
	
	if ( m_direction == 'D' ){
		snake.insert( snake.begin(), SnakeType( snake[0].s_x    , snake[0].s_y + 1 ));
	}

	move( snake[0].s_y, snake[0].s_x);
	addch( m_snake_char );
	refresh();

}

//---------------------------------------
// Internals
//---------------------------------------
int GerarInteiro(const int menor, const int maior) {

    if (maior > menor){
        int faixa  = (maior - menor + 1);
        int gerado = (1 + rand() % faixa);
        return menor + (gerado-1);
    }
    else
        return 0;

}

