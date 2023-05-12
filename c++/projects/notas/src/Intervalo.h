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
    Intervalo(int dificuldade);
    Intervalo(Nota,Nota);
// Sets
    void setN1(Nota nota);
    void setN2(Nota nota);
    void setN2(string descIntervalo,int orientacao=1);
    void SetIntervalo(Nota n1,Nota n2);
// Gets
    Nota getN1();
    Nota getN2();
// Padrão
    void Randomizar(int dificuldade=1);
    string GerarDescricao();
    void ImprimirEmTela();
// Implementações
    int DeduzirQdtNotas();
    int DeduzirQtdSemiTons();
    int DeduzirOrientacao();
    string DeduzirTipoIntervalo();
    void ImprimirQdtNotasEmTela();
    void ImprimirQtdSemiTonsEmTela();
    void ImprimirOrientacaoEmTela();
    void ImprimirTipoIntervaloEmTela();
};
#endif
