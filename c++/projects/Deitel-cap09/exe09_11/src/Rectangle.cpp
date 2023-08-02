#include "Rectangle.h"

//-------------------------------
// Prototipations
//-------------------------------
bool validatedEdge(int);

//-------------------------------
// Constructors
//-------------------------------
Rectangle::Rectangle(int l, int w){
	this->setRectangle(l,w);
}

//-------------------------------
// Publics
//-------------------------------

int Rectangle::perimeter(){
	return 2*(this->getLength() + this->getWidth());
}

int Rectangle::area(){
	return this->getLength() * this->getWidth();
}


//-------------------------------
// Privates
//-------------------------------
void Rectangle::setLength(int l){
	if (validatedEdge(l))
		this->length = l;
}
void Rectangle::setWidth(int w){
	this->width = w;
}

int Rectangle::getLength() const{
	return this->length;
}

int Rectangle::getWidth()const {
	return this->width;
}
void Rectangle::setRectangle(int l,int w){
	this->setLength(l);
	this->setWidth(w);
}


//-------------------------------
// Internals
//-------------------------------

bool validatedEdge(int e){
	return (e>1 && e<=20);
}

