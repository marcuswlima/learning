#include "Hand.h"

#ifndef DECKOSCARDS_H
#define DECKOFCARDS_H
class DeckOfCards
{
public:
	DeckOfCards(); 
//---------------------
	void shuffle();
	void show()const;
	void dealCard(Card &);
	bool moreCards()const;
	void dealHand(Hand &);
private:
	void order();
	int findCard(const int, const int)const;
	void swapCard(Card &, Card &);
//---------
	std::vector <Card> deck;
	std::vector <Card> hand;
	int currentCard;
	static const int QTDCARDS = Card::QTDSUITS * 
		                        Card::QTDFACES;
}; 
#endif

