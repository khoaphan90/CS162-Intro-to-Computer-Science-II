/*********************************************************************
** Program name: vampire.cpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Derived class from the Creature class. It
** holds the unique functions of the Vampire.
*********************************************************************/

#include <iostream>
#include "vampire.hpp"
#include "die.hpp"

using namespace std;

/*********************************************************************
** Vampire::Vampire
** Default constructor that sets armor and strength point values for
** the class.
*********************************************************************/
Vampire::Vampire()
{
	armor = 1;
	strPt = 18;
}

/*********************************************************************
** Vampire::attack
** Function rolls a die to determine the amount that Vampire attacks
** for on its turn.
*********************************************************************/
int Vampire::attack()
{
	// roll die and set amount
	Die a(12);
	int result;
	result = a.roll();

	// print roll amount for attacker
	cout << "ATTACKS!\n(" << cType << ") " << name
		<< " attacks for " << result << "!" << endl;

	return result;
}

/*********************************************************************
** Vampire::defend
** Function that rolls a die to determine the amount that Barbarian
** defends for on its turn and calculates the damage it receives as
** well as triggering its unique effects.
*********************************************************************/
void Vampire::defend(int a)
{
	// roll die and set amount
	Die def(6);
	int d, dr, result = 0;
	dr = 2 * def.roll();
	d = dr + armor;

	// random 50/50 chance variable
	int i = rand() % 2;

	// calls charm ability
	if (i == 0)
	{
		a = 0;
		cout << "\nDEFENDER:\n(" << cType << ") " << name
			<< " uses charm! Attack stopped.\n\n";
	}

	// print roll amount for defender
	else if ( i != 0)
		cout << "\nDEFENDER:\n(" << cType << ") " << name
		<< " rolls " << dr << " and " << "defends for "
		<< d << "!" << endl << endl;

	//calculate the damage between attack and defend
	result = fight(a, d);

	// update strPt
	strPt -= result;
	cout << "(" <<  cType << ") " << name
		<< " has " << strPt 
		<< " strength point(s) left!" << endl;
}

/*********************************************************************
** Vampire::restore
** Function that restores strength points if returned to queue.
*********************************************************************/
void Vampire::restore()
{
	if (strPt < 18)
	{
		int modifier;
		cout << getName() << " draws blood from the defeated victim!"
			<< endl;
		modifier = (18 - strPt) / 2;
		strPt += modifier;
		cout << "Strength Points increased by "
			<< modifier << "." << endl;
	}
}