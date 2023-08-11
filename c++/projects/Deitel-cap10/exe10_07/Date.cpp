#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Date.h" 
using namespace std;

//---------------------------------------
// Public
//--------------------------------------
Date::Date( int mn, int dy, int yr )
{
   if ( mn > 0 && mn <= monthsPerYear ) 
      month = mn;
   else 
      throw invalid_argument( "month must be 1-12" );

   year = yr; 
   day = checkDay( dy );

} 

//Date::~Date()
//{ 
//} 

void Date::print() const
{
	cout << setfill('0') << setw(2) << month << '/' 
		 << setfill('0') << setw(2) << day   << '/' 
		 << year; 
} 

void Date::printExtenso()const
{
	cout << meses[month] << " " << day << ", " << year;
}

void Date::printN2() const
{
	int qtdDiasAno = day;

	for (int i=1;i<=month-1; i++){
		qtdDiasAno += qtdDaysInMonth(year, month);
	}

	cout << qtdDiasAno << ' ' << year;
}

//---------------------------------------
// Private
//--------------------------------------
int Date::checkDay( int testDay ) const
{
   if ( testDay > 0 && testDay <= qtdDaysInMonth(year, month))
      return testDay;

   throw invalid_argument( "Invalid day for current month and year" );
} // end function checkDay

int Date::qtdDaysInMonth(int pYear, int pMonth)const{
   // February 29 check for leap year 
	if (pMonth == 2 && pYear%4==0){
		return 29;
	}else{
		return daysPerMonth[pMonth];
	}
}


