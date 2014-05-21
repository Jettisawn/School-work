#include "Card.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

HANDLE handle2 = GetStdHandle(STD_OUTPUT_HANDLE);

using std::cout;
using std::endl;
using std::setw;

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default contructor for Card class
*
***************************************************************/
Card::Card():m_rank(0),m_suit(2),m_colorCode(-1)
{}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  OverLoaded contructor for Card class
*
***************************************************************/
Card::Card(int rank, char suit): m_rank(rank), m_suit(suit),m_colorCode(-1)
{}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default destructor for Card class
*
***************************************************************/
Card::~Card()
{}
/**************************************************************
*   Entry:  make Card passed in equal to Card that calls it
*
*    Exit:  none
*
* Purpose:  default copy constructor for Card class
*
***************************************************************/
Card::Card(const Card & copy)
{
	*this = copy;
}
/**************************************************************
*   Entry:  make Card on left hand of Equals operator equal
*			to the Card on the right hand operator
*
*    Exit:  none
*
* Purpose: overloaded equals operator for Card class
*
***************************************************************/
Card & Card::operator=(const Card & right)
{
	m_rank = right.m_rank;
	m_suit = right.m_suit;
	m_colorCode = right.m_colorCode;
	
	return *this;
}
/**************************************************************
*   Entry:  Checks if Card on right is equal to card on left
*
*    Exit:  none
*
* Purpose: overloaded equals/equals operator for Card class
*
***************************************************************/
bool Card::operator==(const Card & right)
{
	if(m_rank == right.m_rank && m_suit == right.m_suit)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
/**************************************************************
*   Entry:  Checks if Card on right is not equal to card on left
*
*    Exit:  none
*
* Purpose: overloaded Not/equals operator for Card class
*
***************************************************************/
bool Card::operator!=(const Card & right)
{
	if(m_rank != right.m_rank || m_suit != right.m_suit)
	{
		return true;
	}
	else {
		return false;
	}
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: returns rank of a card
*
***************************************************************/
int Card::getRank()
{
	return m_rank;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: returns suit of a card
*
***************************************************************/
char Card::getSuit()
{
	return m_suit;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: returns color code of a card
*
***************************************************************/
int Card::getColor()
{
	return m_colorCode;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: returns a Card
*
***************************************************************/
Card &  Card::getCard()
{
	return *this;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  change the rank of a card
*
* Purpose: used to set rank of a card
*
***************************************************************/
void Card::setRank(int rank)
{
	m_rank = rank;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  change the color code of a card
*
* Purpose: used to set color code of a card
*
***************************************************************/
void Card::setColor( int color)
{
	m_colorCode = color;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  change the suit of a card
*
* Purpose: used to set suit of a card
*
***************************************************************/
void Card::setSuit( int suit)
{
	m_suit = suit;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: Display the proper rank, and suit and proper suit
*		   color of a card
*
***************************************************************/
void Card::display()
{
	SetConsoleTextAttribute( handle2, 47);
	switch (m_rank)
	{
	case 1:
		cout << " A";
		break;
	case 11:
		cout << " J";
		break;
	case 12:
		cout << " Q";
		break;
	case 13:
		cout << " K";
		break;
	default:
		cout << setw(2)<< m_rank;
		break;
	}

	if(m_colorCode == 0)
	{
		SetConsoleTextAttribute( handle2, 32);
	}

	else if(m_colorCode == 1)
	{
		SetConsoleTextAttribute( handle2, 36);
	}

	else
	{
		SetConsoleTextAttribute( handle2, 47);
	}

	if(m_suit >2)
	{
	 cout << m_suit << ' ';
	}
	else
	{
	 cout << "  ";
	}
}