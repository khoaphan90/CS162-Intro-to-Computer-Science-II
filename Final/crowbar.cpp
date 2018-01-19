/*********************************************************************
** Program name: crowbar.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the derived class 
** crowbar.
*********************************************************************/
#include <iostream>
#include "crowbar.hpp"

/*********************************************************************
** Crowbar::Crowbar
** Default constructor for crowbar item.
*********************************************************************/
Crowbar::Crowbar()
{
	setIcon();
	name = "CROWBAR";
	have = false;
}

/*********************************************************************
** Crowbar::use
** Function that calls item when user uses interact.
*********************************************************************/
int Crowbar::use()
{
	std::cout << "You swing the crowbar and kill the zombie!" << std::endl;
	return 1;
}

char Crowbar::getItem() { return item; }