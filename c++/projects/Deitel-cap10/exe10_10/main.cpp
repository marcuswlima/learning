#include "DeckOfCards.h" // Definição da classe DeckOfCards

int main()
{
	Card c;
	Hand h1,h2;
	DeckOfCards doc;
	doc.shuffle();
	for (int i=1; i<=5; i++){
			doc.dealHand(h1);
			doc.dealHand(h2);
			h1.show();
			cout << " / ";
			h2.show();
			cout << " / ";
			cout << h1.peso() << ' ';
			cout << h2.peso() << '\n';
	}
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

	cout << '\n';
	return 0; // indica terminação bem-sucedida
} // fim de main

