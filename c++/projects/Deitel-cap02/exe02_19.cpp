#include <iostream>


using std::cout;
using std::cin;
using std::endl;

int main () {


    int horasTrabalhadas;
    double valorhora, salario=0;

    cout << "Digite horas trabalhadas (-1 para encerar): " ;
    cin >> horasTrabalhadas ;

    while (horasTrabalhadas != -1)
    {
        salario = 0;
        cout << "Digite o valor da horas do trabalhador:  " ;
        cin >> valorhora ;

        if ( horasTrabalhadas <= 40 ) {
            salario += (valorhora * horasTrabalhadas);
        }
        else { // maior que 40 horas
            salario = salario + (valorhora * 40);
            int excedente = (horasTrabalhadas - 40) ;
            salario += (excedente * valorhora * 1.5);

        }

        cout << "O salario é  " << salario << endl;


        cout << "Digite horas trabalhadas (-1 para encerar): " ;
        cin >> horasTrabalhadas ;
    }
    






    cout << "O salario é  " << salario << endl ;
    
    
    
    cout << endl << endl ;



    return 0;
}