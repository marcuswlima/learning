#include "Nota.h"

class Intervalo {
public:
// Constructors
    Intervalo();
    Intervalo(Nota);
    Intervalo(Nota,Nota);
// Sets&Gets
    void setN1(Nota);
    Nota getN1();
    void setN2(Nota);
    Nota getN2();
    void SetIntervalo(Nota,Nota);
    void setQtdNotasNaturais(int);
    int  getQtdNotasNaturais();
    void setQtdSemiTons(int);
    int  GetQtdSemiTons();
    void setDescIntervalo(string);
    string getDescIntervalo();
// Implementações
    void CalcularSegundaNota(string); // em função da descricao
    string CalcularDescricaoIntervalo(Nota);     // em função da segunda nota
    string RandomizarDescricao();
    void RandomizarIntervaloSimples();
    string GerarDescricao();
    void ImprimirEmTela();
private:
    Nota n1;
    Nota n2;
    int qtdNotasNaturais; //[2-7]
    int qtdSemiTons;     //[2-12]
    string descIntervalo; 
    int orientacao; //[-1 desc, 1 asc]
};
