#include "Cliente.h"

class Atendente{
public:
    static const int sizeAssentos=11;

    Atendente();
    void emitirBilhete(Cliente);
    void atender(Cliente);
    int obterUmaVaga(int);
    void setAssentoVendido(int);
    int getAssentoVendido();
    void mostrarAssentos();
    bool haVagas();
private:    
    int assentos[sizeAssentos];
    int assentoVendido;
    bool estaOcupado(int);
    void queimarAssento(int);
};
