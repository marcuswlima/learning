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
    void setQuantidadeNotas(int);
    int getQuantidadeNotas();
    void setQualidade(char);
    string getQualidade();
    void EncontrarQualificacao(Tecla);      // em função da segunda nota
    void EncontrarSegundaNota(int, string);   // em funçaõ da qualificação
    string GerarDescricao();
    void Imprimir();                        // se existir as duas notas;
private:
    Tecla t1;
    Tecla t2;
    int quantidadeNotas; //[2-7]
    string qualidade; //["3xd","2xd","d","m","M","J","A","2xA","3xA"];
};
