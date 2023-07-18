#include <string>
#include <vector>
#include <ncurses.h>
#include <string.h>

using namespace std;

class NcursesNotas{
public:
	NcursesNotas();
	NcursesNotas(int);
	~NcursesNotas();
private:
	void iniciar(int);
	void setDificuldade(int);
	int getDificuldade();
	void menuInicial();
	int montaMenu(const char **, int, const int );
	void clearscreen(int);
	int dificuldade=0;
	int xMax;
	int yMax;
	int begin_xMainMenu;
};
