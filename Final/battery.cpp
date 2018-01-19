/*********************************************************************
** Program name: battery.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the derived class 
** battery.
*********************************************************************/
#include <iostream>
#include "battery.hpp"

/*********************************************************************
** Battery::Battery
** Default constructor for battery item.
*********************************************************************/
Battery::Battery()
{
	setIcon();
	name = "DEPLETED BATTERY";
	have = false;
}

/*********************************************************************
** Battery::use
** Function that calls item when user uses interact.
*********************************************************************/
int Battery::use()
{
	std::cout << "Placed [" << name << "] into the slot.\n"
		<< " You remove the [" << name << "].\n" << std::endl;
	return 1;
}

char Battery::getItem() { return item; }