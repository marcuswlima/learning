#include "Card.h"
using namespace std;

//-----------------------
// Construtores
// ----------------------
Card::Card(const int f, const int s){
	setCard(f,s);
}


Card::Card(){
}

//-----------------------
// public
// ----------------------
Card &Card::setCard(const int f, const int s){
	setFace(f);
	setSuit(s);
	return *this;
}

void Card::show()const{
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
