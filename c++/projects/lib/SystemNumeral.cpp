#include "SystemNumeral.h"
#include "Mathematics.h"
#include "PrintArray.h"

#include <iostream>

int ConvertHexaToDecimal(string hexadecimal){
	int resposta=0,numero,tamanhoHexa=hexadecimal.length();
	char letras[tamanhoHexa];

	for (int i=tamanhoHexa-1; i>=0; i--){
		cout << i << "\t" << hexadecimal[i] << endl;
	}



	PrintVector(letras,11,"Letras");
/*

	cout << hexa[0] << endl;
	cout << hexa[1] << endl;
	cout << hexa[2] << endl;
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
*/
	return tamanhoHexa;
}


