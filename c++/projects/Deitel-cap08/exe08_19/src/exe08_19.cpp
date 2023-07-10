#include <iostream>
#include <iomanip>
using namespace std;

void dumpMemoria(int const * );
void loadProgram(int * const , int * );

int main(){
	int p1[10]={1007,1008,2007,3008,2109,1109,4300,0   ,0   ,0};
	int p2[10]={1009,1010,2009,3010,4107,1109,4300,1110,4300,0};
	int memory[100];
	loadProgram(p1,memory);
	dumpMemoria(memory);
	loadProgram(p2,memory);
//	dumpMemoria(memory);
}//main

void dumpMemoria(int const * m) {
	int value, resto;

	//titulo
	cout << '\t';
	for (int x=0; x<=9; x++)
		cout << setw(5) << right << x << '\t';
	cout << '\n';

	cout << setw(5) << '0' << '\t';
	for (int x=0; x<=99; x++){
		cout << '+';
		value = m[x];
		if (value>=1000)
			cout <<	m[x];
		else if (value >= 100)
			cout <<	"0" << m[x];
		else if (value >= 10)
			cout <<	"00" << m[x];
		else
			cout <<	"000" << m[x];

		resto = (x % 10);
		if ( resto == 9 ){
			cout << '\n';
			if ((x/10)+1 < 10)
				cout << setw(5) << ((x/10)+1)*10 << '\t';
		}
		else
			cout << '\t';
		
	}
}

void loadProgram(int * const  p, int  * m){
	for (int x=0; x<=99; x++)
		m[x]=0;
	
	for( int i=0; i<=9; i++ )
		m[i] = p[i];
	
}

