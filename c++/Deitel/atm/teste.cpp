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


#include "Account.h" 

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()


int main()
{
 
    Account conta(0);
    cout << "Criada com 0 = " << conta.getBalance() << endl;
    conta.credit(10);
    cout << "+ 10 =  " << conta.getBalance() << endl;
    conta.credit(3);
    cout << "+ 3 =  " << conta.getBalance() << endl;
    conta.credit(15);
    cout << "+ 15 =  " << conta.getBalance() << endl;
    conta.debit(1);
    cout << "- 1 =  " << conta.getBalance() << endl;
    conta.debit(300);
    cout << "- 300 =  " << conta.getBalance() << endl;
    conta.debit(3);
    cout << "- 3 =  " << conta.getBalance() << endl;


//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

