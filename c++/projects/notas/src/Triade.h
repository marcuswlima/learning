#include "Intervalo.h"

class Triade{
public:
// Constructors
    Triade();
    Triade(Intervalo);
// Sets&Gets
    void setInt1(Intervalo);
    Intervalo getInt1();
    void setInt2(Intervalo);
    Intervalo getInt2();
    void setTipoTriade(char);
    char getTipoTriade();
    void setN1(Nota);
    Nota getN1();
    void setN3(Nota);
    Nota getN3();
// Implementações
    void ImprimirEmTela();
    string GerarDescricao();
    string RandomizarTipoTriade();
    void RandomizarTriade();
private:
    Intervalo i1;
    Intervalo i2;
    char tipoTriade; //['M','m','A','d']
};
