#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
using namespace std;

#ifndef TIME_H
#define TIME_H
class Nota {
public:
// Constructors
    Nota(); 
    Nota(int, int, int ); 
// Sets&Gets
    void setOitava(int);
    void setGrau(int);
    void setAcidente(int);
    int getOitava();
    int getGrau();
    int getAcidente();
// Implementações
    void setNota( int, int, int ); 
    void Aleatorio();
    Nota qualRelativa(int);
    string GerarDescricao();
    void ImprimirEmTela();
private:
    int oitava;     // 0--8 
    int grau;       // 1--7 
    int acidente;   // [-2,0,2] [bb,b,0,#,*]
}; 
#endif
