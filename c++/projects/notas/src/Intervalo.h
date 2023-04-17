#include "Nota.h"

class Intervalo {
private:
    Nota n1;
    Nota n2;
public:
// Constructors
    Intervalo();
    Intervalo(int dificuldade);
    Intervalo(int dificuldade, int orientacao);
    Intervalo(Nota,Nota);
// Sets
    void setN1(Nota nota);
    void setN2(Nota nota,int orientacao=1);
    void setN2(string descIntervalo,int orientacao=1);
    void SetIntervalo(Nota n1,Nota n2,int orientacao=1);
// Gets
    Nota getN1();
    Nota getN2();
// Padrão
    void Randomizar(int dificuldade=1);
    string GerarDescricao();
    void ImprimirEmTela();
// Implementações
    void RandomizarSegundaNota(int);
    string RandomizarDescricao();
    string RandomizaOrientacao();
    int DeduzirQdtNotas();
    int DeduzirQtdSemiTons();
    int DeduzirOrientacao();
    void ImprimirQdtNotasEmTela();
    void ImprimirQtdSemiTonsEmTela();
    void ImprimirOrientacaoEmTela();
};
