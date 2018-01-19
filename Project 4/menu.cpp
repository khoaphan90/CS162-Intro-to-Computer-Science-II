/*********************************************************************
** Program name: menu.cpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Function program that is used to create a menu that
** will receive input from the user to choose options.
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "validation.hpp"

using std::cout;
using std::endl;

Game a;

/*********************************************************************
** Menu::mainMenu
** Function that displays options list.
*********************************************************************/
bool Menu::mainMenu()
{
	int input;

	cout << "----Main Menu----"
		<< endl << endl;
	cout << "Please choose an option." << endl;
	cout << "1. Start Game" << endl;
	cout << "2. Exit" << endl;
	cout << "\nEnter option: ";
	input = checkInt();

	switch (input)
	{
	case 1: //start program
		return a.playGame();
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

/*********************************************************************
** Menu::typeMenu
** Displays creature types that are available and returns the type to
** be used.
*********************************************************************/
TYPE Menu::typeMenu()
{
	int input;

	cin.clear();

	cout << "\n----Creatures----"
		<< endl << endl;
	cout << "Please choose a creature." << endl;
	cout << "1. Vampire" << endl;
	cout << "2. Barbarian" << endl;
	cout << "3. Blue Men" << endl;
	cout << "4. Medusa" << endl;
	cout << "5. Harry Potter" << endl;
	cout << "\nEnter option: ";
	input = checkRange();

	switch (input)
	{
	case 1:
	{
		return VAMPIRE;
		break;
	}
	case 2:
	{
		return BARBARIAN;
		break;
	}
	case 3:
	{
		return BLUE_MEN;
		break;
	}
	case 4:
	{
		return MEDUSA;
		break;
	}
	case 5:
	{
		return HARRY_POTTER;
		break;
	}
	default:
	{
		cout << "Please choose a valid option." << endl;
		break;
	}
	}
	return EMPTY;
}