#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>


int main()
{
  
    double raio, diametro, circunferencia, area, pi=3.14159;
    cout << "Qual o raio do círculo ? ";
    cin >> raio ; 
    cout << endl;

    diametro       = raio * 2; 
    circunferencia = pi * diametro;
    area           = pow(raio,2) * pi;

    cout << "O diâmetro do círculo é : "       << diametro       << endl;
    cout << "A circunferência do círculo é : " << circunferencia << endl;
    cout << "A área do círculo é : "           << area           << endl;

    int x=1, y=1;
    cout << x << y << endl;
    cout << ++x + ++y << endl;


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

