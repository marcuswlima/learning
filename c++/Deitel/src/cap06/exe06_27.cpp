#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include "cap06.h"

#include <iomanip>
using std::setprecision;
using std::setiosflags;
using std::setw;
using std::string;

double celsius(double fahrenheit);
double fahrenheit(double celsius);
void imprimeBarra(int quantidade);

int main () {

    srand( time(0) );

    double temperatura;

    cout << "Aleatório[-50,50]|EmCelsius|EmFahrenheit" << endl;

    for (int i=0;i<=20;i++){
        temperatura = gerarDouble(-50,50);

        cout << setiosflags(ios::fixed | ios::showpoint) ; 
        cout << setw(10) << setprecision(2) <<  temperatura             << " | ";
        cout << setw(10) << setprecision(4) <<  celsius(temperatura)    << " | ";
        cout << setw(10) << setprecision(4) <<  fahrenheit(temperatura) << " | ";
        cout << endl;
    }

    for (int i=-17;i<=38;i++){
        cout << setiosflags(ios::fixed | ios::showpoint) ; 
        cout << setw(3) << setprecision(2) <<  i             << " | ";
        cout << setw(8) << setprecision(4) <<  fahrenheit(i) << " | ";
        imprimeBarra(fahrenheit(i));
        cout << endl;
    }

    for (int i=32;i<=212;i++){
        cout << setiosflags(ios::fixed | ios::showpoint) ; 
        cout << setw(3) << setprecision(2) <<  i             << " | ";
        cout << setw(8) << setprecision(4) <<  celsius(i) << " | ";
        imprimeBarra(celsius(i));
        cout << endl;
    }

    for (int i=-50; i<=50; i++) {
        cout << i << endl;
        //cout << celsius(i) << " " << fahrenheit(i) << endl;
        cout << "C: ";
        imprimeBarra(celsius(i));
        cout << endl;
        cout << "F: ";
        imprimeBarra(fahrenheit(i));
        cout << endl;
    }

    return 0;

}

double celsius(double fahrenheit){
    // C = ( F - 32 ) X 5 / 9 
    return (fahrenheit - 32) * 5 / 9 ;
}

double fahrenheit(double celsius){
    // F = ( C x 9 / 5 ) + 32
    return ( celsius * 9 / 5 ) + 32 ;
}

void imprimeBarra(int quantidade){
    string caracter;

    if (quantidade == 0)
        caracter = "-";
    else
        if (quantidade > 0)
            caracter = "+";
        else
            caracter = "-";

    for (int i=1;i<=abs(quantidade);i++){
        cout << caracter;
    }
}