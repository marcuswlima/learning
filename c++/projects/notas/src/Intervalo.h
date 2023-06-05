#include "Nota.h"

#ifndef INTERVALO_H
#define INTERVALO_H
class Intervalo {
private:
    Nota n1;
    Nota n2;
    int orientacao;
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
};
#endif
