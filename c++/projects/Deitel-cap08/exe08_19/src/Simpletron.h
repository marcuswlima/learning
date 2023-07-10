#include "Program.h"

#ifndef SIMPLETRON_H
#define SIMPLETRON_H

class Simpletron{
public:
	Simpletron();
	void memoryDump();
	void setMemory(int,int,int);
	void setMemory(int, int,int,int,int,int);
	Word getWord(int,int);
	void loadProgram(Program);
private:
	Word memory2[10][10] ;
/////
	Word memory[10][10] ;
};

#endif
