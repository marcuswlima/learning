#include "Program.h"

Program::Program(){
}

void Program::setWord(int i, int i0, int i1, int i2, int i3){
		this->words[i].setWord2(i0, i1, i2, i3);
}

void Program::print(){
	for (int i=0; i<=10; i++){
		this->words[i].print();
		if (this->words[i].getOperation()==43)
			break;
	}
}

int Program::getValue(int i, int value){
//	return words[i].
	return 0;
}

