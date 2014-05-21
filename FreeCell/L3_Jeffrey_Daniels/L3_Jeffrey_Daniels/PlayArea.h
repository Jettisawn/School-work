/************************************************************************
* Class: PlayArea
*
*Canonical functions:
*	PlayArea();
*	~PlayArea();
*	PlayArea(const PlayArea & copy);
*	PlayArea & operator=(const PlayArea & right);
*
*Mutators:
*	Card RemoveCard(int index);
*	void PlaceCard(Card aCard, int index);
*
*Acessors:
*	int OpenCells(int FromStack);
*	bool isEmpty(int index);
*	Card & Peek(int index);
*
*Methods:
*	void Display();
*	bool legalMove( Card aCard, int index);
*
*************************************************************************/
#ifndef PLAYAREA_H
#define PLAYAREA_H

#include<iostream>
#include"Array.h"
#include"Card.h"
#include"Deck.h"
#include"ListStack.h"

#define COLUMNCOUNT 8

template<typename T>
class ListStack;


using std::cin;
class PlayArea
{
public:
	//canonical fucntions
	PlayArea();
	PlayArea(Deck aDeck);
	~PlayArea();
	PlayArea(const PlayArea & copy);
	PlayArea & operator=(const PlayArea & right);

	//Mutators
	Card RemoveCard(int index);
	void PlaceCard(Card aCard, int index);

	//Acessors
	int OpenCells(int FromStack);
	bool isEmpty(int index);
	Card & Peek(int index);

	//Methods
	void Display();
	bool legalMove( Card aCard, int index);
private:

	Array<ListStack<Card>>  m_play;
};

#endif