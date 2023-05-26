#include "Triade.h"

#ifndef TETRADE_H 
#define TETRADE_H 

class Tetrade : public Triade{
private:
	Intervalo i3;
public:
// Constructors
	Tetrade();
	Tetrade(int =1);
	Tetrade(Nota,int =1);
//sets
	void setInt3(Intervalo);
//gets
	Intervalo getInt3();
// Padrao
	void Randomizar(int =1);
	string GerarDescricao();
	void ImprimirEmTela();
};
#endif
