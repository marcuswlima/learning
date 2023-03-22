#include <iostream>
using std::cout;

#include "Tecla.h"

class Triade{
public:
    Triade(Tecla);
    void setT1(Tecla);
    Tecla getT1();
    void setT3(Tecla);
    Tecla getT3();
    void setT5(Tecla);
    Tecla getT5();

    
    void ImprimirEmTela();
    string GerarDescricao();
private:
    Tecla t1;
    Tecla t3;
    Tecla t5;
};
