/************************************************************************
* Class: FreeCellGame
*
*Canonical Functions:
*	FreeCellGame();
*	~FreeCellGame();
*	FreeCellGame(const FreeCellGame & copy);
*	FreeCellGame & operator=(const FreeCellGame & right);
*
*Method:
*	void run();
*
*************************************************************************/
#ifndef FREECELLGAME_H
#define FREECELLGAME_H
#include<iostream>
#include"Board.h"
#include"Card.h"

using std::cout;
using std::endl;

class FreeCellGame
{
public:
	//Canonical Functions
	FreeCellGame();
	~FreeCellGame();
	FreeCellGame(const FreeCellGame & copy);
	FreeCellGame & operator=(const FreeCellGame & right);
	//Method
	void run();

private:
	Board	m_gameBoard;
	int		m_to;
	int		m_from;
	Card	m_card;
};
#endif