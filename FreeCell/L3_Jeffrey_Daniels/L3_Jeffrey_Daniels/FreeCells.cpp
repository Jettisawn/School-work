#include"FreeCells.h"
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default contructor for FreeCells class
*
***************************************************************/
FreeCells::FreeCells():m_cells(4), m_numFree(4)
{}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default desructor for FreeCells class
*
***************************************************************/
FreeCells::~FreeCells()
{}
/**************************************************************
*   Entry:  make FreeCells passed in equal to FreeCells that calls it
*
*    Exit:  none
*
* Purpose:  default copy constructor for FreeCells class
*
***************************************************************/
FreeCells::FreeCells(const FreeCells & copy)
{
	*this = copy;
}
/**************************************************************
*   Entry:  make FreeCells on left hand of Equals operator equal
*			to the FreeCells on the right hand operator
*
*    Exit:  none
*
* Purpose: overloaded equals operator for FreeCells class
*
***************************************************************/
FreeCells & FreeCells::operator=( const FreeCells & right)
{
	m_numFree = right.m_numFree;
	m_cells   = right.m_cells;

	return * this;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  Used to display the FreeCells Area of cards to the screen
*
***************************************************************/
void FreeCells::display()
{
	cout << '|';
	for(int i(0); i < m_cells.getLength(); i++)
	{
		m_cells[i].display();
	}

}
/**************************************************************
*   Entry:  none
*
*    Exit:  Returns True if FreeCells is empty
*
* Purpose:  Used to determain if Freecells array is empty
*
***************************************************************/
bool FreeCells::isEmpty()
{
	Card empty;
	bool test(true);

	for(int i(0); i < 4; i++)
	{
		if(m_cells[i] != empty)
		{
			test = false;
		}
	}

	if(test == true)
	{
		m_numFree = 4;
	}

	return test;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  Returns True if FreeCells is full
*
* Purpose:  Used to determain if Freecells array is full
*
***************************************************************/
bool FreeCells::isFull()
{
	Card empty;
	bool test(true);

	for(int i(0); i < 4; i++)
	{
		if( m_cells[i] == empty)
		{
			test = false;
		}
	}

	if(test == true)
	{
		m_numFree = 0;
	}

	return test;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  Returns True if array index of Free cell is empty
*
* Purpose:  Used to determain if array index is empty
*
***************************************************************/
bool FreeCells::openCell( int index)
{
	bool test(false);
	Card empty;

	if( m_cells[index-1] == empty)
	{
		test = true;
	}

	return test;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  removes Card from Freecells Array
*
* Purpose:  pulls Card from array index of FreeCells
*
***************************************************************/
Card FreeCells::RemoveCard(int index)
{
	Card empty;
	Card grabbed;

		grabbed = m_cells[index-1].getCard();
		m_numFree++;
		m_cells[index-1] = empty;



	return grabbed;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  Returns int of number of free cells
*
* Purpose:  return number of empty Arrays in FreeCell area 
*
***************************************************************/
int FreeCells::NumFreeCells()
{
	return m_numFree;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  after card is placed into free cell
*
* Purpose:  Place card into first available Array withing Free
*			cell area
*
***************************************************************/
void FreeCells::PlaceCard( Card aCard)
{
	Card empty;

		for(int i(0); i < 4 && aCard != empty; i++)
		{
			if(openCell(i+1))
			{
				empty = aCard;
				m_cells[i] = aCard;
				m_numFree--;
			}
		}

		if(aCard != empty)
		{
			throw Exception("Error in Game\n");
		}
}