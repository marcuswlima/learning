#include <vector>
#include "Card.h"

class DeckOfCards
{
public:
	DeckOfCards(); 
	void shuffle();
	void deal(); 
	void showDeck()const;
private:
	std::vector <Card> deck;
	int currentCard;
	void order();
	int findCard(int,int);
	void swapCard(Card &, Card &);
}; 
