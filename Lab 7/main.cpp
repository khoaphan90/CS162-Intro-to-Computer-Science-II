/*********************************************************************
** Program name: queue.cpp for Lab6
** Author: Khoa Phan
** Date: May 16, 2017
** Description: The main file that holds the struct QueueNode used
** to implement a queue.
*********************************************************************/
#include <iostream>
#include "queue.hpp"
#include "menu.hpp"

using std::cout;
using std::endl;

int main()
{
	Menu start;
	bool isValid = true;

	while(isValid == true)
		isValid = start.mainMenu();

	cout << "Thank you for using this program." << endl;
	return 0;
}