#include <iostream>
#include <vector>
using namespace std;

class Card{
public:
	Card(const int, const int);
	Card();
//------------------------
	int getSuit()const;
	int getFace()const;
//---------------------
	void toString()const;
	Card &setCard(const int,const int);
//----------------------
    static const int qtdSuits = 4;
	static const int qtdFaces = 13;
private:
	void setSuit(const int);
	void setFace(const int);
//---------------------------
	int suit;
	int face;
	const char *suits[ qtdSuits ] = { "Hearts", "Diamonds", 
		                              "Clubs", "Espadas"};

	const char *faces[ qtdFaces ] = { "As",    "Deuce", "Three", 
		                              "Four",  "Five",  "Six", 
									  "Seven", "Eight", "Nine", 
									  "Ten",   "Jack",  "Queen", 
								      "King" };
};
