// Figura 8.27: fig08_27.cpp
// Programa de embaralhamento e distribuição de cartas.
#include <iostream>
#include <iomanip>
#include "DeckOfCards.h" // Definição da classe DeckOfCards
using namespace std;

int main()
{
	DeckOfCards deckOfCards; // cria objeto DeckOfCards
	
	deckOfCards.shuffle(); // embaralha as cartas
//	deckOfCards.deal(); // distribui as cartas
	deckOfCards.toShowDeck();
	deckOfCards.dealUmaMao(1);
	return 0; // indica terminação bem-sucedida
} // fim de main
