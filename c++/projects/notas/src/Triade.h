#include <iostream>
using std::cout;

#include "Nota.h"

class Triade{
public:
// Constructors
    Triade(Nota);
// Sets&Gets
    void setN1(Nota);
    Nota getN1();
    void setN3(Nota);
    Nota getN3();
    void setN5(Nota);
    Nota getN5();
// Implementações
    void GerarTriade(Nota, string);
    void ImprimirEmTela();
    string GerarDescricao();
private:
    Nota n1;
    Nota n3;
    Nota n5;
    int tipoTriade; //['M','m','A','d']
};
