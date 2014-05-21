/****************************************************************
* Author:				Jeff Daniels
* Date Created:				5/01/11
* Last Modification Date:	5/10/11
* Lab Number:			L3_Jeffrey_Daniels
* Filename:				L3_Jeffrey_Daniels
*
* Overview: This program plays the game of Free Cell, it allows
*			all the core componets of the game, but is stream lined
*			for less user input for placing cards 
*
*    Input: keyboard interface
*
*   Output: The program displays  
*		
*****************************************************************/
#include <Windows.h>
#include<iostream>
#include <ctime> 
#include"FreeCellGame.h"

int main()
{
	FreeCellGame aGame;

	aGame.run();
	
	system("pause");
	return 0;
}