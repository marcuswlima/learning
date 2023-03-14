#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()


#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;

#include <cmath>

int main()
{
    int numeroProduto = 1 , quantidadeVendida, quanidadeProdutos=0;
    double valorProduto, total = 0 ;

    while ( numeroProduto != 0 ) {

        cout << endl;
        cout << "Número Produto < [1,5] 0 sair > : ";
        cin >> numeroProduto;

        if (numeroProduto == 0) 
            continue;
        
        if (numeroProduto > 5){
            cout << "Informe de 1 a 5; " << endl;
            continue;
        }

        cout << "Quantidade Vendida: ";
        cin >> quantidadeVendida;

        ++quanidadeProdutos;

        switch (numeroProduto) {
            case 1 : valorProduto = 2.98; break;
            case 2 : valorProduto = 4.50; break;
            case 3 : valorProduto = 9.98; break;
            case 4 : valorProduto = 4.49; break;
            case 5 : valorProduto = 6.87; break;
        }

        total += quantidadeVendida * valorProduto;

        cout  << "Valor parcial " << quantidadeVendida * valorProduto << endl;
    } // while


    cout << endl << "Foram vendidos " << quanidadeProdutos << " produto(s)";
    cout << endl << "total ->  " << total ;


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

