#include <iostream>

#ifndef EXEMPLO_H
#define EXEMPLO_H

class Exemplo{
public:

	typedef std::string STR;

	Exemplo();
	Exemplo( int , int *);
	~Exemplo();
	void lista_array( STR [] );	
	STR mostra(STR);
private:
	const double pi = 3.14;
protected:
	STR senha={"MinhaSenhaSecreta"};
};

#endif
