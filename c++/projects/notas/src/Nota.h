#include "../../lib/Mathematics.h"
#include "../../lib/BarraTitulo.h"
#include "../../lib/ObterNumero.h"

#ifndef NOTA_H
#define NOTA_H
class Nota {
private:
    int oitava;     // 0--8 
    int grau;       // 1--7 
    int acidente;   // [-2,0,2] [bb,b,0,#,*]
public:
// Constructors
    Nota(); 
    Nota(int); 
    Nota(int, int, int ); 
// Sets
    void setOitava(int);
    void setGrau(int);
    void setAcidente(int);
    void setNota(int, int, int); 
//Gets
    int getOitava();
    int getGrau();
    int getAcidente();
// Padrão
    void Randomizar(int in_dificuldade=1);
    string GerarDescricao();
    void ImprimirEmTela();
// Implementações
    Nota qualRelativa(int, int =1);
    void up1SemiTom();
    void up1Tom();
    void down1SemiTom();
    void down1Tom();
}; 
#endif
