#include "Date.h"
#include "Time.h"

#ifndef DATE_AND_TIME_H
#define DATE_AND_TIME_H

class DateAndTime
{
public:
	DateAndTime(int=2000,int=1,int=1
			   ,int=0,int=0,int=0);
	DateAndTime(const Date &, const Time &);
	void printUniversal() const;
	void tick();
	void nextDay();
private:
	Date date;
	Time time;
};


#endif


