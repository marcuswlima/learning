#include "Intervalo.h"

#ifndef TRIADE_H
#define TRIADE_H
class Triade{
private:
	Intervalo i1;
	Intervalo i2;
	void setInt1(Intervalo);
	void setInt2(Intervalo);
public:
// Constructors
	Triade();
	Triade(int);
	Triade(Nota,int);
	Triade(Intervalo, Intervalo);
// Sets
	void setTriade(Intervalo, Intervalo);
	void setTriade(Nota, int);
//Gets
	Intervalo getInt1();
	Intervalo getInt2();
	Nota getFundamental();
	Nota getTerca();
	Nota getQuinta();
// Padrao
	void Randomizar(int dificuldade=1);
	string GerarDescricao();
	void ImprimirEmTela();
// Implementações
	void ImprimirFundamentalEmTela();
	string RandomizarTipoTriade();
	string DeduzirTipoTriade();
	void ImprimirTipoTriadeEmTela();
};
#endif
