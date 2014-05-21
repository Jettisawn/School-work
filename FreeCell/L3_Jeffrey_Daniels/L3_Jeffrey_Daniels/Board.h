/************************************************************************
* Class: Board
*
*Canonical functions:
*	Board();
*	~Board();
*	Board(const Board & copy);
*	Board & operator=(const Board & right);
*
*Mutators:
*	int moveTo();
*	Card moveFrom( int & from);
*	void move( Card aCard, int to, int from);
*	void play2play( Card aCard);
*
*Methods:
*	bool Gameover();
*	void display();
*
*************************************************************************/
#ifndef BOARD_H
#define BOARD_H	

#include<iostream>
#include"Deck.h"
#include"Card.h"
#include"ArrayStack.h"
#include"Array.h"
#include"FreeCells.h"
#include"HomeCells.h"
#include"ListStack.h"
#include"PlayArea.h"

using std::cin;
using std::cout;
using std::endl;

class Board
{	
public: 
	Board();
	~Board();
	Board(const Board & copy);
	Board & operator=(const Board & right);
	
	int moveTo();
	Card moveFrom( int & from);
	void move( Card aCard, int to, int from);
	void play2play( Card aCard);
	
	bool Gameover();
	void display();
private:
		int m_FromStack;
		int m_ToStack;

		Deck	  m_deck;
		FreeCells m_free; //Array<Card> m_free;
		HomeCells m_home; //Array<ArrayStack<Card>> m_home;
		PlayArea  m_play;//Array<ListStack<Card>>  m_play && Deck m_deck;
		
};
#endif