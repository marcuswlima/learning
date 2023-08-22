#ifndef TIME_H
#define TIME_H

class Time 
{
public:
	Time( const int , const int, const int  ); 
	Time( const int );
	Time( );

	//publics 
	Time &setTime( const int, const int, const int ); 
	Time &setHour( const int ); 
	Time &setMinute( const int ); 
	Time &setSecond( const int ); 
	Time &setSeconds( const int ); 

	void printUniversal() const;
	void printStandard() const;
	void setCurrentTime();
	void tick();
private:
	const int MAX_SECONDS=60*60*24;
	int second; // 0 - 86400

	// gets
	int getHour() const; 
	int getMinute() const;
	int getSecond() const;
	int getSeconds() const; 
}; // end class Time

#endif
