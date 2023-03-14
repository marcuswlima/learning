#include <iostream>
using std::cout;
using std::endl;
#include "cap06.h"
#include <iomanip>
using std::setw;

class Ponto{
public :
    void setx(double);
    void sety(double);
    double getx();
    double gety();
    Ponto(double, double);
    void display();
    void plotar();
private:
    double x;
    double y;
};

void Ponto::display(){
    cout<<"("<<getx()<<","<<gety()<< ")";
}

Ponto::Ponto(double x=0,double y=0){
    setx(x);
    sety(y);
}

void Ponto::setx(double p_x){
    x = p_x;
}

void Ponto::sety(double p_y){
    y = p_y;
}

double Ponto::getx(){
    return x;
}

double Ponto::gety(){
    return y;
}

void Ponto::plotar(){
    int maior;
    if ( getx() > gety() )
        maior = getx();
    else 
        maior = gety();

    maior+=2;

    int ipslon = gety();
    int xis = getx();

    for (int y=maior;y>=1;y--){
        cout << setw(2) << y ;
        cout << " ";
        for (int i=1;i<=xis-1;i++)
            cout << "  ";
        if (y==ipslon) cout << "*";

        cout << endl;
    }

    cout << " ";
    for (int x=0;x<=maior;x++)
        cout << x << " ";


    cout << endl;
}

double distancia(Ponto p1, Ponto p2);
void plotar2pontos(Ponto p1, Ponto p2);


int main(){
    Ponto p1,p2;
    double dDistancia;

    for (int i=1;i<=13;i++){
        p1.setx(gerarDouble(1,9));
        p1.sety(gerarDouble(1,10));
        p1.display();
        cout << " ";

        p2.setx(gerarDouble(1,10));
        p2.sety(gerarDouble(1,10));
        //p2.display();
        cout << " ";

        //cout << distancia(p1,p2);

        cout << endl;

        //p1.plotar();

    }

    
    Ponto p3(10,20), p4(3,4);
    plotar2pontos(p3,p4);

    return 0;
}

double distancia(Ponto p1, Ponto p2){
    double cateto1 = abs(p1.getx()-p2.getx()),
           cateto2 = abs(p1.gety()-p2.gety());

    return hypotenuse(cateto1, cateto2);

}

void plotar2pontos(Ponto p1, Ponto p2){
    int maior=p1.getx();

    if (p1.gety() > maior)
        maior = p1.gety();
    else if (p2.getx() > maior)
        maior = p2.getx();
    else if (p2.gety() > maior)
        maior = p2.gety();

    maior =+ 2;

    for (int y=maior;y>=0;y--){
        cout << y << endl;
    }
}