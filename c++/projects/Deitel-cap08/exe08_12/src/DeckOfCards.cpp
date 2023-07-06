// Figura 8.26: DeckOfCards.cpp
// Definições de função-membro para a classe DeckOfCards que simula
// o embaralhamento e distribuição de um baralho.
#include <iostream>
using std::cout;
using std::left;
using std::right;

#include <iomanip>
using std::setw;

#include <cstdlib> // protótipos para rand e srand
using std::rand;
using std::srand;

#include <ctime> // protótipo para time
using std::time;

#include "DeckOfCards.h" // definição da classe DeckOfCards

int contarPar( int * const );
bool hasTrinca( int * const );
bool hasQuadra( int * const );
bool isFlush( int * const );
bool isStright( int * const, const int);
void selectionSort( int * const, const int); 
void maoToRespostas(const int [][3], bool * const, const int);

// inicializa o array suit
static const char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Espadas"};

// inicializa o array face
static const char *face[ 13 ] = { "As", "Deuce", "Three", "Four", "Five", "Six", "Seven",
								  "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

// construtor-padrão DeckOfCards inicializa deck
DeckOfCards::DeckOfCards()
{
	this->zerarBaralho();

	srand( time( 0 ) ); // semeia o gerador de número aleatório
} // fim do construtor-padrão DeckOfCards


void DeckOfCards::zerarBaralho()
{
	// itera pelas linhas do baralho
	for ( int row = 0; row <= 3; row++ )
	{
		// itera pelas colunas do baralho para linha atual
		for ( int column = 0; column <= 12; column++ )
		{
			this->deck[ row ][ column ] = 0; // inicializa slot de deck como 0
		} // fim do for interno
	} // fim do for externo

	//srand( time( 0 ) ); // semeia o gerador de número aleatório
} // fim do construtor-padrão DeckOfCards

// embaralha as cartas do baralho
void DeckOfCards::shuffle()
{
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
} // fim da função shuffle

// distribui as cartas do baralho
void DeckOfCards::deal()
{
	bool achou;
	//para_cada_carta 
	for ( int card = 1; card <= 52; card++ )
	{
		achou = false;
		//for_each_suite 
		for ( int s = 0; s <= 3; s++ )
		{
			// for_earch_face
			for ( int f = 0; f <= 12; f++ )
			{
				// se o slot contiver a carta atual, exibe a carta
				if ( this->deck[ s ][ f ] == card )
				{
					cout << setw( 5 ) << right << face[ f ] << " of " 
						 << setw( 8 ) << left  << suit[ s ]
						 << ( card % 2 == 0 ? '\n' : '\t' );
					achou=true;
					break;
				} // fim do if
			} // for_each_face
			if (achou)
				break;
		} // for_each_suite
	} // para_cada_carta
} // deal()

int DeckOfCards::qualValor(int suit, int face){
	return this->deck[suit][face];
}

void DeckOfCards::toShowDeck(){
	for (int i=0; i<=12; i++){
		cout << face[i] << '\t';
	}
	cout << '\n';
	for (int s = 0; s <= 3; s++){

		for (int f = 0; f <= 12; f++){
			cout << setw(2) << right << this->deck[s][f];
			if (f<12)
				cout << '\t';
		}
		cout << '\t' << suit[s] << "\n";
	}
}

void DeckOfCards::qualCarta(int card){
	//for_each_suite 
	for ( int s = 0; s <= 3; s++ )
	{
		// for_earch_face
		for ( int f = 0; f <= 12; f++ )

		{
			// se o slot contiver a carta atual, exibe a carta
			if ( this->deck[ s ][ f ] == card )
			{
				cout << card << " - " << face[ f ] << " of " 
					 << suit[ s ] << " (" << s << ',' << f << ')';
			} // fim do if
		} // for_each_face
	} // for_each_suite
	cout << '\n';
}

void DeckOfCards::exe12(int inicio){
	const int SIZE=5;
	int mao[SIZE][3];
	int suite, face;
	bool respostas[6];

	//montar mao
	for (int i=0; i<=(SIZE-1); i++){

		suite = this->qualSuite(inicio+i);
		face = this->qualFace(inicio+i);

		mao[i][0]=inicio+i;
		mao[i][1]=suite;
		mao[i][2]=face;

	}

	// mostar maos;
	for (int i=0; i<=(SIZE-1); i++){
		cout << mao[i][0] << ' ' << mao[i][1] << ' ' << mao[i][2] << '\n';
	}
	
	maoToRespostas(mao,respostas,SIZE);
	
	cout << "stright? "    << (respostas[0] ? "sim" : "nao") << '\n';
	cout << "flush? "      << (respostas[1] ? "sim" : "nao") << '\n';
	cout << "quadra? "     << (respostas[2] ? "sim" : "nao") << '\n';
	cout << "trincas? "    << (respostas[3] ? "sim" : "nao") << '\n';
	cout << "dois pares? " << (respostas[4] ? "sim" : "nao") << '\n';
	cout << "um par? "     << (respostas[5] ? "sim" : "nao") << '\n';

}

void DeckOfCards::exe13(int inicio){
	const int SIZE=5;
	int mao1[SIZE][3], mao2[SIZE][3];
	int face, suite;
	bool respostas1[6], respostas2[6];

	for (int i=0; i<=(SIZE-1); i++){
		// polular mao1;
		suite = this->qualSuite(inicio+i);
		face = this->qualFace(inicio+i);
		mao1[i][0]=inicio+i;
		mao1[i][1]=suite;
		mao1[i][2]=face;
		
		// polular mao2;
		suite = this->qualSuite(inicio+i+SIZE);
		face = this->qualFace(inicio+i+SIZE);
		mao2[i][0]=inicio+i+SIZE;
		mao2[i][1]=suite;
		mao2[i][2]=face;
	}
	// mostar maos;
	for (int i=0; i<=(SIZE-1); i++){
		cout << mao1[i][0] << ' ' << mao1[i][1] << ' ' << mao1[i][2] << '\t'
			 << mao2[i][0] << ' ' << mao2[i][1] << ' ' << mao2[i][2] << '\n';
	}
	maoToRespostas(mao1,respostas1,SIZE);
	maoToRespostas(mao2,respostas2,SIZE);
}


int DeckOfCards::qualSuite(int card){
	int resposta;
	//for_each_suite 
	for ( int s = 0; s <= 3; s++ )
	{
		// for_earch_face
		for ( int f = 0; f <= 12; f++ )
		{
			// se o slot contiver a carta atual, exibe a carta
			if ( this->deck[ s ][ f ] == card )
			{
				resposta = s;
			} // fim do if
		} // for_each_face
	} // for_each_suiteA

	return resposta;
}

int DeckOfCards::qualFace(int card){
	int resposta;
	//for_each_suite 
	for ( int s = 0; s <= 3; s++ )
	{
		// for_earch_face
		for ( int f = 0; f <= 12; f++ )
		{
			// se o slot contiver a carta atual, exibe a carta
			if ( this->deck[ s ][ f ] == card )
			{
				resposta = f;
			} // fim do if
		} // for_each_face
	} // for_each_suite

	return resposta;
}

int contarPar(int * const arr){
	int resposta=0;
	for (int i=0; i<=12; i++)
		if (arr[i]==2)
			resposta++;
	
	return resposta;
}

bool hasTrinca(int * const arr){
	bool resposta=false;
	for (int i=0; i<=12; i++)
		if (arr[i] == 3){
			resposta=true;
			break;
		}
	
	return resposta;
}

bool hasQuadra(int * const arr){
	bool resposta=false;
	for (int i=0; i<=12; i++)
		if (arr[i] == 4){
			resposta=true;
			break;
		}
	
	return resposta;
}

bool isFlush(int * const arr){
	int resposta=false;
	for (int i=0; i<=3; i++)
		if (arr[i] == 5){
			resposta=true;
			break;
		}
	
	return resposta;
}

bool isStright(int * const arr, const int size){

	selectionSort(arr,size);
	if ( 
		 arr[0]==(arr[1]-1) && 
		 arr[1]==(arr[2]-1) &&
		 arr[2]==(arr[3]-1) &&
		 arr[3]==(arr[4]-1) 
	   )
		return true;
	else
		return false;

}

 
// swap values at memory locations to which
// element1Ptr and element2Ptr point
// (Const pointer to nocost data, const pointer to noconst data)
void swap( int * const element1Ptr, int * const element2Ptr ) 
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
} // end function swap

// function to sort an array
// (Const Pointer to Nonconst data)
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
 
void maoToRespostas(const int mao[][3], bool * const respostas, const int SIZE){
	int somaSuites[4]={0,0,0,0};
	int somaFaces[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
	int faces[SIZE];
	int suite, face;
	
	//somas
	for (int i=0; i<=(SIZE-1); i++){

		suite = mao[i][1];
		face = mao[i][2];

		somaSuites[suite]++;
		somaFaces[face]++;

		faces[i]=face;
	}

	respostas[0] = isStright(faces,SIZE);
	respostas[1] = isFlush(somaSuites);
	respostas[2] = hasQuadra(somaFaces);
	respostas[3] = hasTrinca(somaFaces);
	respostas[4] = (contarPar(somaFaces)>=2);
	respostas[5] = (contarPar(somaFaces)>=1);

}

