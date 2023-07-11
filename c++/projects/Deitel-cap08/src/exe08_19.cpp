#include <iostream>
#include <iomanip>
using namespace std;

//Protpripations------------------------
void receberPrograma(int * const);
void loadProgram(const int * const , int * const );
void run(int * const);
void dumpMemoria(const int * const );
bool comandoValido(int const);

//Globais--------------------------------------
int registers[100][5];
int gflagFim=-99999;

//main--------------------------------------
int main(){
	cout << "**************************************************************\n";
	cout << "*** Bem vindo ao Simpletron!                               ***\n";
	cout << "*** Por favor insira uma instrução                         ***\n";
	cout << "*** (ou data word) por vez em seu programa. Eu vou digitar ***\n";
	cout << "*** o número de alocação e o ponto de interrogação (?).    ***\n";
	cout << "*** Então você digita a palavra para a alocação.           ***\n";
	cout << "*** Digite o número -99999 para parar de inserir dados     ***\n";
	cout << "*** no seu programa.                                       ***\n";
	cout << "**************************************************************\n";
	cout << '\n'; 

	int p[100];
	int memory[100];

	receberPrograma(p);
	loadProgram(p,memory);
	run(memory);
	dumpMemoria(memory);
}//main

void receberPrograma(int * const p){
	int cont=0, digitado=0;
	do{ 
		do{
			cout << setfill('0') << setw(2) << cont << " ? ";
			cin >> digitado;
		}while (!comandoValido(digitado));
		p[cont] = digitado;
		cont++;
	}while (digitado != gflagFim);
}//receberPrograma

void dumpMemoria(const int * const m) {

	//titulo
	for (int x=0; x<=9; x++)
		cout << x << right << '\t';
	cout << '\n';

	for (int x=0; x<=99; x++){
		cout << '+';
		cout <<	setw(4) << setfill('0') << m[x];
		cout << (x % 10 == 9 ? '\n' : '\t');
	}
	cout << '\n'; 

	cout << "Registers:\n";
	int i=0;
	while (registers[i][0] != gflagFim){
		cout << registers[i][0] << '\t' 
			 << registers[i][1] << '\t'
			 << registers[i][2] << '\t'
			 << registers[i][3] << '\t'
			 << registers[i][4] << '\t'
			 ;
		cout << '\n';
		i++;
	}
}//dumpMemoria

void loadProgram(const int * const p, int * const m){
	int i=0;
	
	for (int x=0; x<=99; x++)
		m[x]=0;
	
	while (p[i] != gflagFim){
		m[i] = p[i];
		i++;
	}
	for (int y=0; (m[i] = p[i]) != gflagFim; i++)
		; 
}//loadProgram

void run(int * const m){
	int instrRegister, operationCode, operand, accumulator=0, instrCount=0, ate=10;
	do{

		instrRegister = m[instrCount];
		operationCode = instrRegister/100;
		operand = instrRegister % 100;

		registers[instrCount][0]=instrCount;
		registers[instrCount][1]=instrRegister;
		registers[instrCount][2]=operationCode;
		registers[instrCount][3]=operand;
		
		if (operationCode==43)
			break;

		switch (operationCode){
			case 10:
				cout << "Digite um número: ";
				cin >> m[operand];
				break;
			case 11:
				cout << "Resultado: " << m[operand] << '\n';
				break;
			case 20:
				accumulator = m[operand];
				break;
			case 21:
				m[operand] = accumulator;
				break;
			case 30:
				accumulator += m[operand];
				break;
			case 31:
				accumulator -= m[operand];
				break;
			case 32:
				accumulator /= m[operand];
				break;
			case 33:
				accumulator *= m[operand];
				break;
		}

		if (operationCode < 40)
			instrCount++;
		else{
			int unidade = operationCode % 10;

			if (unidade==0)
				instrCount = operand;
			else if (unidade == 1 && accumulator < 0)
				instrCount = operand;
			else if (unidade == 2 && accumulator == 0)
				instrCount = operand;
			else 
				instrCount++;
		}

		registers[instrCount][4]=accumulator;
		
	}while (instrCount<=ate);


	registers[instrCount][0]=gflagFim;

}//run

bool comandoValido(int const c){
	return  ((c/100) <= 4 ? true : false);
}

