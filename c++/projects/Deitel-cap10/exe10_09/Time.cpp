#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h" // Time class definition
using namespace std;

void NumberToHour(const int , int &, int &, int &);
int HourToNumber(const int , const int , const int );

//---------------------------------------------
// constructors
//---------------------------------------------
Time::Time( int hr, int min, int sec ) 
{ 
   setTime( hr, min, sec ); 
} 

Time::Time( int s ) 
{ 
	setSeconds( s ); 
} 

Time::Time(){
	setSeconds( 0 ); 
}
//---------------------------------------------
// publics
//---------------------------------------------
Time &Time::setTime( const int h, const int m, const int s ) // note Time & return
{
	setSeconds(HourToNumber(h,m,s));
	return *this; // enables cascading
} // end function setTime

Time &Time::setHour( const int ph ) // note Time & return
{	
	if ( ph >= 0 && ph < 24 ){
		int h, m, s;
		NumberToHour(getSeconds(),h,m,s);
		setSeconds(HourToNumber(ph,m,s));
	}
	else
		throw invalid_argument( "hour must be 0-23" );

	return *this; // enables cascading
} // end function setHour

Time &Time::setMinute( const int pm ) // note Time & return
{
   if ( pm >= 0 && pm < 60 ){
		int h, m, s;
		NumberToHour(getSeconds(), h ,m ,s);
		setSeconds(HourToNumber(h, pm, s));
   }
   else
      throw invalid_argument( "minute must be 0-59" );

   return *this; // enables cascading
} // end function setMinute

Time &Time::setSecond( const int ps ) // note Time & return
{
   if ( ps >= 0 && ps < 60 ){
		int h, m, s;
		NumberToHour(getSeconds(), h ,m ,s);
		setSeconds(HourToNumber(h, m, ps));
   }
   else
      throw invalid_argument( "second must be 0-59" );

   return *this; // enables cascading
} // end function setSecond

Time &Time::setSeconds( const int s ) 
{
	if (s >=0 && s<=MAX_SECONDS){
		this->second=s;
	}else{
		throw invalid_argument( "quantide de segundos invalida entre 0-"+MAX_SECONDS );
	}

   return *this; // enables cascading
} // end function setSecond

void Time::printUniversal() const
{
   cout << setfill( '0' ) << setw( 2 ) << getHour()   << ":"
                          << setw( 2 ) << getMinute() << ":" 
						  << setw( 2 ) << getSecond();
} 

void Time::printStandard() const
{
	int h=getHour();
	int m=getMinute();
	int s=getSecond();
	cout << ( ( h == 0 || h == 12 ) ? 12 : h % 12 )
	     << ":" << setfill( '0' ) << setw( 2 ) << m
  	     << ":" << setw( 2 ) << s << ( h < 12 ? " AM" : " PM" );
}

void Time::setCurrentTime(){
   time_t agora = time(0);
   tm * dh = localtime( &agora );
   setTime(dh->tm_hour,dh->tm_min,dh->tm_sec );
}

void Time::tick(){
	int s=this->getSeconds();
	
	s++;
	if (s >= MAX_SECONDS){
		s=0;
	}

	this->setSeconds(s);

}

//---------------------------------------------
// privates
//---------------------------------------------
int Time::getSeconds() const 
{ 
   return second; 
} 

int Time::getHour() const 
{ 
	int h, m, s;
	NumberToHour(getSeconds(), h ,m ,s);
	return h; 
}

int Time::getMinute() const 
{ 
	int h, m, s;
	NumberToHour(getSeconds(), h ,m ,s);
	return m; 
}

int Time::getSecond() const 
{ 
	int h, m, s;
	NumberToHour(getSeconds(), h ,m ,s);
	return s; 
}

//---------------------------------------------
// internals
//---------------------------------------------
void NumberToHour(const int secs, int &h, int &m, int &s){
	int r;
    h = secs / 3600 ;
	r = secs % 3600 ;

	m = r / 60;
	r = r % 60;

	s = r;
}

int HourToNumber(const int h, const int m, const int s){
	return (h*3600) + (m*60) + (s);
}

