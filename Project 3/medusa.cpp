/*********************************************************************
** Program name: medusa.cpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Derived class from the Creature class. It
** holds the unique functions of the Medusa.
*********************************************************************/

#include <iostream>
#include "medusa.hpp"
#include "die.hpp"

using namespace std;

/*********************************************************************
** Medusa::Barbarian
** Default constructor that sets armor and strength point values for
** the class.
*********************************************************************/
Medusa::Medusa()
{
	armor = 3;
	strPt = 8;
}

/*********************************************************************
** Medusa::attack
** Function rolls a die to determine the amount that Medusa attacks
** for on its turn  as
** well as triggering its unique effects.
*********************************************************************/
int Medusa::attack()
{
	// roll die and set amount
	Die a(6);
	int result;
	result = 2 * a.roll();

	// check for roll of 12, GLARE activates on this
	if (result == 12)
	{
		cout << "ATTACKs!\nMedusa uses Glare! Enemy turns to stone!" << endl;
		result = 100;
	}

	// print roll amount for attacker
	else if (!(result == 12))
		cout << "ATTACKS!\nMedusa attacks for " 
		<< result << "!" << endl;

	return result;
}

/*********************************************************************
** Medusa::defend
** Function that rolls a die to determine the amount that Barbarian
** defends for on its turn and calculates the damage it receives.
*********************************************************************/
void Medusa::defend(int a)
{
	// roll die and set amount
	Die def(6);
	int d, dr, result;
	dr = def.roll();
	d = dr + armor;
	

	// print roll amount for defender
	cout << "\nDEFENDER:\nMedusa rolls " << dr << " and " << "defends for "
		<< d << "!" << endl << endl;

	//calculate the damage between attack and defend
	result = fight(a, d);

	// update strPt
	strPt -= result;
	cout << cType << " has " << strPt << " strength point(s) left!" << endl;
}