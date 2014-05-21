#include"FreeCellGame.h"
#include<Windows.h>
#include <ctime>

HANDLE ErrorMsg = GetStdHandle(STD_OUTPUT_HANDLE);
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default constructor for FreeCellGame
*
***************************************************************/
FreeCellGame::FreeCellGame():m_to(0), m_from(0)
{

}
/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:  default destructor for FreeCellGame
*
***************************************************************/
FreeCellGame::~FreeCellGame()
{}
/**************************************************************
*   Entry:  make FreeCellGame passed in equal to FreeCellGame
*			that called it
*
*    Exit:  none
*
* Purpose:  default copy constructor for FreeCellGame
*
***************************************************************/
FreeCellGame::FreeCellGame( const FreeCellGame & copy)
{
	*this = copy;
}
/**************************************************************
*   Entry:  make FreeCellGame on left hand of Equals operator equal
*			to right hand operator
*
*    Exit:  none
*
* Purpose: overloaded equals operator for FreeCellGame
*
***************************************************************/
FreeCellGame & FreeCellGame::operator=( const FreeCellGame & right)
{
	m_card = right.m_card;
	m_to = right.m_to;
	m_from = right.m_from;
	m_gameBoard = right.m_gameBoard;

	return *this;
}

/**************************************************************
*   Entry:  none
*
*    Exit:  after GameBoard.Gameover == true
*
* Purpose: Used to play the Game of Free Cell, Exits after 
*		   HomeCells are filled, Does not account for 
*		   games that cannot be won.
*
***************************************************************/
void FreeCellGame::run()
{
	srand((unsigned)time(0));

	while(m_gameBoard.Gameover() == false)
	{
		try
		{
			m_gameBoard.display();

			m_card= m_gameBoard.moveFrom(m_from);
			m_to = m_gameBoard.moveTo();

			m_gameBoard.move(m_card, m_to, m_from);
			cout << "\n" << endl;
			system("cls");
		}
		catch(Exception & msg)
		{	
			SetConsoleTextAttribute( ErrorMsg, 12);
			COORD cur_pos;
			cur_pos.X = 0;
			cur_pos.Y = 15;
			SetConsoleCursorPosition(ErrorMsg, cur_pos);
			cout << msg << endl;
			system("pause");
		}

	}

	m_gameBoard.display();
	cout << "\n\nWINNER" << endl;
}