#include <iostream>
using namespace std;

#ifndef WORD_H
#define WORD_H

class Word{
public:
	Word();
	void setWord2(int,int,int,int);
	void print();
	int getOperation();
	int getOperand();
///	
	Word(int);
	Word(int,int,int,int);
	Word(char *);
	void setValor(int);
	int getValor();
	char* getValor(int);
	void setValor(char * p);
private:
	int word2[4];
//////
	int valor;
	char operatorW[2];
	char operandW[2];
	char word[4];
};

#endif
