#include"PlayArea.h"
#include <Windows.h>

HANDLE handle4 = GetStdHandle(STD_OUTPUT_HANDLE);
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default constructor for PlayArea
*
***************************************************************/
PlayArea::PlayArea():m_play(8)
{}
/**************************************************************
*   Entry:  Places Cards from Deck onto play area
*
*    Exit:  none
*
* Purpose:  overloaded constructor for PlayArea
*
***************************************************************/
PlayArea::PlayArea(Deck aDeck):m_play(8)
{
	char choice (0);
	int shuffle(0);

	while( choice != 'Y'  && choice != 'N')
	{
		cout <<"\nWould you like to Play in debugger mode Y/N: ";
		cin >> choice;

		if(choice != 'Y' && choice != 'N')
		{
			cout << "Incorrect choice, please input Y or N" << endl;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin.clear();

			system("pause");
			system("cls");
		}
	}

	if(choice == 'N')
	{
		shuffle = rand() % 8 + 2;

		for( int i(0); i < shuffle; i++)
		{
			aDeck.shuffle();
		}
	}
	else
	{
		cout << "\n\nRESOURCE FILE CONTAINS WIN CODE\n" << endl;
		system("pause");
	}

		while(aDeck.getSize()-1 > 0)
	{
			for(int i = 0; i < 8 ; i++)
			{
				if(aDeck.getSize()-1 >0)
				{
					m_play[i].Push(aDeck.Deal());
				}
			}
	}
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default destructor for PlayArea
*
***************************************************************/
PlayArea::~PlayArea()
{}
/**************************************************************
*   Entry:  make PlayArea passed in equal to PlayArea that calls it
*
*    Exit:  none
*
* Purpose:  default copy constructor for PlayArea
*
***************************************************************/
PlayArea::PlayArea( const PlayArea & copy)
{
	*this = copy;
}
/**************************************************************
*   Entry:  make PlayArea on left hand of Equals operator equal
*			to right hand operator
*
*    Exit:  none
*
* Purpose: overloaded equals operator for FreeCellGame
*
***************************************************************/
PlayArea & PlayArea::operator=(const PlayArea & right)
{
	m_play = right.m_play;

	return *this;
}
/**************************************************************
*   Entry:  int index
*
*    Exit:  none
*
* Purpose: returns true if an PlayArea index is empty
*
***************************************************************/
bool PlayArea::isEmpty(int index)
{
	bool Test(false);
	
	if(m_play[index -1].isEmpty())
	{
		Test = true;
	}

	return Test;
}
/**************************************************************
*   Entry:  int index
*
*    Exit:  none
*
* Purpose: Remove Card From PlayArea index
*
***************************************************************/
Card PlayArea::RemoveCard(int index)
{
	Card topCard;

	if(!m_play[index-1].isEmpty())
	{
		topCard = m_play[index-1].Peek();
		m_play[index-1].Pop();
	}
	else
	{
		throw Exception("invalid move\n");
	}
	
	return topCard;
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: Returns true if card being passed in to the index
*		   is a legal move 
*
***************************************************************/
bool PlayArea::legalMove( Card aCard, int index)
{
	bool test (false);

		if((m_play[index -1].isEmpty())||
		  ( m_play[index-1].Peek().getColor() != aCard.getColor()
		  && m_play[index-1].Peek().getRank() > aCard.getRank()
		  && m_play[index-1].Peek().getRank() < aCard.getRank()+2))
		{
			test = true;
		}

	return test;
}

/**************************************************************
*   Entry:  int index(Array Section moving from)
*
*    Exit:  none
*
* Purpose: Returns the number of open cells, excludes the Array
*		   section being passed in
*
***************************************************************/
int PlayArea::OpenCells(int FromStack)
{
	int count(0);

	for( int i(0); i < 8 ; i++)
	{
		if(m_play[i].isEmpty() && i != FromStack)
		{
			count++;
		}
	}
	
	return count;

}
/**************************************************************
*   Entry:  input Card, and index
*
*    Exit:  none
*
* Purpose: Places a card into the array of the Index
*
***************************************************************/
void PlayArea::PlaceCard( Card aCard, int index)
{
	m_play[index-1].Push(aCard);

}
/**************************************************************
*   Entry:  int index
*
*    Exit:  none
*
* Purpose: returns reference to the top of an array Stack
*
***************************************************************/
Card & PlayArea::Peek(int index)
{
	return m_play[index].Peek();
}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  Used to display the PlayArea of cards to the screen
*
***************************************************************/
void PlayArea::Display()
{
	Array<ListStack<Card>> temp(COLUMNCOUNT);
	int AreaSize(0);
	int largest_stack(0);
	
	for( int i (0); i < COLUMNCOUNT; i++)
	{	
		if(m_play[i].Size() > largest_stack)
		{
			largest_stack = m_play[i].Size();
		}
		for( int j = m_play[i].Size(); j > 0 ; j--)
		{
			temp[i].Push(m_play[i].Peek());
			m_play[i].Pop();
		}
	}
	SetConsoleTextAttribute( handle4, 46);
		cout << "| 1   2   3   4   5   6   7   8  |\n"
			 << "|================================|"<< endl;

	for(int i(0); i < largest_stack; i++)
	{
		SetConsoleTextAttribute( handle4, 46);
		cout << '|';

		for(int j(0); j < COLUMNCOUNT; j++)
		{
			
			if(!temp[j].isEmpty())
			{
			//display top card of stack
				temp[j].Peek().display();
			//copy card back to board
				m_play[j].Push(temp[j].Peek());
				temp[j].Pop();
			}
			else
			{
				cout <<"    ";
			}	
		}
		SetConsoleTextAttribute( handle4, 46);
		cout << '|'<< endl;
		
	}
}