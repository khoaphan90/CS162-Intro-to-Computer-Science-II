/*********************************************************************
** Program name: menu.cpp for Project 1
** Author: Khoa Phan
** Date: April 12, 2017
** Description: Function program that is used to create a menu that
** will recieve input from the user to choose an option.
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "gameBoard.hpp"
#include "validation.hpp"

using std::cout;
using std::cin;
using std::endl;

bool menu(int input)
{
	GameBoard game;
	switch (input)
	{
	case 1:
		//start program
		game.gameBoard();
		return true;
		break;
	//case 2:
	//	return true;
	//	break;
	//case 3:
	//	return true;
	//	break;
	//case 4:
	//	return true;
	//	break;
	//case 5: //play again
	//	return true;
	//	break;
	case 2: //quit program
		cout << "Thank you for playing." << endl;
		return false;
		break;
	default:
		cout << "Please choose a valid option." << endl;
		return true;
		break;
	}
}