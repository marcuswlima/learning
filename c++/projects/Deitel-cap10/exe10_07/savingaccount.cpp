#include <iostream>
#include "savingaccount.h"
using namespace std;

//-------------------------------------
// initializing statics data members
//-------------------------------------
int SavingAccount::d_annualInterestRate=0;

//---------------------------
// Constructor
//---------------------------
SavingAccount::SavingAccount( double sb ){
	setSavingBalance(sb);
}

//---------------------------
// Publics
//---------------------------
double SavingAccount::f_calculateMonthlyInterest() const{
	double sb = getSavingBalance();
	int air = getAnnualInterestRate();

	return static_cast< double >( sb * air ) / 12 ;
}
		
void SavingAccount::setAnnualInterestRate(int air){
	d_annualInterestRate = air;
}

void SavingAccount::printAll() const{
	cout << getSavingBalance()           << '\t' 
		 << getAnnualInterestRate()      << '\t' 
		 << f_calculateMonthlyInterest() << '\n';
}

//---------------------------
// Sets
//---------------------------
void SavingAccount::setSavingBalance(double sb){
	d_savingBalance = sb;
}

//---------------------------
// gets
//---------------------------
double SavingAccount::getSavingBalance() const{
	return d_savingBalance;
}

int SavingAccount::getAnnualInterestRate(){
	return d_annualInterestRate;
}

