/*********************************************************************
** Program name: harry_potter.cpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Derived class from the Creature class. It
** holds the unique functions of the Harry_Potter.
*********************************************************************/

#include <iostream>
#include "harry_potter.hpp"
#include "die.hpp"

using namespace std;

/*********************************************************************
** Harry_Potter::Harry_Potter
** Default constructor that sets armor and strength point values for
** the class.
*********************************************************************/
Harry_Potter::Harry_Potter()
{
	armor = 0;
	strPt = 10;
}

/*********************************************************************
** Harry_Potter::attack
** Function rolls a die to determine the amount that Harry_Potter 
** attacks for on its turn.
*********************************************************************/
int Harry_Potter::attack()
{
	Die a(6);
	int result;
	result = 2 * a.roll();

	cout << "ATTACKs!\n(" << cType << ") " << name
		<< " attacks for " << result << "!" << endl;

	return result;
}

/*********************************************************************
** Harry_Potter::defend
** Function that rolls a die to determine the amount that Barbarian
** defends for on its turn and calculates the damage it receives as
** well as triggering its unique effects.
*********************************************************************/
void Harry_Potter::defend(int a)
{
	// roll die and set amount
	Die def(6);
	int d, dr, result;
	dr = 2 * def.roll();
	d = dr + armor;

	// print roll amount for defender
	cout << "\nDEFENDER:\n(" << cType << ") " << name << " rolls "
		<< dr << " and " << "defends for "
		<< d << "!" << endl << endl;

	//calculate the damage between attack and defend
	result = fight(a, d);

	// update strPt
	strPt -= result;
	cout << "(" << cType << ") " << name << " has " 
		<< strPt << " strength point(s) left!" << endl;

	// when strPt = 0, check for hogwarts ability
	if (strPt <= 0)
	{
		if (life == 1)
		{
			cout << "(" << cType << ") " << name
				<< " activated his Hogwarts ability!"
				<< endl;
			strPt = 20;
			life = 0;
		}
		else
			cout << "(" << cType << ") " << name
			<< "'s Hogwarts ability"
			<< " has run out!" << endl;
	}
}

/*********************************************************************
** Harry_Potter::restore
** Function that restores strength points if returned to queue.
*********************************************************************/
void Harry_Potter::restore()
{
	if (life == 0)
	{
		cout << getName() << " recharges his Hogwarts ability!" 
			<< endl;
		life = 1;
	}
	else if (strPt <= 8)
	{
		int modifier;
		cout << getName() << " has a memory flashback of his parents!" 
			<< endl;
		modifier = (10 - strPt) + 1;
		strPt += modifier;
		cout << "Strength Points increased by "
			<< modifier << "." << endl;
	}
}