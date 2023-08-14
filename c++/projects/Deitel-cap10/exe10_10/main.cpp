#include "DeckOfCards.h" // Definição da classe DeckOfCards

int main()
{
	Card c;
	Hand h;
	DeckOfCards doc;
/*

	h.clear();
	c.setCard(0,0);
	h.push_back(c);
	c.setCard(1,0);
	h.push_back(c);
	c.setCard(2,0);
	h.push_back(c);
	c.setCard(3,0);
	h.push_back(c);
	c.setCard(4,0);
	h.push_back(c);
	h.show();
	h.analize();
	
*/

	doc.shuffle();
	for (int i=1; i<=4; i++){

//		if (doc.moreCards()){
			doc.dealHand(h);
			h.show();
			h.analize();
			cout << '\n';
//		}
	}
	cout << '\n';
	return 0; // indica terminação bem-sucedida
} // fim de main

