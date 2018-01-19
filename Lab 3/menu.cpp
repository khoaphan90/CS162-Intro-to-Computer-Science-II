/*********************************************************************
** Program name: menu.cpp for Lab 3
** Author: Khoa Phan
** Date: April 18, 2017
** Description: Function program that is used to create a menu that
** will recieve input from the user to choose an option.
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "validation.hpp"
#include "game.hpp"

using std::cout;
using std::endl;

// menu for input value
bool mainMenu(int input)
{
	switch (input)
	{
	case 1: //start program
		Game();
		return true;
		break;
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