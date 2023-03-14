#include "Tecla.h"

class Triade{
public:
    Triade(Tecla);
    void setT1(Tecla);
    Tecla getT1();
    void setT3(Tecla);
    Tecla getT3();
    void imprimir();
    void gerarMaior();
private:
    Tecla t1;
    Tecla t3;
};
