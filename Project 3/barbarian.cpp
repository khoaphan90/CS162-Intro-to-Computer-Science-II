/*********************************************************************
** Program name: barbarian.cpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Derived class from the Creature class. It
** holds the unique functions of the Barbarian.
*********************************************************************/

#include <iostream>
#include "barbarian.hpp"
#include "die.hpp"

using namespace std;

/*********************************************************************
** Barbarian::Barbarian
** Default constructor that sets armor and strength point values for
** the class.
*********************************************************************/
Barbarian::Barbarian()
{
	armor = 0;
	strPt = 12;
}

/*********************************************************************
** Barbarian::attack
** Function rolls a die to determine the amount that Barbarian attacks
** for on its turn.
*********************************************************************/
int Barbarian::attack()
{
	// roll die and set amount
	Die a(6);
	int result;
	result = 2 * a.roll();

	// print roll amount for attacker
	cout << "ATTACKS!\nBarbarian attacks for "
		<< result << "!" << endl;

	return result;
}

/*********************************************************************
** Barbarian::defend
** Function that rolls a die to determine the amount that Barbarian
** defends for on its turn and calculates the damage it receives.
*********************************************************************/
void Barbarian::defend(int a)
{
	// roll die and set amount
	Die def(6);
	int d, dr, result;
	dr = 2 * def.roll();
	d = dr + armor;

	// print roll amount for defender
	cout << "\nDEFENDER:\nBarbarian rolls " << d << " and " << "defends for "
		<< dr << "!" << endl << endl;

	//calculate the damage between attack and defend
	result = fight(a, d);

	// update strPt
	strPt -= result;
	cout << cType << " has " << strPt << " strength point(s) left!" << endl;
}