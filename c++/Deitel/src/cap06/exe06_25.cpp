#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;

#include <cmath>

using std::ios;

#include "cap06.h"

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()

int quociente(int a, int b);
int resto(int a, int b);
void separar(int inteiro);

int main()
{
    int inteiro;

    srand( time(0) );


    inteiro = gerarInteiro(1,32767);
    inteiro = 12045;
    string asda;

    separar(inteiro);




//--------------------------------------------
    cout << endl << endl ;
    return 0;
}


int quociente(int a, int b){
    return a / b;
}

int resto(int a, int b){
    return a % b;
}

void separar(int inteiro ){
    int decimal, resto, isolado;

    cout << "-------" << endl;
    cout << "Entrou " << inteiro << endl;


    if (inteiro > 10000)
        decimal = 10000;
    else
        if (inteiro > 1000)
            decimal = 1000;
        else
            if (inteiro > 100)
                decimal = 100;
            else 
                if (inteiro > 10)
                    decimal = 10;
                else 
                    decimal = 1;

    cout << "decimal " << decimal << endl;

    if (decimal==1)
        cout << inteiro << endl;
    else {
        //cout << quociente (inteiro,decimal) << " ";
        resto = inteiro % decimal ;
        cout << "resto " << resto << endl;
        isolado = (inteiro - resto) / decimal;
        cout << "isolado " << isolado << endl;
        separar(resto);
    }


    cout <<  endl;
}


