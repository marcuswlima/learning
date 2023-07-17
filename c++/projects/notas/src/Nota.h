#include "includes.h"
#include "Mathematics.h"

#ifndef NOTA_H
#define NOTA_H
class Nota {
private:
	int oitava;   // 0--8 
	int grau;     // 1--7 
	int acidente; // [-2,0,2] [bb,b,0,#,*]
	int clave;    // [5-sol,4-fa]
	bool EhNota(string nota);	
public:
    string DescNota[7]={"DO","RE",
		                "MI","FA",
						"SOL","LA",
						"SI"};
// Constructors
	Nota(); 
	Nota(int); 
	Nota(int, int, int ); 
// Sets
	void setOitava(int o);
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
// Implementacoes
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
