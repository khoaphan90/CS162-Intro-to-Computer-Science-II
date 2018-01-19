/*********************************************************************
** Program name: main.cpp for Lab5
** Author: Khoa Phan
** Date: May 2, 2017
** Description: Main file for 
*********************************************************************/

#include <iostream>
#include "menu.hpp"

using namespace std;

int main()
{
	Menu start;
	bool menuActive = true;

	while (menuActive == true)
	{
		menuActive = start.mainMenu();
	}	

	return 0;
}