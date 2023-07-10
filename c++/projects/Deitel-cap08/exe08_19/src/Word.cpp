#include "Word.h"


Word::Word(){
}// Word constructor

Word::Word(int i0, int i1, int i2, int i3){
	this->setWord2(i0, i1, i2, i3);
}//construtor(int)

void Word::setWord2(int i0, int i1, int i2, int i3){
	this->word2[0]=i0;
	this->word2[1]=i1;
	this->word2[2]=i2;
	this->word2[3]=i3;
}//construtor(int)

int Word::getOperation(){
	return (this->word2[0]*10)+this->word2[1];
}

int Word::getOperand(){
	return (this->word2[2]*10)+this->word2[3];
}
void Word::print(){
	cout << '+'
		<< this->word2[0] 
		<< this->word2[1]
		<< this->word2[2]
		<< this->word2[3]
		;
}

//------------------------------------
Word::Word(char * p){
	this->word[0]=p[0];
	this->word[1]=p[1];
	this->word[2]=p[2];
	this->word[3]=p[4];
}//construtor(int)

Word::Word(int p){
	this->setValor(p);
}//construtor(int)

void Word::setValor(int p){
	this->valor = p;
}//setValue

int Word::getValor(){
	return this->valor;
}//getValor

void Word::setValor(char * p){
	this->operatorW[0] = p[0];
	this->operatorW[1] = p[1];
	this->operandW[0] = p[2];
	this->operandW[1] = p[3];
}//setValue



