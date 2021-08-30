#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <iomanip>

using std::setprecision;
using std::setiosflags;

int main()
{
    double vendas, comissao; 
    double salario; 

    while ( vendas != -1 ) {

        salario = 200;
        cout << "Digite vendas em dólares (-1 para encerrar ) : " ;
        cin  >> vendas;

        if (vendas == -1) 
            continue;

        comissao = vendas/100*9;
        salario += comissao;

        cout << "salario -> " << salario << endl ;

    }

    cout << endl << endl ;
  return 0;
}

