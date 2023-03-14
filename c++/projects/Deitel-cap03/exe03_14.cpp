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

#include "Employee.h"

//setprecision(5) 
//setiosflags( ios::fixed | ios::showpoint )
////static_cast< double > ()


int main()
{
    int novoSalario;
    Employee emp1("Marcus","william",100), 
             emp2("Ignacio","Lima",200),
             emp3("Caetano","Lima",300)
             ;

    emp1.showEmployee();
    emp2.showEmployee();
    emp3.showEmployee();

    cout << endl;

    //novoSalario = ;

    emp1.setsalarioMensal(emp1.getSalarioMensal() + emp1.getSalarioMensal()/10);
    emp2.setsalarioMensal(emp2.getSalarioMensal() + emp2.getSalarioMensal()/10);
    emp3.setsalarioMensal(emp3.getSalarioMensal() + emp3.getSalarioMensal()/10);

    emp1.showEmployee();
    emp2.showEmployee();
    emp3.showEmployee();

//--------------------------------------------
    cout << endl << endl ;
    return 0;
}

