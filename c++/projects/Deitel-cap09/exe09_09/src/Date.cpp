#include "Date.h" 
using namespace std;

//--------------------------------------
// Prototipations
// -------------------------------------
int qtdDiasEmUmMes(int y,int  m);

//--------------------------------------
// Constructors
// -------------------------------------
Date::Date( int y, int m, int d)
{
	this->setDate(y,m,d);
} // end constructor Date

//--------------------------------------
// Publics
// -------------------------------------
void Date::print() const 
{ 
   cout << year << '/' 
	    << setfill( '0' ) << setw( 2 ) << month << '/' 
		<< setfill( '0' ) << setw( 2 ) <<  day ; 
} // end function print

void Date::nextDay(){
	int y = this->getYear(),
		m = this->getMonth(),
		d = this->getDay();
	int qtdDias=qtdDiasEmUmMes(y,m);

	d++;
	if (d>qtdDias){
		d=1;
		m++;
		if (m>12){
			m=1;
			y++;
		}

	}
	this->setDate(y,m,d);
}


//--------------------------------------
// Sets
// -------------------------------------
void Date::setYear(int y){
	if (y>=2000){
		this->year = y;
	}else{
		throw invalid_argument("ano invalido");
	}
}
void Date::setMonth(int m){
	if (m>=1 && m<=12){
		this->month = m;
	}else{
		throw invalid_argument("mes invalido");
	}
}
void Date::setDay(int y,int m, int d){
	int qtdDias=qtdDiasEmUmMes(y,m);
	if (d>=1 && d<=qtdDias){
		this->day = d;
	}else{
		throw invalid_argument("dia invalido");
	}
}

void Date::setDate(int y,int m,int d){
	this->setYear(y);
	this->setMonth(m);
	this->setDay(y,m,d);
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

int Date::getDay() const{
	return this->day;
}

//--------------------------------------
// Internals
// -------------------------------------

int qtdDiasEmUmMes(int y,int  m){
	if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
		return 31;
	else if(m==4 || m==6 || m==9 || m==11)
		return 30;
	else 
		if (GetRemainder(y,4)==0)//ano bisexto
			return 29;
		else
			return 28;
}
