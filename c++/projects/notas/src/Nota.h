#include "../../lib/Mathematics.h"
#include "../../lib/BarraTitulo.h"
#include "../../lib/ObterNumero.h"

#ifndef TIME_H
#define TIME_H
class Nota {
private:
    int oitava;     // 0--8 
    int grau;       // 1--7 
    int acidente;   // [-2,0,2] [bb,b,0,#,*]
public:
// Constructors
    Nota(); 
    Nota(int, int, int ); 
// Sets
    void setOitava(int);
    void setGrau(int);
    void setAcidente(int);
    void setNota( int, int, int ); 
//Gets
    int getOitava();
    int getGrau();
    int getAcidente();
// Padrão
    void Randomizar();
    string GerarDescricao();
    void ImprimirEmTela();
// Implementações
    Nota qualRelativa(int);
    bool ehMaior(Nota n1, Nota n2);
}; 
#endif
