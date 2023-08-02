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
protected:
	int m_maxwidth;
	int m_maxheight;

	std::vector<SnakeType> snake;
	char m_snake_char;

	SnakeType v_food;
	char m_food_char;
private:
	void m_bordas();
	void m_insert_food();
	int GerarInteiro(int, int);
};
