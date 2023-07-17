#include <regex>
#include "Nota.h"

#ifndef INTERVALO_H
#define INTERVALO_H
class Intervalo {
private:
    Nota n1;
    Nota n2;
    string DescIntervalo[16]={"1J","2m",
  		                      "2M","3m",
						      "3m","4d",
						      "4J","4A",
						      "5d","5J",
						      "5A","6M",
					  	      "6m","7M",
							  "7m","8J"
	                         };
public:
// Constructors
    Intervalo();
    Intervalo(int);
    Intervalo(Nota,Nota);
// Sets
    void setN1(Nota);
    void setN2(Nota);
    void setN2(string ,int =1);
    void SetIntervalo(Nota,Nota);
// Gets
    Nota getN1();
    Nota getN2();
// Padrão
    void Randomizar(int =1);
    string Descricao();
    void ImprimirEmTela();
// Implementações
    int DeduzirQdtTons();
    int DeduzirQtdSemiTons();
    int DeduzirOrientacao();
    string DeduzirTipoIntervalo();
	string OrientacaoEmString();
    void ImprimirQdtTonsEmTela();
    void ImprimirQtdSemiTonsEmTela();
	void ImprimirOrientacaoEmTela();
    void ImprimirTipoIntervaloEmTela();
	bool strEhIntervalo(string);
};
#endif
