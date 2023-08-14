#include "Card.h"
using namespace std;

//-----------------------
// Construtores
// ----------------------
Card::Card(const int s, const int f){
	setCard(s,f);
}


Card::Card(){
}

//-----------------------
// public
// ----------------------
Card &Card::setCard(const int s, const int f){
	setSuit(s);
	setFace(f);
	return *this;
}

void Card::toString()const{
	cout << faces[getFace()] << " of " << suits[getSuit()] ;
}

int Card::getSuit()const{
	return suit;
}

int Card::getFace()const{
	return face;
}

//-----------------------
// private
// ----------------------
void Card::setSuit(const int s){
	suit = s;
}

void Card::setFace(const int f){
	face = f;
}
