/************************************************************************
* Class: HomeCells
*
*Canonical functions:
*	HomeCells();
*	~HomeCells();
*	HomeCells(const HomeCells & copy);
*	HomeCells & operator=(const HomeCells & right);
*
*Mutators:
*	void PlaceCard(Card aCard);
*	
*Accessors:
*	bool CardCheck(Card aCard);
*	bool openCell();
*	bool isFull();
*	
*Methods:
*	void display();
*
*************************************************************************/
#ifndef HOMECELLS_H
#define HOMECELLS_H

#include"Array.h"
#include"ArrayStack.h"
#include"Card.h"

class HomeCells
{
public:
	//Canonical function
	HomeCells();
	~HomeCells();
	HomeCells(const HomeCells & copy);
	HomeCells & operator=(const HomeCells & right);

	//Mutators
	void PlaceCard(Card aCard);
	
	//Accessors
	bool CardCheck(Card aCard);
	bool openCell();
	bool isFull();

	//Methods
	void Display();
private:
	Array<ArrayStack <Card>> m_home;
};
#endif  