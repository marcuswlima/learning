#include <iostream>

using std::cout;
using std::endl;

#include "Tecla.h"
#include "../../lib/cplusplus/BarraTitulo.h"

void copiaTecla(Tecla,Tecla &);
Tecla i2m(Tecla);
Tecla i2M(Tecla);
Tecla i3m(Tecla);
Tecla i3M(Tecla);
Tecla i4J(Tecla);

/////////////////////////////////////////
// Main
/////////////////////////////////////////
int main ( )
{
    srand( time(0) );

    ImprimirTitulo("Nota Musicais");

    Tecla t1(3,1,0), t2;
    t1.imprimirTecla();
    t2 = i2m(t1);
    t2.imprimirTecla();
    t2 = i2M(t1);
    t2.imprimirTecla();
    t2 = i3m(t1);
    t2.imprimirTecla();
    t2 = i3M(t1);
    t2.imprimirTecla();
    t2 = i4J(t1);
    t2.imprimirTecla();
	cout << endl;

    return 0; //indica o fim do programa
}

Tecla i2m(Tecla t){
    Tecla temp;
    int deslocamentoTecla=1,deslocamentoSemitom=1,distanciaDeNotas=2;
    copiaTecla(t,temp);

    temp.setNota(temp.getNota()+deslocamentoTecla);
    temp.setAcidente(deslocamentoSemitom-distanciaDeNotas);
    return temp;
}

Tecla i2M(Tecla t){
    Tecla temp;
    int deslocamentoTecla=1,deslocamentoSemitom=2,distanciaDeNotas=2;
    copiaTecla(t,temp);

    temp.setNota(temp.getNota()+deslocamentoTecla);
    temp.setAcidente(deslocamentoSemitom-distanciaDeNotas);
    return temp;
}

Tecla i3m(Tecla t){
    Tecla temp;
    int deslocamentoTecla=2,deslocamentoSemitom=3,distanciaDeNotas=4;
    copiaTecla(t,temp);

    temp.setNota(temp.getNota()+deslocamentoTecla);
    temp.setAcidente(deslocamentoSemitom-distanciaDeNotas);
    return temp;
}

Tecla i3M(Tecla t){
    Tecla temp;
    int deslocamentoTecla=2,deslocamentoSemitom=4,distanciaDeNotas=4;
    copiaTecla(t,temp);

    temp.setNota(temp.getNota()+deslocamentoTecla);
    temp.setAcidente(deslocamentoSemitom-distanciaDeNotas);
    return temp;
}

Tecla i4J(Tecla t){
    Tecla temp;
    int deslocamentoTecla=3,deslocamentoSemitom=5,distanciaDeNotas=5;
    copiaTecla(t,temp);

    temp.setNota(temp.getNota()+deslocamentoTecla);
    temp.setAcidente(deslocamentoSemitom-distanciaDeNotas);
    return temp;
}

void copiaTecla(Tecla t1,Tecla &t2){
    t2.setTecla(t1.getOitava(), t1.getNota(), t1.getAcidente());
}


