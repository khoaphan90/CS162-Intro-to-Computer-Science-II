/*********************************************************************
** Program name: barbarian.hpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Header file for Barbarian class
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "creature.hpp"

class Barbarian : public Creature
{
private:
public:
	Barbarian();
	int attack(); // get attack die and use
	void defend(int); // get defense die and use
protected:
};
#endif
