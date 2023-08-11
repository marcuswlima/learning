#ifndef DATE_H
#define DATE_H

class Date 
{
public:
	Date( int = 1, int = 1, int = menorAno ); 
	//publics
	void print() const; 
	void printExtenso() const;
	void printN2() const;
	void nextDay();
	void setCurrentDate();
	//cascade function call// 
	Date &setDate(int,int,int);
private:
	int month; 
	int day; 
	int year;
	static const int monthsPerYear = 12;
	static const int menorAno = 1900;
	//privates
	int qtdDaysInMonth(int,int)const;
	// Sets
	void setYear(int);
	void setMonth(int);
	void setDay(int,int,int);
	// Gets
	int getYear() const;
	int getMonth() const;
	int getDay()const ;
};

#endif
