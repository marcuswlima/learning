#include "DeckOfCards.h" // Definição da classe DeckOfCards

int main()
{
	Card c(1,1);
//	c.toString();

	DeckOfCards dof;
	dof.shuffle();
	dof.showDeck();
	cout << '\n';
	return 0; // indica terminação bem-sucedida
} // fim de main

