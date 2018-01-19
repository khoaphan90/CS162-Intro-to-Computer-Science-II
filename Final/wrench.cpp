/*********************************************************************
** Program name: wrench.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the derived 
** class wrench.
*********************************************************************/
#include <iostream>
#include "wrench.hpp"

/*********************************************************************
** Wrench::Wrench
** Default constructor for wrench item.
*********************************************************************/
Wrench::Wrench()
{
	setIcon();
	name = "WRENCH";
	have = false;
}

/*********************************************************************
** Wrench::use
** Function that calls item when user uses interact.
*********************************************************************/
int Wrench::use()
{
	std::cout << "   You loosen a bolt and the\n"
		<< "    machine falls apart.\n\n";
	return 1;
}

char Wrench::getItem() { return item; }