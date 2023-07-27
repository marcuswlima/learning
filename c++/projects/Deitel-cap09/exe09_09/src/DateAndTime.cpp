#include "DateAndTime.h"

//-----------------------
// Constructors
// ----------------------

DateAndTime::DateAndTime(int y, int mo, int d
		                ,int h, int mi, int s){
	this->date.setDate(y,mo,d);
	this->time.setTime(h,mi,s);
}


//-----------------------
// Publics
// ----------------------
void DateAndTime::printUniversal(){
	this->date.print();
	cout << ' ';
	this->time.printUniversal();
}

void DateAndTime::tick(){
	this->time.tick();
	
	int h=this->time.getHour(),
		mi=this->time.getMinute(),
		s=this->time.getSecond();
	
	if (h==0 && mi==0 && s==0)
		this->nextDay();
}

void DateAndTime::nextDay(){
	this->date.nextDay();
}
