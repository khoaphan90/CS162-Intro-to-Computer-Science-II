/*********************************************************************
** Program name: key.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the class key.
*********************************************************************/
#include <iostream>
#include "key.hpp"

/*********************************************************************
** Key::Key
** Default constructor for key item.
*********************************************************************/
Key::Key()
{
	setIcon();
	name = "KEY";
	have = false;
}

/*********************************************************************
** Key::use
** Function that calls item when user uses interact.
*********************************************************************/
int Key::use()
{
	std::cout << "" << std::endl;
	return 1;
}

char Key::getItem() { return item; }