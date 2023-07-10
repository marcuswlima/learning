#include <iostream>
#include <iomanip>

using namespace std;

#include "Simpletron.h"


string pad_left(string const&, size_t );

Simpletron::Simpletron(){
	//zerar memoria
	for (int i=0; i<=99; i++)
		this->setMemory(i,0,0,0,0);
}//contructor

void Simpletron::memoryDump(){
	string sValor;
	//titulo
	cout << '\t';
	for (int x=0; x<=9; x++)
		cout << setw(5) << right << x << '\t';
	cout << '\n';

	//enderecos
	for (int i=0; i<=99; i++) {
		cout << i << "->";
		this->memory2[i].print();
		cout << ( (i % 9 == 0)&&(i!=0) ? '\n' : '\t' );
	}

	cout << '\n';

}//memoryDump

void Simpletron::setMemory(int i, int i0, int i1, int i2, int i3){
	this->memory2[i].setWord2(i0, i1, i2, i3);
}//setMemory

void Simpletron::setMemory(int x, int y, int value){
	this->memory[x][y].setValor(value);
}//setMemory

Word Simpletron::getWord(int x, int y){
	return this->memory[x][y];
}//getWord
 

string pad_left(string const& str, size_t s)
{
    if ( str.size() < s )
        return std::string(s-str.size(), '0') + str;
    else
        return str;
}

