/*********************************************************************
** Program name: medusa.hpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Header file for Medusa class.
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "creature.hpp"

class Medusa : public Creature
{
private:
	string type = "Medusa";
public:
	Medusa();
	int attack(); // get attack die and use
	void defend(int); // get defense die and use
	void restore();
protected:
};
#endif