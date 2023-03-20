#include <iostream>
#include <cmath>
using namespace std;

#include "Tecla.h"

class Intervalo
{
public:
    Intervalo();
    Intervalo(Tecla);
    Intervalo(int, int, int);
    void setT1(Tecla);
    Tecla getT1();
    void setT2(Tecla);
    Tecla getT2();
    void setNumero(int);
    int getNumero();
    void setQualidade(char);
    char getQualidade();
    void EncontrarQualificacao(Tecla);      // em função da segunda nota
    void EncontrarSegundaNota(int, char);   // em funçaõ da qualificação
    string GerarDescricao();
    void Imprimir();                        // se existir as duas notas;
private:
    Tecla t1;
    Tecla t2;
    int numero; //[2-7]
    char qualidade; //['m','M','J'];
};