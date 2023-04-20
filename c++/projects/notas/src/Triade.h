#include "Intervalo.h"

#ifndef TRIADE_H
#define TRIADE_H
class Triade{
private:
    Intervalo i1;
    Intervalo i2;
public:
// Constructors
    Triade();
    Triade(Intervalo);
    Triade(Intervalo, Intervalo);
// Sets
    void setInt1(Intervalo);
    void setInt2(Intervalo);
    void setTriade(Intervalo, Intervalo);
//Gets
    Intervalo getInt1();
    Intervalo getInt2();
    Nota getFundamental();
    Nota getTerca();
    Nota getQuinta();
// Padrao
    void Randomizar(int dificuldade=1);
    string GerarDescricao();
    void ImprimirEmTela();
// Implementações
    void ImprimirFundamentalEmTela();
    string RandomizarTipoTriade();
};
#endif
