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

	for (int i=0; i<QTDCARDS; i++){
		suite = rand() % Card::QTDSUITS; 
		face = rand() % Card::QTDFACES;
		newCard = findCard(face,suite);
		swapCard(deck[newCard],deck[i]);
	}
} 

void DeckOfCards::show()const{
	for (int i=1; i<=QTDCARDS; i++){
		deck[i-1].show();
//		cout << ( (i % 13) == 0  ? "\n" : ", ");
		cout << ' '; 
	}
}

bool DeckOfCards::moreCards()const{
	return currentCard < QTDCARDS;
}

void DeckOfCards::dealCard( Card &c ){
	c=deck[currentCard++];
}

void DeckOfCards::dealHand( Hand &h ){
	Card c;
	h.clear();
	for(int i=1; i<=Hand::SIZE_HAND; i++){
		dealCard(c);
		h.push_back(c);
	}
}

//-----------------------
// private
// ----------------------
void DeckOfCards::order(){
	Card c;
	deck.clear();
	for (int s=0; s<=Card::QTDSUITS-1; s++){
		for (int f=0; f<=Card::QTDFACES-1; f++){
			c.setCard(f,s);
			deck.push_back(c);
		}
	}

}

int DeckOfCards::findCard(const int f, const int s)const{
	int resposta=0;
	for (int i=0; i<QTDCARDS; i++){
		if (deck[i].getFace() == s && deck[i].getSuit() == f)	{
			resposta = i;
			break;
		}
	}
	return resposta;
}

void DeckOfCards::swapCard(Card &c1, Card &c2){
	int tf=c2.getFace();
	int ts=c2.getSuit();

	c2.setCard(c1.getFace(), c1.getSuit());
	c1.setCard(tf,ts);
}

