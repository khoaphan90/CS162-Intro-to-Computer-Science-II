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
	cout << "1. Add a new node to the head;" << endl;
	cout << "2. Add a new node to the tail;" << endl;
	cout << "3. Delete from head;" << endl;
	cout << "4. Delete from tail;" << endl;
	cout << "5. Traverse the list reversely;" << endl;
	cout << "6. Exit;" << endl;
	cout << "\nEnter option: ";
	input = checkInt();

	switch (input)
	{
	case 1:
		return true;
		break;
	case 2:
		return true;
		break;
	case 3:
		return true;
		break;
	case 4:
		return true;
		break;
	case 5:
		return true;
		break;
	case 6:
		return false;
		break;
	default:
		cout << "Please choose a valid option." << endl;
		return true;
		break;
	}
}