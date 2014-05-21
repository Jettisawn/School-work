#include"HomeCells.h"

#include<iostream>
using std::cout;

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default contructor for HomeCells class
*
***************************************************************/
HomeCells::HomeCells():m_home(4)
{
	Card empty;

	for(int i(0); i < 4; i++)
	{
		m_home[i] = (52);
		m_home[i].Push(empty);
	}
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default desructor for HomeCells class
*
***************************************************************/
HomeCells::~HomeCells()
{}
/**************************************************************
*   Entry:  make HomeCells passed in equal to HomeCells that calls it
*
*    Exit:  none
*
* Purpose:  default copy constructor for HomeCells class
*
***************************************************************/
HomeCells::HomeCells(const HomeCells & copy)
{
	*this = copy;
}
/**************************************************************
*   Entry:  make HomeCells on left hand of Equals operator equal
*			to the HomeCells on the right hand operator
*
*    Exit:  none
*
* Purpose: overloaded equals operator for HomeCells class
*
***************************************************************/
HomeCells & HomeCells::operator=( const HomeCells & right)
{
	m_home = right.m_home;

	return *this;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  after card is placed into Home cell
*
* Purpose:  Place card into first available Array withing Home
*			cell area or in the proper suit and after the proper
*			rank of previous Card
*
***************************************************************/
void HomeCells::PlaceCard( Card aCard)
{
	Card empty;

	for( int i(0); i < 4 && empty != aCard; i++)
	{
		if((m_home[i].Peek().getSuit() == aCard.getSuit()) 
			|| (m_home[i].Peek() == empty))
		{
			m_home[i].Push(aCard);
			empty = aCard;
		}
	}
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  Used to display the top Card in the HomeCells Area 
*			to the screen
*
***************************************************************/
void HomeCells::Display()
{

	for(int i(0); i < m_home.getLength(); i++)
	{
		m_home[i].Peek().display();
	}
}
/**************************************************************
*   Entry:  none
*
*    Exit:  Returns True if HomeCells Area is full
*
* Purpose:  Used to determain if HomeCells Array of ArrayList 
*			is full
*
***************************************************************/
bool HomeCells::isFull()
{
	bool test(true);

	for(int i(0); i < 4 && test != false; i++)
	{
		if(m_home[i].Size() != 14)
			test = false;
	}
	return test;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  Returns True if an Array cell is empty
*
* Purpose:  Used to determain if HomeCells has avaialable ArrayCell
*
***************************************************************/
bool HomeCells::openCell()
{
	Card empty;
	bool test(false);

	for( int i(0); i < 4 && test == false ; i++)
	{
		if(m_home[i].Peek() == empty)
		{
			test = true;
		}
	}
	
	return true;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  Returns True, if Card being passed in can be placed 
*			ontop of previous Card
*
* Purpose:  Used for placing cards in order from Ace to King
*
***************************************************************/
bool HomeCells::CardCheck(Card aCard)
{
	bool test(false);

	for( int i(0); i < 4 && test == false; i++)
	{
		if(m_home[i].Peek().getSuit() == aCard.getSuit() 
		  && m_home[i].Peek().getRank() < aCard.getRank()
		  && m_home[i].Peek().getRank()+2 > aCard.getRank())
		{
			test = true;
		}
	}
	return test;
}
