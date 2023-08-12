#include "Card.h"
using namespace std;

//-----------------------
// Construtores
// ----------------------
Card::Card(const int s, const int f){
	setCard(s,f);
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

bool Card::getShuffled()const{
	return shuffled;
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

void Card::setShuffled(const bool sh){
	shuffled=sh;
}


