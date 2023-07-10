#include "Simpletron.h"

Simpletron::Simpletron(){
	//zerar memoria
	for (int x=0; x<=9; x++)
		for (int y=0; y<=9; y++)
			this->setMemory(x,y,0,0,0,0);
}//contructor

void Simpletron::memoryDump(){
	string sValor;
	//titulo
	cout << '\t';
	for (int x=0; x<=9; x++)
		cout << setw(5) << right << x << '\t';
	cout << '\n';

	//enderecos
	for (int x=0; x<=9; x++){
		cout << setw(2) << x*10 << '\t';
		for (int y=0; y<=9; y++){
			this->memory2[x][y].print();
			cout << '\t';
		}
		cout << '\n';
	}

}//memoryDump

void Simpletron::setMemory(int x, int y, int i0, int i1, int i2, int i3){
	this->memory2[x][y].setWord2(i0, i1, i2, i3);
}//setMemory

void Simpletron::setMemory(int x, int y, int value){
	this->memory[x][y].setValor(value);
}//setMemory

Word Simpletron::getWord(int x, int y){
	return this->memory[x][y];
}//getWord

void Simpletron::loadProgram(Program p){
	//int i0=p.words[i];

//	cout << &p ;

//for (int i=0; i<=10; i++){
//		this->setMemory2(0,i,);
//	}
}
	 
