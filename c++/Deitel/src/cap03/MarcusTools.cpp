#include <string> 
#include "MarcusTools.h" 

int gerarInteiro(int menor, int maior) {

    int faixa  = (maior - menor + 1);
    int gerado = (1 + rand() % faixa);

    return menor + (gerado-1);

}

bool ehPar(int entrada){
    int resto = entrada % 2;

    if (resto == 0)
        return true;
    else
        return false;
}
