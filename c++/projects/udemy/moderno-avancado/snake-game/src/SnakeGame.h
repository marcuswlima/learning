#include <iostream> // time e rand
#include <ncurses.h>
#include <vector> //logica das coordenad
#include <unistd.h>

struct SnakeType{
	int s_x, s_y;
	SnakeType(int s_col, int s_row){
		s_x = s_col;
		s_y = s_row;
	}
	SnakeType(){
		s_x=1;
		s_y=1;
	}
};

class SnakeGame{
public:
	SnakeGame();
	~SnakeGame();
	void start();
protected:
	const char m_food_char='x';
	const char m_snake_char='o';
	int m_delay=100000;

	int m_maxwidth;
	int m_maxheight;

	char m_direction='L';//valor inicial
	bool m_tail_stop=false;
	
	std::vector<SnakeType> snake;
	SnakeType v_food;

	int m_score=0;
private:
	void m_bordas();
	void m_insert_food();
	void m_movesnake();
	bool _collide();
};
