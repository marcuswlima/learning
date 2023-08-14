#include <vector>
#include "Card.h"

class DeckOfCards
{
public:
	DeckOfCards(); 
//---------------------
	void shuffle();
	void showDeck()const;
	void dealCard(Card &);
	bool moreCards()const;
	void dealHand();
private:
	void order();
	int findCard(int,int);
	void swapCard(Card &, Card &);
//---------
	std::vector <Card> deck;
	int currentCard;
	static const int qtdCards = Card::qtdSuits * 
		                        Card::qtdFaces;
}; 
