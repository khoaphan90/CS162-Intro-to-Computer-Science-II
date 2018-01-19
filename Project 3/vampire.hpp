/*********************************************************************
** Program name: vampire.hpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Header file for Vampire class
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "creature.hpp"

class Vampire : public Creature
{
private:
public:
	Vampire();
	int attack(); // get attack die and use
	void defend(int); // get defense die and use
protected:
};
#endif
