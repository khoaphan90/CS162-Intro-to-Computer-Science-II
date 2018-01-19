/*********************************************************************
** Program name: validation.cpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Creature is an abstract class that holds the
** functions of all relatable creature features.
*********************************************************************/

#include <iostream>
#include "creature.hpp"

using namespace std;

/*********************************************************************
** Creature::getSP
** Function that returns the strength points of the creature.
*********************************************************************/
int Creature::getSP()
{
	return strPt;
}

/*********************************************************************
** Creature::setType
** Function that sets the class type the creature is.
*********************************************************************/
void Creature::setType(string n)
{
	cType = n;
}

/*********************************************************************
** Creature::getType
** Function that returns a string to the type of creature that is 
** called.
*********************************************************************/
string Creature::getType()
{
	return cType;
}

/*********************************************************************
** Creature::setPosition
** Function that sets the position the creature is in, either 
** ATTACK or DEFEND.
*********************************************************************/
void Creature::setPosition(POSITION p)
{
	cPos = p;
}

/*********************************************************************
** Creature::getPosition
** Function that returns which position the creature is in.
*********************************************************************/
int Creature::getPosition()
{
	return cPos;
}

/*********************************************************************
** Creature::fight
** Function that calculates the results between two creatures 
** fighting, one attacking and one defending.
*********************************************************************/
int Creature::fight(int a, int d)
{
	// variable initialization
	int x = 0;

	// attack roll higher than defend roll
	if (a > d)
	{
		x = a - d;
		cout << cType << " takes " << x
			<< " damage!" << endl;
	}
	// defend roll higher than attack roll
	else if (a <= d)
	{
		cout << cType << " defends entire attack!"
			<< "\nNo damage done." << endl;
		x = 0;
	}

	return x;
}