#include "SystemNumeral.h"
#include "Mathematics.h"

//#include "PrintArray.h" //para debug

#include <iostream>

int ConvertHexaToDecimal(string hexadecimal){
	int resposta=0,numero=0,tamanhoHexa=hexadecimal.length();
	char letras[tamanhoHexa];
	string str_numero;

	//inverter
	for (int i=0; i<=tamanhoHexa-1; i++){
		letras[tamanhoHexa-1-i]=hexadecimal[i];
	}


	for (int i=0; i<=tamanhoHexa-1;i++){
			if      (letras[i]=='A') numero=10;
			else if (letras[i]=='B') numero=11;
			else if (letras[i]=='C') numero=12;
			else if (letras[i]=='D') numero=13;
			else if (letras[i]=='E') numero=14;
			else if (letras[i]=='F') numero=15;
			else {
				str_numero = letras[i];
				numero=stoi(str_numero); //tranformat char->int
			}

			resposta += numero*CalcPower(16,i);
	}

	return resposta;
}


