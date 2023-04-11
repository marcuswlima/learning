#include "../../lib/Mathematics.h"
#include "../../lib/BarraTitulo.h"
#include "../../lib/ObterNumero.h"

#ifndef TIME_H
#define TIME_H
class Nota {
public:
// Constructors
    Nota(); 
    Nota(int, int, int ); 
// Sets
    void setOitava(int);
    void setGrau(int);
    void setAcidente(int);
//Gets
    int getOitava();
    int getGrau();
    int getAcidente();
// Padrão
    void Randomizar();
    string GerarDescricao();
    void ImprimirEmTela();
// Implementações
    void setNota( int, int, int ); 
    Nota qualRelativa(int);
private:
    int oitava;     // 0--8 
    int grau;       // 1--7 
    int acidente;   // [-2,0,2] [bb,b,0,#,*]
}; 
#endif
