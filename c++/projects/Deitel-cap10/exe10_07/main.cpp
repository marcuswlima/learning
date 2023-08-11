#include <iostream>
#include "savingaccount.h" 
using namespace std;

int main()
{
	SavingAccount saver1(2000), saver2(3000);

	SavingAccount::setAnnualInterestRate(3);
	saver1.printAll();
	saver2.printAll();

	SavingAccount::setAnnualInterestRate(4);
	saver1.printAll();
	saver2.printAll();
	
	return 0;

} // end main
