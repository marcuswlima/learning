#include "Hand.h"

//-----------------------
// prototipations
// ----------------------
int contarPar(const int * const , const int );
bool contarMesmaFace(const int * const, const int, const int);
bool isFlush(const int * const , const int);
bool isStraight(std::vector <Card> );
//-----------------------
// Construtores
// ----------------------
Hand::Hand(){
}

//-----------------------
// public
// ----------------------
void Hand::clear(){
	hand.clear();
}

void Hand::push_back(const Card c){
	hand.push_back(c);
}

void Hand::show()const{
	for (int i=0; i < SIZE_HAND; i++){
		hand[i].show();
		cout << ' '; 
	}
}

void Hand::analize()const{

	const int qtdFaces = Card::QTDFACES; 
	const int qtdSuits = Card::QTDSUITS; 
	int sumFaces[qtdFaces];
	int sumSuits[qtdSuits];


	{//inicializar vetores
		for (int i=0; i < qtdFaces; i++)
			sumFaces[i]=0;

		for (int i=0; i < qtdSuits; i++)
			sumSuits[i]=0;
	}//incializar vetore


	for (int i=0; i<SIZE_HAND; i++){
		sumFaces[hand[i].getFace()]++;
		sumSuits[hand[i].getSuit()]++;
	}

//	for (int i=0; i < qtdFaces; i++)
//		cout << sumFaces[i]<< ' ';

	if ( contarPar(sumFaces,qtdFaces) >= 1 ) 
		cout << " / contains a pair";
	if ( contarPar(sumFaces,qtdFaces) >= 2 )
		cout << " / contains two pairs";
	if ( contarMesmaFace(sumFaces,3,qtdFaces) )
		cout << " / contains three of a kind";
	if ( contarMesmaFace(sumFaces,4,qtdFaces) )
		cout << " / contains four of a kind";
	if ( isFlush(sumSuits,qtdSuits) )
		cout << " / contains flush";
	if ( isStraight(hand) )
		cout << " / contains straight";

}


//-----------------------
// internals
// ----------------------
int contarPar(const int * const arr, const int SIZE){
	int resposta=0;
	for (int i=0; i<SIZE; i++)
		if (arr[i]==2)
			resposta++;
	
	return resposta;
}

bool contarMesmaFace(const int * const arr, const int valorDesejado, const int SIZE){
	for (int i=0; i<SIZE; i++){
		if (arr[i] == valorDesejado)
			return true;
	}
	return false;
}

bool isFlush(const int * const arr, const int SIZE){
	for (int i=0; i < SIZE; i++)
		if ( arr[i] == 5 )
			return true;

	return false;
}

void swap( int * const element1Ptr, int * const element2Ptr )
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
} // end function swap

void selectionSort( int * const array, const int size ) 
{
    int smallest; // index of smallest element

    // loop over size - 1 elements
    for ( int i = 0; i < size - 1; ++i )
    {
        smallest = i; // first index of remaining array

        // loop to find index of smallest element
        for ( int index = i + 1; index < size; ++index )

            if ( array[ index ] < array[ smallest ] )
                smallest = index;

        swap( &array[ i ], &array[ smallest ] );
    } // end if
} // end function selectionSort

bool isStraight(std::vector <Card> hand){
//	const int qtdFaces = SIZE_HAND; 
	const int qtdHand = 5; 
	int faces[qtdHand];

	for (int i=0; i < qtdHand; i++){
		faces[i]=hand[i].getFace();
	}

	selectionSort(faces,qtdHand);

	if (
		 faces[0]==(faces[1]-1) &&
		 faces[1]==(faces[2]-1) &&
		 faces[2]==(faces[3]-1) &&
		 faces[3]==(faces[4]-1)
	   )
		return true;
	else
		return false;

}

