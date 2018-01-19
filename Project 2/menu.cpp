/*********************************************************************
** Program name: menu.cpp for Project2
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Function program that is used to create a menu that
** will receive input from the user to choose options.
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "list.hpp"
#include "item.hpp"
#include "validation.hpp"

using std::cout;
using std::endl;


/*********************************************************************
** Menu::mainMenu
** Function that displays options list.
*********************************************************************/
bool Menu::mainMenu(List &a)
{
	int input;

	cout << "----Main Menu----"
		<< endl << endl;
	cout << "Please choose an option." << endl;
	cout << "1. Add/remove item" << endl;
	cout << "2. Display list" << endl;
	cout << "3. Exit" << endl;
	cout << "\nEnter option: ";
	input = checkInt();

	switch (input)
	{
	case 1: //start program
			//Modify sub: List, Item.
		modifyMenu(a);
		return true;
		break;
	case 2: //start program
			//Display, sub: List, Item.
		displayMenu(a);
		return true;
		break;
	case 3: //quit program
		cout << "Thank you for using this program." << endl;
		return false;
		break;
	default:
		cout << "Please choose a valid option." << endl;
		return true;
		break;
	}
}

/*********************************************************************
** Menu::mainMenu
** Displays list options for display type.
*********************************************************************/
void Menu::displayMenu(List &a)
{
	int input, itemSelect;
	bool hasItem = false;

	cout << "\n----Display Menu----"
		<< endl << endl;
	cout << "Please choose an option." << endl;
	cout << "1. Item" << endl;
	cout << "2. List" << endl;
	cout << "3. Go Back" << endl;
	cout << "\nEnter option: ";
	input = checkInt();

	switch (input)
	{
	case 1: //start program
			//display item

		cout << "\n----Item List.----" << endl;
		hasItem = a.itemListMenu();
		if (hasItem == true)
		{
			// call for user option
			cout << "\nEnter option: ";
			itemSelect = checkInt();

			// display option
			displayItem(a, itemSelect);
		}
		break;
	case 2:
			//display list
		a.displayList();
		break;
	case 3: //go back
		break;
	default:
		cout << "Please choose a valid option." << endl;
		break;
	}
}

/*********************************************************************
** Menu::modifyMenu
** Function that displays options for modifying the list.
*********************************************************************/
void Menu::modifyMenu(List &a)
{
	int input, itemSelect;
	bool hasItem = false;

	cout << "\n----Modify Menu----"
		<< endl << endl;
	cout << "Please choose an option." << endl;
	cout << "1. Add item" << endl;
	cout << "2. Remove item" << endl;
	cout << "3. Go Back" << endl;
	cout << "\nEnter option: ";
	input = checkInt();

	switch (input)
	{
	case 1: 
		a.addItem();
		break;
	case 2: 
		cout << "\n----Item List.----" << endl;
		hasItem = a.itemListMenu();
		if (hasItem == true)
		{
			// as user for choice
			cout << "\nEnter option: ";
			itemSelect = checkInt();
			// remove user choice
			a.removeItem(itemSelect);
		}
		break;
	case 3: //go back
		break;
	default:
		cout << "Please choose a valid option." << endl;
		break;
	}
}

/*********************************************************************
** Menu::displayItem
** Function that displays item.
*********************************************************************/
void Menu::displayItem(List &a, int item)
{
	cout << endl;
	a.displayItem(item);
	cout << endl;
}