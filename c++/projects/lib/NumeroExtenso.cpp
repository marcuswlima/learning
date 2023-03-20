#include "NumeroExtenso.h"
#include "Mathematics.h"

string ShowNumeroExtensoUnidade(int numero){
	string resposta;
	switch (numero)
	{
		case 0:resposta="zero"	;break;
		case 1:resposta="one"	;break;
		case 2:resposta="two"	;break;
		case 3:resposta="three"	;break;
		case 4:resposta="four"	;break;
		case 5:resposta="five"	;break;
		case 6:resposta="six"	;break;
		case 7:resposta="seven"	;break;
		case 8:resposta="eight"	;break;
		case 9:resposta="nine"	;break;
		default:resposta="Unknown"; break;			
	}
	return resposta;
}

string ShowNumberEnglishPronuciation(int numero){
	int unidade,dezena,centena;
	string resposta;

	unidade = GetRemainder(numero,10);
	numero = numero/10;
	dezena = GetRemainder(numero,10);
	numero = numero/10;
	centena = GetRemainder(numero,10);

	resposta = "";
	//Centena
	if (centena>0)
		resposta = ShowNumeroExtensoUnidade(centena)+" hundread ";

	//Dezena e Unidade
	if (dezena==1){
		switch((dezena*10)+unidade){
			case 10:resposta += "ten";      break;
			case 11:resposta += "eleven";   break;
			case 12:resposta += "twelve";   break;
			case 13:resposta += "thirteen"; break;
			case 14:resposta += "fourteen"; break;
			case 15:resposta += "fifteen";  break;
			case 16:resposta += "sixteen";  break;
			case 17:resposta += "seventeen";break;
			case 18:resposta += "eithteen"; break;
			case 19:resposta += "nineteen"; break;
		}
	}else{
		switch(dezena){
			case 2:resposta += "twenty "; break;
			case 3:resposta += "thirty "; break;
			case 4:resposta += "forty ";  break;
			case 5:resposta += "fifty ";  break;
			case 6:resposta += "sixth ";  break;
			case 7:resposta += "seventy ";break;
			case 8:resposta += "eitghty ";break;
			case 9:resposta += "ninety "; break;
		}

		if (unidade > 0) 
			resposta += ShowNumeroExtensoUnidade(unidade);

	}
	return resposta;
}


