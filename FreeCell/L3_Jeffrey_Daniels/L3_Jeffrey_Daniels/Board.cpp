#include"Board.h"

#include<iostream>
#include <Windows.h>

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//setConsoleCursorPosition(handle, cur_pos);

using std::cout;
using std::endl;

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default contructor for Board class
*
***************************************************************/
Board::Board(): m_FromStack(0), m_ToStack(0), m_play(m_deck)
{
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default destructor for Board class
*
***************************************************************/
Board::~Board()
{}
/**************************************************************
*   Entry:  make board passed in equal to board that calls it
*
*    Exit:  none
*
* Purpose:  default copy constructor for board
*
***************************************************************/
Board::Board(const Board & copy): m_play(copy.m_play)
{
	*this = copy;
}
/**************************************************************
*   Entry:  make board on left hand of Equals operator equal
*			to right hand operator
*
*    Exit:  none
*
* Purpose: overloaded equals operator for board
*
***************************************************************/
Board & Board::operator=( const Board & right)
{
	m_FromStack = right.m_FromStack;
	m_ToStack = right.m_ToStack;

	m_deck = right.m_deck;
	m_play = right.m_play;
	m_free = right.m_free;
	m_home = right.m_home;

	return * this;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  Used to call the display functions of m_free,
*			m_home, and m_play
*
***************************************************************/
void Board::display()
{
	SetConsoleTextAttribute( handle, 46);
	system("cls");

	cout <<"|---Free Cells------Home Cells---|" << endl;
	m_free.display();
	COORD cur_pos;
	cur_pos.X = 16;
	cur_pos.Y = 1;
	SetConsoleCursorPosition(handle, cur_pos);
	cout <<'|';

	m_home.Display();
	SetConsoleTextAttribute( handle, 46);
	cout <<"|\n|--------------------------------|" << endl;
	m_play.Display();
	SetConsoleTextAttribute( handle, 46);
	cout << "\n" << endl;
}
/**************************************************************
*   Entry:  int From by reference, 
*
*    Exit:  returns Card, fromstack, and which section it came from
*
* Purpose:  Used to pull card from cell and return were it came
*			from.
*
***************************************************************/
Card Board::moveFrom( int & from)
{ 
	Card TempCard;
	from = 0;
	
	while(from < 1 || from > 2)
	{
		COORD cur_pos;
		cur_pos.X = 0;
		cur_pos.Y = 23;
		SetConsoleCursorPosition(handle, cur_pos);

		cout << "\nWhere would you like to move from"
			 << "\nPlayArea:  1"
			 << "\nFreecells: 2"
			 << "\nselection: ";

		cin  >> from;
	}

	if(from ==  1)
	{
		m_FromStack= 0;

		while(m_FromStack < 1)
		{
			cout << "\nWhich Column would you like to Pull FROM:  ";
			cin >> m_FromStack;

			if(m_FromStack < 1 || m_FromStack > 8)
			{
				throw Exception("Invalid Entry\n");
			}	
		}	

		if(m_play.isEmpty(m_FromStack))
		{
		   throw Exception("invalid move\n");
		}
		
		TempCard = m_play.RemoveCard(m_FromStack);
		
	}

	else if(from == 2)
	{
		m_FromStack= 0;

		if(!m_free.isEmpty())
		{
			
			while(m_FromStack < 1)
			{
				cout << "\nWhich Free Cell would you like to Pull Card From:  ";
				cin >>m_FromStack;

				if(m_FromStack < 1 || m_FromStack > 4)
				{
					throw Exception("Invalid Entry\n");
				}
			}

			if(m_free.openCell(m_FromStack))
			{
				 throw Exception("invalid move\n");
			}

			TempCard = m_free.RemoveCard(m_FromStack);
		}
		else
		{
			 throw Exception("invalid move\n");
		}

	}

	else
	{		
		throw Exception("Error in Entry\n");
	}
	

	return TempCard;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  change Tostack, and which section it Card is going to
*
* Purpose:  Used to get input of where card is going to and possible
*			stack Card is going to.
*
***************************************************************/
int Board::moveTo()
{
	int to(0);

	while(to < 1 || to > 3 )
	{

		cout << "\nWhere would you like to move to"
			 <<"\nPlayArea:  1"
			 <<"\nFreecells: 2"
			 <<"\nHomecells: 3"
			 << "\nselection: ";
		cin  >> to;
	

		if(to ==  1)
		{
			m_ToStack = 0;

			while(m_ToStack < 1)
			{
				cout << "\nWhich Column would you like to move TO:  ";
				cin >> m_ToStack;

				if(m_ToStack < 1 || m_ToStack > 8)
				{
					throw Exception("invalid entry\n");
				}	
			}

			to = 1;
		}

		else if(to == 2)
		{
			if(m_free.isFull())
			{
				throw Exception("invalid move\n");
			}
		}
	}
	
	return to;
	
}
/**************************************************************
*   Entry:  int to, int from, and Card pulled from
*
*    Exit:  after card is placed
*
* Purpose:  Used to move a card from one area to another area
*
***************************************************************/
void Board::move(Card aCard, int to, int from)
{
	Card Empty;

	switch (to)//playArea = 1, freeArea = 2, homeArea = 3
	{
		case 1:
				if(from == 1)
				{	//Moves card stack to another Card Stack
					play2play(aCard);

				}
				else if(from == 2)
				{
					if( m_play.legalMove(aCard, m_ToStack))
					{
						m_play.PlaceCard(aCard, m_ToStack);
					}
					else
					{
					//from FreeCell area
						m_free.PlaceCard(aCard);
						throw Exception("invalid move\n");
					}
				}	
			break;

		case 2:
				if(!m_free.isFull())
				{
					m_free.PlaceCard(aCard);
				}
				else
				{
					m_play.PlaceCard(aCard, m_FromStack);
					throw Exception("invalid move\n");
				}
			break;

		case 3: 	
				if(( m_home.openCell() && aCard.getRank() == 1)
				  ||(m_home.CardCheck(aCard) == true))
					{
						m_home.PlaceCard(aCard);
					}
				else
				{
					if(from == 1)
					{
						m_play.PlaceCard(aCard, m_FromStack);
						throw Exception("invalid move\n");
					}
					else
					{
						m_free.PlaceCard(aCard);
						throw Exception("invalid move\n");
					}
				}
			break;
		default:
			throw Exception("Error in Game");
			break;
	}
}
/**************************************************************
*   Entry:  a Card 
*
*    Exit:  After Card stack is placed in correct area
*
* Purpose:  Creates a temporary stack fills it with cards for 
*			the number of available open cells and places Cards
*			to new Area or back were they came from
*
***************************************************************/
void Board::play2play( Card aCard)
{
	ListStack<Card> tempArray;
	int moves(0);
	int moves2(0);

	moves = m_free.NumFreeCells() + m_play.OpenCells(m_FromStack) +1;

	while(moves2< moves && !m_play.isEmpty(m_FromStack))
	{
		tempArray.Push(aCard);
		aCard = m_play.RemoveCard(m_FromStack);
		moves2++;
	}
	
	while(moves2 >= 0)
	{
		if( m_play.legalMove(aCard, m_ToStack))
		{
			m_play.PlaceCard(aCard, m_ToStack);
			if(!tempArray.isEmpty())
			{
				aCard = tempArray.Peek();
				tempArray.Pop();
			}
			moves2--;
		}
		else
		{
			m_play.PlaceCard(aCard, m_FromStack);
			if(!tempArray.isEmpty())
			{
				aCard = tempArray.Peek();
				tempArray.Pop();
			}
			moves2--;
		}
	}
}
/**************************************************************
*   Entry:  none
*
*    Exit:  retuns True if homecells are full
*
* Purpose:  determine the end of the game
*
***************************************************************/
bool Board::Gameover()
{
	bool test(false);

	if(m_home.isFull())
	{
		test = true;
	}

	return test;
}