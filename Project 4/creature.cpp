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

Creature::~Creature()
{
}

/*********************************************************************
** Creature::getSP
** Function that returns the strength points of the creature.
*********************************************************************/
int Creature::getSP()
{
	return strPt;
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

/*********************************************************************
** Creature::setName
** Function that sets name of the creature.
*********************************************************************/
void Creature::setName()
{
	string input;
	cout << "Enter the name of the creature: ";
	getline(cin, input);
	name = input;
}

/*********************************************************************
** Creature::getName
** Function that gets name of the creature.
*********************************************************************/
string Creature::getName() const
{
	return name;
}