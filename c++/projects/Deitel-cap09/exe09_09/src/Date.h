#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Mathematics.h"

#ifndef DATE_H
#define DATE_H
class Date 
{
public:
	// Constructors
	Date(int=2000,int=1,int=1);
	void print() const;
	void nextDay();
	void setDate(int,int,int);
private:
	int month;
	int day;
	int year;
	// Sets
	void setYear(int);
	void setMonth(int);
	void setDay(int,int,int);
	// Gets
	int getYear() const ;
	int getMonth() const;
	int getDay() const;
}; // end class Date

#endif
