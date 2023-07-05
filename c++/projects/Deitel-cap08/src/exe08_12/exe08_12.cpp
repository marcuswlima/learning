// Figura 8.27: fig08_27.cpp
// Programa de embaralhamento e distribuição de cartas.
#include “DeckOfCards.h” // Definição da classe DeckOfCards

int main()
{
	DeckOfCards deckOfCards; // cria objeto DeckOfCards
	
	deckOfCards.shuffle(); // embaralha as cartas
	deckOfCards.deal(); // distribui as cartas
	return 0; // indica terminação bem-sucedida
} // fim de main
