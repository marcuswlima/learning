#include "Nota.h"

class Intervalo {
private:
    Nota n1;
    Nota n2;
public:
// Constructors
    Intervalo();
    Intervalo(Nota);
    Intervalo(Nota,Nota);
// Sets
    void setN1(Nota);
    void setN2(Nota, int=1);
    void setN2(string, int=1);
    void SetIntervalo(Nota,Nota,int=1);
// Gets
    Nota getN1();
    Nota getN2();
// Padrão
    void Randomizar();
    void Randomizar(int);
    string GerarDescricao();
    void ImprimirEmTela();
// Implementações
    void RandomizarSegundaNota();
    string RandomizaOrientacao();
    string RandomizarDescricao();
    void CalcularQdtNotas();
    void CalcularSemiTons();
    void CalcularOrientacao();
};
