#include <iostream>
#include <stdexcept>
#include "Mathematics.h"

#ifndef DATE_H
#define DATE_H
class Date 
{
public:
	// Constructors
	Date( int = 2000, int = 1, int = 1 );
	// Sets
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	void setDate(int,int,int);
	// Gets
	int getYear();
	int getMonth();
	int getDay();
	void print();
private:
	int month;
	int day;
	int year;
}; // end class Date

#endif
