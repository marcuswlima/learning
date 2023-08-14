#include <iostream>
#include <vector>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card{
public:
	Card(const int, const int);
	Card();
//------------------------
	int getFace()const;
	int getSuit()const;
//---------------------
	void show()const;
	Card &setCard(const int,const int);
//----------------------
	static const int QTDFACES = 13;
    static const int QTDSUITS = 4;
private:
	void setFace(const int);
	void setSuit(const int);
//---------------------------
	int face;
	int suit;
	const char *faces[ QTDFACES ] = { "As",    "Deuce", "Three", 
		                              "Four",  "Five",  "Six", 
									  "Seven", "Eight", "Nine", 
									  "Ten",   "Jack",  "Queen", 
								      "King" };
	const char *suits[ QTDSUITS ] = { "Hearts", "Diamonds", 
		                              "Clubs", "Espadas"};

};

#endif
