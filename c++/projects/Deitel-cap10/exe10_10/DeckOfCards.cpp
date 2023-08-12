#include "DeckOfCards.h" // definição da classe DeckOfCards

//-----------------------
// Construtores
// ----------------------
DeckOfCards::DeckOfCards(){
	order();
	srand( time( 0 ) ); // semeia o gerador de número aleatório
}


//-----------------------
// public
// ----------------------
void DeckOfCards::shuffle()
{
	order();
	int qtdCards = Card::qtdSuits * Card::qtdFaces,
	    suite,
	    face,
		newCard;

	qtdCards=2;
	for (int i=1; i<=qtdCards; i++){
		suite = rand() % 4; 
		face = rand() % 13;
		newCard = findCard(suite,face);
		swapCard(deck[newCard],deck[i-1]);
	}
/*
	int suite; // representa o valor do naipe da carta
	int face; // representa o valor da face da carta
	
	this->zerarBaralho();
	
	// para cada uma das 52 cartas, escolhe um slot aleatoriamente
	for ( int card = 1; card <= 52; card++ )
	{
		do // escolhe uma nova localização aleatória até um slot vazio ser encontrado
		{
			suite = rand() % 4; // seleciona a linha aleatoriamente
			face = rand() % 13; // seleciona a coluna aleatoriamente
		} while( this->deck[ suite ][ face ] != 0 ); // fim da instrução do...while

		// coloca o número de carta no slot escolhido
		deck[ suite ][ face ] = card;
	} // fim do for
*/
} // fim da função shuffle

void DeckOfCards::showDeck()const{
	int qtdCards = Card::qtdSuits * Card::qtdFaces;
	for (int i=1; i<=qtdCards; i++){
		deck[i-1].toString();
		cout << ( (i % 13) == 0  ? "\n" : ", ");
	}
}

//-----------------------
// private
// ----------------------
void DeckOfCards::order(){
	deck.clear();
	Card c(0,0);
	for (int s=0; s<=Card::qtdSuits-1; s++){
		for (int f=0; f<=Card::qtdFaces-1; f++){
			c.setCard(s,f);
			deck.push_back(c);
		}
	}
}

int DeckOfCards::findCard(int s, int f){
	int qtdCards = Card::qtdSuits * Card::qtdFaces;
	int resposta=0;
	for (int i=1; i<=qtdCards; i++){
		if (deck[i-1].getSuit() == s && deck[i-1].getFace() == f)	{
			resposta = (i-1);
			break;
		}
	}
	return resposta;
}


void DeckOfCards::swapCard(Card &c1, Card &c2){
	int ts=c2.getSuit();
	int tf=c2.getFace();

	c2.setCard(c1.getSuit(), c1.getFace());
	c1.setCard(ts,tf);


}

