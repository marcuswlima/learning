#include <iostream>
using namespace std;

//Prototipations-------------------------------------------
void umSegundo(int &, int &, int);
int movT(int);
int movH(int);

//Main-----------------------------------------------------
int main(){
	srand( time( 0 ) ); // semeia o gerador de número aleatório
	int SIZE=15, T=1, H=1;

	do {
		umSegundo(T,H,SIZE);
	} while (H<SIZE && T<SIZE);

	if (H==SIZE && T==SIZE)
		cout << "Empatou\n";
	else
		if (H==SIZE)	
			cout << "Hare Ganhou\n";
		else if (T==SIZE)	
			cout << "Tortoise Ganhou\n";
}

void umSegundo(int &T, int &H, int SIZE){
	int aleatorio = 1+(rand() % 10);

	H += movH(aleatorio);
	T += movT(aleatorio);

	if(T<1)T=1;
	if(H<1)H=1;

	if(T>SIZE)T=SIZE;
	if(H>SIZE)H=SIZE;

	cout << aleatorio << '\t'<< T << '\t' << H << '\t';

	for (int i=1;i<=(SIZE);i++){
		if (H==T && i==T)
			cout << '*';
		else if (i==H)
			cout << 'H';
		else if (i==T)
			cout << 'T';
		else
			cout << '_';
	}
	cout << '\n';

}

int movT(int aleatorio){
	if      (aleatorio >= 1 && aleatorio <=  5) return  3;
	else if (aleatorio >= 6 && aleatorio <=  7) return -6;
	else if (aleatorio >= 8 && aleatorio <= 10) return  1;
}

int movH(int aleatorio){
	if      (aleatorio >= 1 && aleatorio <=  2) return   0;
	else if (aleatorio >= 3 && aleatorio <=  4) return   9;
	else if (aleatorio >= 5 && aleatorio <=  5) return -12;
	else if (aleatorio >= 6 && aleatorio <=  8) return   1;
	else if (aleatorio >= 9 && aleatorio <= 10) return  -2;
}

