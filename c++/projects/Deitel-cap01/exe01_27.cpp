#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  
    int raio, diametro, circunferencia, area;
    cout << "Qual o raio do círculo ? ";
    cin >> raio ; 

    diametro       = raio * 2; 
    circunferencia = 3.14 * diametro;
    area           = raio * raio * 3.14;

    cout << "O diâmetro do círculo é : "       << diametro       << endl;
    cout << "A circunferência do círculo é : " << circunferencia << endl;
    cout << "A área do círculo é : "           << area           << endl;


    return 0;
}

