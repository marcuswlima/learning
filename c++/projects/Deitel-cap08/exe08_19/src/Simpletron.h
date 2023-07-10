#include "Program.h"

#ifndef SIMPLETRON_H
#define SIMPLETRON_H

class Simpletron{
public:
	Simpletron();
	void memoryDump();
	void setMemory(int,int,int);
	void setMemory(int,int,int,int,int);
	Word getWord(int,int);
private:
	Word memory2[100] ;
/////
	Word memory[10][10] ;
};

#endif
