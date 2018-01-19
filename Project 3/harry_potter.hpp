/*********************************************************************
** Program name: harry_potter.hpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Header file for Harry Potter class
*********************************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP
#include "creature.hpp"

class Harry_Potter : public Creature
{
private:
	int life = 1;
public:
	Harry_Potter();
	int attack(); // get attack die and use
	void defend(int); // get defense die and use
protected:
};
#endif
