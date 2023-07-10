#include <iostream>
using namespace std;

#include "Simpletron.h"

void testarProgram();
void testarMemoria();

int main(){
	testarProgram();
	testarMemoria();
}//main

void testarProgram(){
	Program p;
	p.setWord(0,1,0,0,7);
	p.setWord(1,1,0,0,8);
	p.setWord(2,2,0,0,7);
	p.setWord(3,3,0,0,8);
	p.setWord(4,2,1,0,9);
	p.setWord(5,1,1,0,9);
	p.setWord(6,4,3,0,0);
	p.print();
	cout << '\n';

}

void testarMemoria(){
	Simpletron s;
//	s.setMemory(0,0,1001);
//	s.setMemory(0,1,100);
//	s.setMemory(3,4,123);
//	s.setMemory(8,8,1008);
	s.memoryDump();
}


