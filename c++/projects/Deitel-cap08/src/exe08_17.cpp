#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;

#ifndef CORRIDA_H
#define CORRIDA_H

//Class Corrida-------------------------------------------
class Corrida{
public:
	Corrida(int, int, int);
	void start();
private:
	int size;
	int T;
	int H;
	int qtdSegundos;
	void setSize(int);
	void setH(int);
	void setT(int);
	void setQtdSegundos(int);
	int getSize();
	int getH();
	int getT();
	int getQtdSegundos();
	void umSegundo(int &, int &, const int);
	int movT(const int);
	int movH(const int);
	void incrementarUmSegundo();
};
#endif

Corrida::Corrida(int s, int t, int h){
	this->setSize(s);
	this->setT(t);
	this->setH(h);
	this->setQtdSegundos(1);
}

void Corrida::setSize(int s){
	this->size=s;
}

void Corrida::setT(int t){
	this->T=t;
}

void Corrida::setH(int h){
	this->H=h;
}

void Corrida::setQtdSegundos(int p){
	this->qtdSegundos=p;
}

int Corrida::getSize(){
	return this->size;
}

int Corrida::getT(){
	return this->T;
}

int Corrida::getH(){
	return this->H;
}

int Corrida::getQtdSegundos(){
	return this->H;
}

void Corrida::incrementarUmSegundo(){
	int i=this->getQtdSegundos();
	i++;
	this->setQtdSegundos(i);
}

void Corrida::start(){
	int H=this->getH();
	int T=this->getT();
	int SIZE=this->getSize();

	do {
		this->umSegundo(T,H,SIZE);
	} while (H<SIZE && T<SIZE);

	if (H==SIZE && T==SIZE)
		cout << "Empatou\n";
	else
		if (H==SIZE)	
			cout << "Hare Ganhou\n";
		else if (T==SIZE)	
			cout << "Tortoise Ganhou\n";
}//start

void Corrida::umSegundo(int &T, int &H, const int SIZE){
	int aleatorio = 1+(rand() % 10);

	H += this->movH(aleatorio);
	T += this->movT(aleatorio);

	if ( T < 1 ) T=1;
	if ( H < 1 ) H=1;

	if ( T > SIZE ) T=SIZE;
	if ( H > SIZE ) H=SIZE;

	cout 
		 //<< setw(4) << aleatorio
		 //<< setw(4) << T
		 //<< setw(4) << H
		 << setw(4) << this->getQtdSegundos()
		 << ' ';

	for (int i=1; i<=(SIZE); i++){

		if (H==T && i==T)
			cout << '*';
		else if (i==H)
			cout << 'H';
		else if (i==T)
			cout << 'T';
		else
			cout << ' ';
	}
	cout << '\n';
	this->incrementarUmSegundo();
	usleep(70000);

}//umSegundo

int Corrida::movT(const int aleatorio){
	if      (aleatorio >= 1 && aleatorio <=  5) return  3;
	else if (aleatorio >= 6 && aleatorio <=  7) return -6;
	else if (aleatorio >= 8 && aleatorio <= 10) return  1;
}//movT

int Corrida::movH(const int aleatorio){
	if      (aleatorio >= 1 && aleatorio <=  2) return   0;
	else if (aleatorio >= 3 && aleatorio <=  4) return   9;
	else if (aleatorio >= 5 && aleatorio <=  5) return -12;
	else if (aleatorio >= 6 && aleatorio <=  8) return   1;
	else if (aleatorio >= 9 && aleatorio <= 10) return  -2;
}//movH

//Main-----------------------------------------------------
int main(){
	srand( time( 0 ) ); // semeia o gerador de número aleatório
	int SIZE=17, T=10, H=1;
	Corrida c(SIZE,T,H);
	c.start();

	return 0;
}//main




