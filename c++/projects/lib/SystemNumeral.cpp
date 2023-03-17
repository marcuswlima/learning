#include "SystemNumeral.h"
#include "Mathematics.h"

#include <iostream>

int ConvertHexaToDecimal(string hexa){
	int resposta=0,numero,tamanhoHexa=hexa.length();
	cout << tamanhoHexa << endl;
	string letras[tamanhoHexa];

	//inverter
	for (int i=0; i<= (hexa.length()-1); i++){
		letras[hexa.length()-1-i]=hexa[i];
	}

	for (int i; i<=tamanhoHexa-1;i++){
			numero=0;
			if      (letras[i]=="A") numero=10;
			else if (letras[i]=="B") numero=11;
			else if (letras[i]=="C") numero=12;
			else if (letras[i]=="D") numero=13;
			else if (letras[i]=="E") numero=14;
			else if (letras[i]=="E") numero=15;
			else numero=std::stoi(letras[i]);

			resposta += numero*CalcPower(16,i);
	}

	return resposta;
}


