/*********************************************************************
** Program name: blue_Men.cpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Derived class from the Creature class. It
** holds the unique functions of the Blue_Men.
*********************************************************************/

#include <iostream>
#include "blue_men.hpp"
#include "die.hpp"

using namespace std;

/*********************************************************************
** Blue_Men::Blue_Men
** Default constructor that sets armor and strength point values for
** the class.
*********************************************************************/
Blue_Men::Blue_Men()
{
	armor = 3;
	strPt = 12;
}

/*********************************************************************
** Blue_Men::attack
** Function rolls a die to determine the amount that Blue_Men attacks
** for on its turn.
*********************************************************************/
int Blue_Men::attack()
{
	Die a(10);
	int result;
	result = 2 * a.roll();
	cout << "ATTACKs!\nBlue Men attacks for "
		<< result << "!" << endl;
	return result;
}

/*********************************************************************
** Blue_Men::defend
** Function that rolls a die to determine the amount that Barbarian
** defends for on its turn and calculates the damage it receives as
** well as triggering its unique effects.
*********************************************************************/
void Blue_Men::defend(int a)
{
	// roll die and set amount
	Die def(6);
	int d, dr, result;
	int dCount = 0;

	// check existing strPt to determine dCount
	if (strPt <= 12 && strPt >= 9)
		dCount = 3;
	else if (strPt <= 8 && strPt >= 5)
	{
		cout << "Too much damage! Mob decreased by 1.";
		dCount = 2;
	}
	else if (strPt <= 4 && strPt >= 1)
	{
		cout << "Too much damage! Mob decreased by 1.";
		dCount = 1;
	}
	dr = dCount * def.roll();
	d = dr + armor;

	// print roll amount for defender
	cout << "\nDEFENDER:\nBlue Men rolls " << dr << " and " << "defends for "
		<< d << "!" << endl << endl;

	//calculate the damage between attack and defend
	result = fight(a, d);

	// update strPt
	strPt -= result;
	cout << cType << " has " << strPt << " strength point(s) left!" << endl;
}