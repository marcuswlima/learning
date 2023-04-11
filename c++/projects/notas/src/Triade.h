#include "Intervalo.h"

class Triade{
public:
// Constructors
    Triade();
    Triade(Intervalo);
    Triade(Intervalo, Intervalo);
// Sets&Gets
    void setInt1(Intervalo);
    Intervalo getInt1();
    void setInt2(Intervalo);
    Intervalo getInt2();
    Nota getFundamental();
    Nota getTerca();
    Nota getQuinta();
// Implementações
    void ImprimirEmTela();
    void ImprimirFundamentalEmTela();
    string GerarDescricao();
    string RandomizarTipoTriade();
    void RandomizarTriade();
private:
    Intervalo i1;
    Intervalo i2;
};
