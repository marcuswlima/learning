#include <string>
using namespace std;

#ifndef TIME_H
#define TIME_H
// Time class definition
class Tecla
{
public:
    Tecla(); // constructor
    Tecla(int, int, int ); // constructor
    void setTecla( int, int, int ); 
    void setOitava(int);
    void setNota(int);
    void setAcidente(int);
    int getOitava();
    int getNota();
    int getAcidente();
    string GerarDescricao();
    void Imprimir();
    void Aleatorio();
private:
    int oitava;     // 0--8     / oitavas de um pianao
    int nota;       // 1--7     / do,re,mi,fa,sol,la,si,
    int acidente;   // [-1,0,1] / bemol, sim acidente, sustenido
}; // end class Time
#endif