#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setprecision;
using std::setiosflags;
using std::setw;

#include <cmath>

using std::ios;

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()

#include "Invoice.h" 


int main()
{
    Invoice invoiceTest1("1","primeiro item",2,30);
    cout << "id -> " << invoiceTest1.getId() << endl; 
    cout << "descricao -> " << invoiceTest1.getDescricao() << endl; 
    cout << "quantidade -> " << invoiceTest1.getQuantidade() << endl; 
    cout << "PrecoPorItem -> " << invoiceTest1.getPrecoPorItem() << endl; 
    cout << "Total -> " << invoiceTest1.getInvoiceAmmount() << endl; 

    Invoice invoiceTest2("2","segundo",-2,30);
    cout << "id -> " << invoiceTest2.getId() << endl; 
    cout << "descricao -> " << invoiceTest2.getDescricao() << endl; 
    cout << "quantidade -> " << invoiceTest2.getQuantidade() << endl; 
    cout << "PrecoPorItem -> " << invoiceTest2.getPrecoPorItem() << endl; 
    cout << "Total -> " << invoiceTest2.getInvoiceAmmount() << endl; 

    Invoice invoiceTest3("3","terceiro",2,-30);
    cout << "id -> " << invoiceTest3.getId() << endl; 
    cout << "descricao -> " << invoiceTest3.getDescricao() << endl; 
    cout << "quantidade -> " << invoiceTest3.getQuantidade() << endl; 
    cout << "PrecoPorItem -> " << invoiceTest3.getPrecoPorItem() << endl; 
    cout << "Total -> " << invoiceTest3.getInvoiceAmmount() << endl; 

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

