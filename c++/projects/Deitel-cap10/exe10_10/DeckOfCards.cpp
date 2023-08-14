#include "DeckOfCards.h" // definição da classe DeckOfCards

//-----------------------
// Construtores
// ----------------------
DeckOfCards::DeckOfCards(){
	order();
}


//-----------------------
// public
// ----------------------
void DeckOfCards::shuffle()
{
	order();
	currentCard=0;
	srand( time( 0 ) ); // semeia o gerador de número aleatório
	int suite, face, newCard;

	for (int i=0; i<qtdCards; i++){
		suite = rand() % Card::qtdSuits; 
		face = rand() % Card::qtdFaces;
		newCard = findCard(suite,face);
		swapCard(deck[newCard],deck[i]);
	}
} 

void DeckOfCards::showDeck()const{
	for (int i=1; i<=qtdCards; i++){
		deck[i-1].toString();
//		cout << ( (i % 13) == 0  ? "\n" : ", ");
		cout << ' '; 
	}
}

bool DeckOfCards::moreCards()const{
	return currentCard < qtdCards;
}

void DeckOfCards::dealCard(Card &c){
	c=deck[currentCard++];
}

void DeckOfCards::dealHand(){
		std::vector <Card> hand;
}
//-----------------------
// private
// ----------------------
void DeckOfCards::order(){
	deck.clear();
	Card c;
	for (int s=0; s<=Card::qtdSuits-1; s++){
		for (int f=0; f<=Card::qtdFaces-1; f++){
			c.setCard(s,f);
			deck.push_back(c);
		}
	}

}

int DeckOfCards::findCard(int s, int f){
	int resposta=0;
	for (int i=0; i<qtdCards; i++){
		if (deck[i].getSuit() == s && deck[i].getFace() == f)	{
			resposta = i;
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

