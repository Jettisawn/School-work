#include "Deck.h"

/**************************************************************
*   Entry:  sets card Card ranks and place them into Decks Array
*
*    Exit:  none
*
* Purpose:  default contructor for Deck Class
*
***************************************************************/
Deck::Deck():m_size(53),m_card(53)
{
	int count(0);

	m_card[count].setRank(0);
	m_card[count].setSuit(2);
	m_card[count].setColor(-1);

	count++;

	for(char i = 3; i < 7; i++)
	{
		for(int j = 1; j < 14; j++, ++count)
		{
			m_card[count].setRank(j);
			m_card[count].setSuit(i);
			
			if(i == 3 || i == 4)
			{
				m_card[count].setColor(1);
			}
			else
			{
				m_card[count].setColor(0);
			}
		}
	}

}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default destructor for Deck Class
*
***************************************************************/
Deck::~Deck()
{}

/**************************************************************
*   Entry:  make deck passed in equal to deck that calls it
*
*    Exit:  none
*
* Purpose:  default copy constructor for Deck Class
*
***************************************************************/
Deck::Deck(const Deck & copy)
{
	*this = copy;
}

/**************************************************************
*   Entry:  make deck on left hand of Equals operator equal
*			to right hand operator
*
*    Exit:  none
*
* Purpose: overloaded equals operator for Deck Class
*
***************************************************************/
Deck & Deck::operator=(const Deck & right)
{
	m_card = right.m_card;
	m_size = right.m_size;

	return *this;
}

/**************************************************************
*   Entry:  Deck.Deal(),
*
*    Exit:  none
*
* Purpose:  used to deal all the cards in the deck class
*
***************************************************************/
Card & Deck::Deal()
{

		return m_card[--m_size];
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  returns the size of the deck
*
***************************************************************/
int Deck::getSize()
{
	return m_size;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  Used to shuffle the cards within a deck
*
***************************************************************/
void Deck::shuffle()
{
	Card aCard;
	int holder(0);

	for (int i=1; i<(53-1); i++) 
	{
		holder = i + (rand() % (53-i)); // Random remaining position.
		 aCard = m_card[i]; 
		 m_card[i] = m_card[holder]; 
		 m_card[holder] = aCard;
	}
}