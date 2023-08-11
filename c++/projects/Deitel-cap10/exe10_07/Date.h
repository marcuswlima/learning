#ifndef DATE_H
#define DATE_H

class Date 
{
public:
	Date( int = 1, int = 1, int = 1900 ); 
//	~Date(); 
	void print() const; 
	void printExtenso() const;
	void printN2() const;
private:
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year
	static const int monthsPerYear = 12;
	const char * const meses[ monthsPerYear + 1] = 
		{ NULL , "Janeiro", "Fevereiro", "Marco", "Abril", 
		 "Maio", "Junho", "Julho", "Agosto", "Setembro", 
		 "Outubro", "Novembro", "Dezembro"};
	const int daysPerMonth[ monthsPerYear + 1 ] = 
		{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int checkDay( int ) const; 
	int qtdDaysInMonth(int,int)const;
};

#endif
