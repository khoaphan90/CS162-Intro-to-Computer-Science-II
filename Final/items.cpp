/*********************************************************************
** Program name: items.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the base class items.
*********************************************************************/
#include "items.hpp"

Items::~Items() { }

/*********************************************************************
** Items::setHave
** Function that sets to see if the user has an item.
*********************************************************************/
void Items::setHave(bool h) { have = h; }

/*********************************************************************
** Items::setHave
** Function that returns the if the user has an item.
*********************************************************************/
bool Items::getHave() const { return have; }

/*********************************************************************
** Items::setHave
** Function that sets the name of the item.
*********************************************************************/
void Items::setName(std::string n) { name = n; }

std::string Items::getName() { return name; }