// Figura 8.25: DeckOfCards.h
// Definição da classe DeckOfCards que
// representa um baralho.

// Definição da classe DeckOfCards
class DeckOfCards
{
public:
	DeckOfCards(); // construtor inicializa deck
	void shuffle(); // embaralha as cartas do baralho
	void deal(); // distribui as cartas do baralho
	int qualValor(int, int );
	void toShowDeck();
private:
	int deck[ 4 ][ 13 ]; // representa o baralho de cartas
}; // fim da classe DeckOfCards
