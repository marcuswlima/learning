#include <iostream>
#include <iomanip>
#include "Date.h" 
using namespace std;

//---------------------------------------
// Construntors
//--------------------------------------
Date::Date( int m, int d, int y )
{
   this->setDate(y, m, d);
} 

//---------------------------------------
// Public
//--------------------------------------
void Date::print() const
{
	int y = this->getYear();
	int m = this->getMonth();
	int d = this->getDay();

	cout << setfill('0') << setw(2) << m << '/' 
		 << setfill('0') << setw(2) << d << '/' 
		 << y; 
} 

void Date::printExtenso()const
{
	int y = this->getYear();
	int m = this->getMonth();
	int d = this->getDay();
	
	const char * const meses[ this->monthsPerYear + 1] = 
		{ NULL , 
		 "Janeiro" , "Fevereiro", "Marco"   , "Abril", 
		 "Maio"    , "Junho"    , "Julho"   , "Agosto", 
		 "Setembro", "Outubro"  , "Novembro", "Dezembro"
		};
	
	cout << meses[m] << " " << d << ", " << y;
}

void Date::printN2() const
{
	int y = this->getYear();
	int m = this->getMonth();
	int d = this->getDay();

	for (int i=1;i<=m-1; i++){
		d += this->qtdDaysInMonth(y, m);
	}

	cout << d << ' ' << y;
}

void Date::nextDay(){
	int y = this->getYear();
	int m = this->getMonth();
	int d = this->getDay();
	int qtdDias=this->qtdDaysInMonth(y,m);

	d++;
	if (d > qtdDias){
		d=1;
		m++;
		if (m > 12){
			m=1;
			y++;
		}
	}
	this->setDate(y,m,d);
}

void Date::setCurrentDate(){
   time_t agora = time(0);
   tm * dh = localtime( &agora );
   this->setDate((1900 + dh->tm_year) , (1 + dh->tm_mon) , dh->tm_mday);
}

//cascade function call//
Date &Date::setDate(int y,int m,int d){
	this->setYear(y);
	this->setMonth(m);
	this->setDay(y,m,d);

	return *this;
}

//---------------------------------------
// Private
//--------------------------------------
int Date::qtdDaysInMonth(int pYear, int pMonth)const{
	const int daysPerMonth[ this->monthsPerYear + 1 ] = 
		{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (pMonth == 2 && (pYear % 4) == 0){
		return 29;
	}else{
		return daysPerMonth[pMonth];
	}
}

//--------------------------------------
// Sets
// -------------------------------------
void Date::setYear(int y){
	if ( y >= this->menorAno){
		this->year = y;
	}else{
		throw invalid_argument("ano invalido");
	}
}

void Date::setMonth(int m){
	if (m >= 1 && m <= this->monthsPerYear){
		this->month = m;
	}else{
		throw invalid_argument("mes invalido");
	}
}

void Date::setDay(int y,int m, int d){
	int qtdDias = this->qtdDaysInMonth(y,m);
	if (d >= 1 && d <= qtdDias){
		this->day = d;
	}else{
		throw invalid_argument("dia invalido");
	}
}

//--------------------------------------
// Gets
// -------------------------------------
int Date::getYear() const{
	return this->year;
}

int Date::getMonth() const{
	return this->month;
}

int Date::getDay()const {
	return this->day;
}


//--------------------------------------
// internals
// -------------------------------------

