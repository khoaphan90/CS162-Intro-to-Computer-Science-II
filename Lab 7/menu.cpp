/*********************************************************************
** Program name: menu.cpp for Lab7
** Author: Khoa Phan
** Date: May 16, 2017
** Description: Function program that is used to create a menu that
** will receive input from the user to choose options.
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "validation.hpp"
#include "queue.hpp"

using std::cout;
using std::cin;
using std::endl;

Queue q;

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
	cout << "1. Enter a value to be added to the queue." << endl;
	cout << "2. Display first node (front) value." << endl;
	cout << "3. Remove first node (front) value." << endl;
	cout << "4. Display queue contents." << endl;
	cout << "5. Exit;" << endl;
	cout << "\nEnter option: ";
	input = checkInt();

	switch (input)
	{
	case 1:
		// prompt user enter info
		int number;
		cout << "Please enter a positive integer." << endl;
		number = checkInt();
		q.addBack(number);
		return true;
		break; 
	case 2:
		q.getFront();
		return true;
		break;
	case 3:
		q.removeFront();
		return true;
		break;
	case 4:
		q.displayContents();
		return true;
		break;
	case 5:
		return false;
		break;
	default:
		cout << "Please choose a valid option." << endl;
		return true;
		break;
	}
}