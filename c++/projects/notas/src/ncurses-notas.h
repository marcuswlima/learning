#include <string>
#include <vector>
#include <ncurses.h>
using namespace std;

class ncursesNotas{
public:
	ncursesNotas();
	~ncursesNotas();
	void setDificuldade(int);
	int getDificuldade();
	void MenuInicial();
	int montaMenu(const string *, int, const int );
	void clearscreen(int);
private:
	int dificuldade=0;
	int xMax;
	int yMax;
};
