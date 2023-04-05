#include "Nota.h"

class Intervalo {
public:
// Constructors
    Intervalo();
    Intervalo(Nota);
    Intervalo(Nota,Nota);
// Sets&Gets
    void setN1(Nota);
    void setN2(Nota);
    void setQtdNotasNaturais(int);
    void setQtdSemiTons(int);
    Nota getN1();
    Nota getN2();
    int  getQtdNotasNaturais();
    int  GetQtdSemiTons();
// Implementações
    void SetIntervalo(Nota,Nota);
    void CalcularSegundaNota(string);
    void CalcularSegundaNota();
    void CalcularAtributosSecundarios();
    void RandomizarSegundaNota();
    string RandomizarDescricao();
    string GerarDescricao();
    void ImprimirEmTela();
private:
    Nota n1;
    Nota n2;
    int qtdNotasNaturais; //[2-7]
    int qtdSemiTons;     //[2-12]
    int orientacao; //[-1 desc, 1 asc]
};
