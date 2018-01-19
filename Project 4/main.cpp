/*********************************************************************
** Program name: main.cpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: These is the code written to start the operating
** program.
*********************************************************************/

#include <iostream>
#include "game.hpp"
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// call class variables to start
	Menu start;
	bool menuValid = true;

	// loop to continue until user declines to continue
	while ( menuValid == true)
		menuValid = start.mainMenu();
	
	return 0;
}