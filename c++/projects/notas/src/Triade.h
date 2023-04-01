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
    void setTipoTriade(char);
    char getTipoTriade();
// Implementações
    void ImprimirEmTela();
    void ImprimirFundamentalEmTela();
    string GerarDescricao();
    string RandomizarTipoTriade();
    void RandomizarTriade();
private:
    Intervalo i1;
    Intervalo i2;
    char tipoTriade; //['M','m','A','d']
};
