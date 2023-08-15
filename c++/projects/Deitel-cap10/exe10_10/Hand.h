#include <vector>
#include "Card.h"

#ifndef HAND_H
#define HAND_H
class Hand
{
public:
	Hand();
	void clear();
	void push_back(const Card);
	void show()const;
	void analize()const;
	int peso()const;
//------------------
	static const int SIZE_HAND=5;
private:
	std::vector <Card> hand;
};
#endif


