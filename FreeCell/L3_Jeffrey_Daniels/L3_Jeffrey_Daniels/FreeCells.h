/************************************************************************
* Class: FreeCells
*
*Canonical functions:
*	FreeCells();
*	~FreeCells();
*	FreeCells(const FreeCells & copy);
*	FreeCells & operator=(const FreeCells & right);
*
*Mutators:
*	void PlaceCard( Card aCard);
*	Card RemoveCard(int index);
*	
*Accessors:
*	bool isFull();
*	bool isEmpty();
*	bool openCell(int index);
*	int  NumFreeCells();
*	
*Methods:
*	void display();
*
*************************************************************************/
#ifndef FREECELLS_H
#define FREECELLS_H

#include"Array.h"
#include"Card.h"
#include"PlayArea.h"

template<typename T>
class Array;

class FreeCells
{
public:
	//Canoncical functions
	FreeCells();
	~FreeCells();
	FreeCells(const FreeCells & copy);
	FreeCells & operator=(const FreeCells & right);

	//Mutators
	void PlaceCard( Card aCard);
	Card RemoveCard(int index);
	
	//Accessors
	bool isFull();
	bool isEmpty();
	bool openCell(int index);
	int  NumFreeCells();
	
	//Methods
	void display();

private:
	int m_numFree;
	Array<Card> m_cells;
};
#endif