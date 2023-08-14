#include "DeckOfCards.h" // Definição da classe DeckOfCards

int main()
{
	Card c;
//	c.toString();

	DeckOfCards doc;
	doc.shuffle();
	while (doc.moreCards()){
		doc.dealCard(c);
		c.toString();
		cout << ' ';
	}
	cout << '\n';
	return 0; // indica terminação bem-sucedida
} // fim de main

