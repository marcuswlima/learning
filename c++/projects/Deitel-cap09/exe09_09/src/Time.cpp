#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <ctime>
#include "Time.h" 
using namespace std;


//------------------------------
// Contructors
//------------------------------
Time::Time( int hour, int minute, int second ) 
{ 
   setTime( hour, minute, second );
} 

//------------------------------
// Sets
//------------------------------
void Time::setTime( int h, int m, int s )
{
   setHour( h ); // set private field hour
   setMinute( m ); // set private field minute
   setSecond( s ); // set private field second
}

void Time::setHour( int h )
{
   if ( h >= 0 && h < 24 )
      hour = h;
   else
      throw invalid_argument( "hour must be 0-23" );
}

void Time::setMinute( int m )
{
   if ( m >= 0 && m < 60 )
      minute = m; 
   else
      throw invalid_argument( "minute must be 0-59" );
} // end function setMinute

void Time::setSecond( int s )
{
   if ( s >= 0 && s < 60 )
      second = ( ( s >= 0 && s < 60 ) ? s : 0 ); 
   else
      throw invalid_argument( "second must be 0-59" );
} // end function setSecond

//------------------------------
// Gets
//------------------------------
int Time::getHour() const 
{
   return hour;
} // end function getHour

int Time::getMinute() const
{
   return minute;
} // end function getMinute

int Time::getSecond() const
{
   return second;
} // end function getSecond

//------------------------------
// Publics
//------------------------------
void Time::printUniversal() const
{
   cout << setfill( '0' ) << setw( 2 ) << getHour() << ":"
      << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond();
} // end function printUniversal

void Time::printStandard() const
{
   cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
      << ":" << setfill( '0' ) << setw( 2 ) << getMinute()
      << ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard

void Time::setCurrentTime(){
   time_t agora = time(0);
   tm * dh = localtime( &agora );
   setTime(dh->tm_hour,dh->tm_min,dh->tm_sec );
}

void Time::tick(){
	int s=this->getSecond(),
		m=this->getMinute(),
		h=this->getHour();
	
	s++;
	if (s>=60){
		s=0;
		m++;
		if (m>=60){
			m=0;
			h++;
			if (h>=24){
				h=0;
			}
		}
	}

	this->setSecond(s);
	this->setMinute(m);
	this->setHour(h);

}


