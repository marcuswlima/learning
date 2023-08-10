// Fig. 10.08: Date.h 
// Date class definition; Member functions defined in Date.cpp
#ifndef DATE_H
#define DATE_H

class Date 
{
public:
	static const int monthsPerYear = 12; // number of months in a year
	
	Date( int = 1, int = 1, int = 1900 ); // default constructor
	~Date(); // provided to confirm destruction order
	void print() const; // print date in month/day/year format
	void printExtenso() const;
	void printN2() const;
private:
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year
	int checkDay( int ) const; 
	int qtdDaysInMonth(int,int)const;
	const char * const meses[ monthsPerYear + 1] = 
		{ NULL , "Janeiro", "Fevereiro", "Marco", "Abril", 
		 "Maio", "Junho", "Julho", "Agosto", "Setembro", 
		 "Outubro", "Novembro", "Dezembro"};
	const int daysPerMonth[ monthsPerYear + 1 ] = 
		{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
}; // end class Date

#endif
