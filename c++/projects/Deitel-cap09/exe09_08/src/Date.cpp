#include "Date.h" 
using namespace std;

//--------------------------------------
// Prototipations
// -------------------------------------
bool validate(int y, int m, int d);

//--------------------------------------
// Constructors
// -------------------------------------
Date::Date( int y, int m, int d)
{
	if (validate(y,m,d))
		this->setDate(y,m,d);
	else
		throw invalid_argument("Data Invalida "+to_string(y)+'/'+to_string(m)+'/'+to_string(d) );
} // end constructor Date

//--------------------------------------
// Sets
// -------------------------------------
void Date::setYear(int p){
	this->year = p;
}
void Date::setMonth(int p){
	this->month = p;
}
void Date::setDay(int p){
	this->day = p;
}

void Date::setDate(int y,int m,int d){
	this->setYear(y);
	this->setMonth(m);
	this->setDay(d);
}
//--------------------------------------
// Gets
// -------------------------------------
int Date::getYear(){
	return this->year;
}

int Date::getMonth(){
	return this->month;
}

int Date::getDay(){
	return this->day;
}

//--------------------------------------
// Publics
// -------------------------------------
void Date::print() 
{ 
   cout << month << '/' << day << '/' << year; 
} // end function print

//--------------------------------------
// Internals
// -------------------------------------
bool validate(int y, int m, int d){

	if (y<2000){
		return false;
	}else{
		if (m<1 || m>12){
			return false;
		}else{
			bool bisexto=(GetRemainder(y,4)==0);
			if (  bisexto  && (m==2) && ( d<1 || d >29)){
				return false;
			}
			if (!(bisexto) && (m==2) && ( d<1 || d >28)){
				return false;
			}
			
		}
	}

	return true;
}
