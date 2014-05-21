/************************************************************************
* Class: Deck
*
* Canonical functions:
*	Deck();
*	~Deck();
*	Deck(const Deck & copy);
*	Deck & operator=(const Deck & right);
*		destructor
*
* Mutators:
*	void shuffle();
*	Card & Deal();
*
*Acessors:
*	int getSize();
*
*************************************************************************/
#ifndef DECK_H
#define DECK_H

#include"Card.h"
#include"Array.h"

class Deck
{
public:
	Deck();
	~Deck();
	Deck(const Deck & copy);
	Deck & operator=(const Deck & right);

	int getSize();
	void shuffle();
	Card & Deal();

private:
	Array<Card> m_card;
	int m_size;
};

#endif