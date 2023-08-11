#ifndef SAVINGBALANCE_H
#define SAVINGBALENCE_H

class SavingAccount{
	public:
		SavingAccount(double);
		double f_calculateMonthlyInterest() const;
		static void setAnnualInterestRate(int);
		void printAll() const;
	private:
		static int d_annualInterestRate;
		double d_savingBalance;
		//sets
		void setSavingBalance (double);
		//gets
		double getSavingBalance() const;
		static int getAnnualInterestRate();
};

#endif
