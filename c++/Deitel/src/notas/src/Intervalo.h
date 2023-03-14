#include "Tecla.h"

class Intervalo
{
public:
    Intervalo();
    Intervalo(Tecla);
    Intervalo(Tecla,Tecla);
    Intervalo(int , int , int , int , int , int );
    void setT1(Tecla);
    void setT2(Tecla);
    void setQuantNotas(int);
    void setQuantSemiTons(int);
    Tecla getT1();
    Tecla getT2();
    int getQuantNotas();
    int getQuantSemiTons();
    void imprimirIntervalo();
    void aleatorio();
private:
    Tecla t1;
    Tecla t2;
    int quantNotas;
    int quantSemiTons;
};