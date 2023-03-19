#include "SystemNumeral.h" //cabecalho
#include "Mathematics.h"
//#include "PrintArray.h" //para debug


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


long ConvertBinaryToDecimal(string binario){
	long resposta,numero;

	long restos[50];
	int base=10,qtdElements=0;
	numero = stol(binario); // transformação de string para longInt
	for (int i=0; numero>0; i++){
		restos[i]=GetRemainder(numero,base);
		numero /= base;
		qtdElements++;
	}

	resposta=0;
	for (int i=0;i<qtdElements; i++){
		resposta += restos[i]*CalcPower(2,i); 
	}
	return resposta;
}


string ConvertDecimalTo(long numero,int base){
	int i;
	string restos[15];  
	string resposta="";

	for(i=0; numero>0; i++)      
	{      
		//cout << "numero "<< numero << endl;
		//cout << "base "<< base << endl;
		restos[i]=to_string(GetRemainder(numero,base));
		//cout << "restos[i] "<< restos[i] << endl;


		//cout << restos[i];
		if (base==16){
			if      (restos[i]=="10") restos[i]="A";
			else if (restos[i]=="11") restos[i]="B";
			else if (restos[i]=="12") restos[i]="C";
			else if (restos[i]=="13") restos[i]="D";
			else if (restos[i]=="14") restos[i]="E";
			else if (restos[i]=="15") restos[i]="F";
			else if (restos[i]=="16") restos[i]="0";
		}
		numero /= base;    
	}      

	for(i=i-1 ;i>=0 ;i--)      
		resposta += restos[i];

	return resposta;

}
string ConvertDecimalToHexadecimal(int numero){
	return ConvertDecimalTo(numero,16);
}

string ConvertDecimalToBinary(int numero){
	return ConvertDecimalTo(numero,2);
}

