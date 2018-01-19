/*********************************************************************
** Program name: blue_men.hpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Header file for Blue_Men class
*********************************************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP
#include "creature.hpp"

class Blue_Men : public Creature
{
private:
	string type = "Blue Men";
public:
	Blue_Men();
	int attack(); // get attack die and use
	void defend(int); // get defense die and use
	void restore();
protected:
};
#endif
