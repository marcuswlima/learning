#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "MarcusTools.h"

#include <ctime>

#include <iomanip>
using std::setw; // permite que o programa configure a largura de um campo
using std::setprecision;

class Tempo{
public:
    void setHora(int);
    void setMinuto(int);
    void setSegundo(int);
    int getHora();
    int getMinuto();
    int getSegundo();
    void setTempo(int, int, int);
    void apresentar();
private:
    int hora;
    int minuto;
    int segundo;
};

void Tempo::setHora(int x){
    hora = x;
}

void Tempo::setMinuto(int x){
    minuto = x;
}

void Tempo::setSegundo(int x){
    segundo = x;
}

void Tempo::setTempo(int h, int m, int s){
    setHora(h);
    setMinuto(m);
    setSegundo(s);
}

void Tempo::apresentar(){
    cout << setw(2) << getHora()    << ":" 
         << setw(2) << getMinuto()  << ":" 
         << setw(2) << getSegundo() ;
}

int Tempo::getHora(){
    return hora;
}

int Tempo::getMinuto(){
    return minuto;
}

int Tempo::getSegundo(){
    return segundo;
}

int countSecondFromZero2(Tempo h1);
int diferencaEmSegundos2(Tempo h1, Tempo h2);


int main(){

    srand( time(0) );

    Tempo h1, h2;

    cout << "Hora1\t\tcsfz1\tHora2\t\tcsfz2\tDiff" << endl;
    cout << "--------\t-----\t-----\t\t-----\t----" << endl;

    for (int i=1; i<=500; i++){

        h1.setTempo(gerarInteiro(0,11)
                   ,gerarInteiro(0,59)
                   ,gerarInteiro(0,59)
                   );

        h2.setTempo(gerarInteiro(0,11)
                   ,gerarInteiro(0,59)
                   ,gerarInteiro(0,59)
                   );

        h1.apresentar();
        cout << "\t" << countSecondFromZero2(h1);
        cout << "\t" ;
        h2.apresentar();
        cout << "\t" << countSecondFromZero2(h2);
        cout << "\t" << diferencaEmSegundos2(h1,h2);
        cout << endl;
    }
    cout << endl;



    h1.setTempo(0,1,0);
    h2.setTempo(11,59,59);

    h1.apresentar();
    cout << "\t" << countSecondFromZero2(h1);
    cout << "\t" ;
    h2.apresentar();
    cout << "\t" << countSecondFromZero2(h2);
    cout << "\t" << diferencaEmSegundos2(h1,h2);
    cout << endl;

}

int countSecondFromZero2 (Tempo h1){
    return (h1.getHora()*60*60) + 
           (h1.getMinuto()*60)  + 
            h1.getSegundo();
}

int diferencaEmSegundos2(Tempo h1, Tempo h2) {
    return abs(countSecondFromZero2(h1)-
               countSecondFromZero2(h2)
              );
}

