#include "../../lib/Mathematics.h"
#include "../../lib/BarraTitulo.h"
#include "../../lib/ObterNumero.h"

#ifndef NOTA_H
#define NOTA_H
class Nota {
private:
	int oitava;   // 0--8 
	int grau;     // 1--7 
	int acidente; // [-2,0,2] [bb,b,0,#,*]
	int clave;    // [5-sol,4-fa]
public:
// Constructors
	Nota(); 
	Nota(int); 
	Nota(int, int, int ); 
// Sets
	void setOitava(int);
	void setGrau(int);
	void setAcidente(int);
	void setNota(int, int, int);
	void setNota(string);
//Gets
	int getOitava();
	int getGrau();
	int getAcidente();
	int getId();
// Padrão
	void Randomizar(int =1);
	string Descricao();
	void ImprimirEmTela();
// Implementações
	Nota qualRelativa(int, int =1);
	void up1SemiTom();
	void up1Tom();
	void down1SemiTom();
	void down1Tom();
	static bool strEhNota(string);
// Operacoes
	bool operator==(Nota const&);
	bool operator>(Nota const&);
	bool operator<(Nota const&);
}; 
#endif
