#include "Nota.h"

class Intervalo {
public:
// Constructors
    Intervalo();
    Intervalo(Nota);
    Intervalo(Nota,Nota);
// Sets
    void setN1(Nota);
    void setN2(Nota);
    void setN2(string);
    void setN2();
    void setQtdNotasNaturais(int);
    void setQtdSemiTons(int);
// Gets
    Nota getN1();
    Nota getN2();
    int  getQtdNotasNaturais();
    int  GetQtdSemiTons();
// Implementações
    void SetIntervalo(Nota,Nota);
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
