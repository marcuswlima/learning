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


int contarPar(int *);
int contarTrinca(int []);
int contarQuadra(int []);
bool isFlush(int *);

// inicializa o array suit
static const char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades"};

// inicializa o array face
static const char *face[ 13 ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
								  "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

// construtor-padrão DeckOfCards inicializa deck
DeckOfCards::DeckOfCards()
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

	srand( time( 0 ) ); // semeia o gerador de número aleatório
} // fim do construtor-padrão DeckOfCards

// embaralha as cartas do baralho
void DeckOfCards::shuffle()
{
	int suite; // representa o valor do naipe da carta
	int face; // representa o valor da face da carta
	
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
	//para_cada_carta 
	for ( int card = 1; card <= 52; card++ )
	{
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
				} // fim do if
			} // for_each_face
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
				cout << card << " - " << face[ f ] << " of " << suit[ s ] << " (" << s << ',' << f << ')';
			} // fim do if
		} // for_each_face
	} // for_each_suite
	cout << '\n';
}

void DeckOfCards::dealUmaMao(int inicio){
	const int SIZE=5;
	int somaSuites[4]={0,0,0,0};
	int somaFaces[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
	int qtdPares=0;

	for (int i=0; i<=(SIZE-1); i++)
		this->qualCarta(inicio+i);
//	for (int i=0; i<=(SIZE-1); i++)
//		cout << this->qualFace(inicio+i)<<'\n';
	for (int i=0; i<=(SIZE-1); i++){
		somaFaces[this->qualFace(inicio+i)]++;
		somaSuites[this->qualSuite(inicio+i)]++;
	}

	
//	for (int i=0; i<=12; i++)
//		cout << i << '-' << somaFaces[i] << ' ';
//	cout << '\n';
//	for (int i=0; i<=3; i++)
//		cout << i << '-' << somaSuites[i] << ' ';
//	cout << '\n';
	
	cout << "um par? "     << (contarPar(somaFaces)    >= 1 ? "sim" : "nao") << '\n';
	cout << "dois pares? " << (contarPar(somaFaces)    >= 2 ? "sim" : "nao") << '\n';
	cout << "trincas? "    << (contarTrinca(somaFaces) >= 1 ? "sim" : "nao") << '\n';
	cout << "quadra? "     << (contarQuadra(somaFaces) >= 1 ? "sim" : "nao") << '\n';
	cout << "flush? "      << (isFlush(somaSuites)          ? "sim" : "nao") << '\n';
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
	} // for_each_suiteA

	return resposta;
}

int contarPar(int *f){
	int resposta=0;
	for (int i=0; i<=12; i++)
		if (f[i]==2)
			resposta++;
	
	return resposta;
}

int contarTrinca(int *f){
	int resposta=0;
	for (int i=0; i<=12; i++)
		if (f[i] == 3)
			resposta++;
	
	return resposta;
}

int contarQuadra(int *f){
	int resposta=0;
	for (int i=0; i<=12; i++)
		if (f[i] == 4)
			resposta++;
	
	return resposta;
}

bool isFlush(int f[]){
	int resposta=false;
	for (int i=0; i<=3; i++)
		if (f[i] == 5){
			resposta=true;
			break;
		}
	
	return resposta;
}



