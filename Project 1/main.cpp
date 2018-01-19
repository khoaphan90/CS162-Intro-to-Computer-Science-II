/*********************************************************************
** Program name: main.cpp for Project 1
** Author: Khoa Phan
** Date: April 12, 2017
** Description: Main program file for the Langston's Ant Program
** that welcomes and calls the menu class, prompting the user to
** choose an option.
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "ant.hpp"
#include "gameBoard.hpp"
#include "validation.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int input;
	bool active = true;

	do
	{
		cout << "Welcome the Langton's Ant program." << endl << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. Start" << endl;
		//cout << "2. NULL" << endl;
		//cout << "3. NULL" << endl;
		//cout << "4. NULL" << endl;
		//cout << "5. Play again" << endl;
		cout << "2. Quit" << endl;
		input = validOption();
		active = menu(input);
	} while (active == true);

	return 0;
}