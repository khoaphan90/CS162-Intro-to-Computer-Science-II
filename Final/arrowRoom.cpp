/*********************************************************************
** Program name: arrowRoom.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the derived class 
** arrowRoom.
*********************************************************************/
#include <iostream>
#include "arrowRoom.hpp"
#include "wrench.hpp"

/*********************************************************************
** ArrowRoom::ArrowRoom
** Default constructor class that generates walls and creates items.
*********************************************************************/
ArrowRoom::ArrowRoom(Player* player)
{
	// create new arrows and wrench
	for (int i = 0; i < 4; i++)
		aList.push_back(new Arrow);
	wrench = new Wrench;

	// set player
	p = player;

	// vertical walls
	for (int i = 0; i < 6; i++) map[i][0] = '#';
	for (int i = 9; i < 15; i++) map[i][0] = '#';
	for (int i = 0; i < 6; i++) map[i][1] = '#';
	for (int i = 9; i < 15; i++) map[i][1] = '#';
	for (int i = 0; i < 6; i++) map[i][2] = '#';
	for (int i = 9; i < 15; i++) map[i][2] = '#';
	for (int i = 0; i < 10; i++) map[i][6] = '#';
	for (int i = 12; i < 15; i++) map[i][6] = '#';
	for (int i = 0; i < 10; i++) map[i][10] = '#';
	for (int i = 12; i < 15; i++) map[i][10] = '#';
	for (int i = 0; i < 10; i++) map[i][11] = '#';
	for (int i = 12; i < 15; i++) map[i][11] = '#';
	for (int i = 0; i < 10; i++) map[i][12] = '#';
	for (int i = 12; i < 15; i++) map[i][12] = '#';
	for (int i = 0; i < 10; i++) map[i][13] = '#';
	for (int i = 12; i < 15; i++) map[i][13] = '#';
	for (int i = 0; i < 4; i++) map[i][18] = '#';
	for (int i = 8; i < 15; i++) map[i][18] = '#';
	for (int i = 0; i < 10; i++) map[i][22] = '#';
	for (int i = 13; i < 15; i++) map[i][22] = '#';
	for (int i = 0; i < 10; i++) map[i][23] = '#';
	for (int i = 13; i < 15; i++) map[i][23] = '#';
	for (int i = 0; i < 10; i++) map[i][24] = '#';
	for (int i = 13; i < 15; i++) map[i][24] = '#';
	for (int i = 0; i < 10; i++) map[i][25] = '#';
	for (int i = 13; i < 15; i++) map[i][25] = '#';

	setComponents();
}

/*********************************************************************
** ArrowRoom::~ArrowRoom
** Function that deallocates the created items.
*********************************************************************/
ArrowRoom::~ArrowRoom()
{
	for (int i = 0; i < rows; i++)
		delete[] map[i];
	delete[] map;
	map = NULL;

	for (int i = 0; i < 4; i++)
		delete aList[i];
	delete wrench;
	wrench = 0;
}

/*********************************************************************
** ArrowRoom::printMessage
** Function that prints out information for user about the room.
*********************************************************************/
void ArrowRoom::printMessage()
{
	std::cout << "  These arrows can really hurt.\n"
		<< "  Maybe we can disable them.\n";
}

/*********************************************************************
** ArrowRoom::interact
** Function that allows user to interact with objects
*********************************************************************/
void ArrowRoom::interact()
{
	// check if wrench exist near user
	if (map != 0)
	{
		if ((pNorth == 'W') || (pEast == 'W') || (pSouth == 'W') || (pWest == 'W'))
		{
			std::cout << "    You picked up a [" << wrench->getName() 
				<< "].\n    This might be useful.\n\n";
			{
				wrench->setHave(true);
				p->addInventory(wrench);
			}
			// remove wrench from ground
			map[1][28] = 0;
		}
		// checks if arrow machine is near user
		if ((pNorth == 'A') || (pEast == 'A') || (pSouth == 'A' || (pWest == 'A')))
			//use wrench to destroy machines
			if (wrench->getHave() == true)
			{
				machines -= wrench->use();
				if ((p->getX() == 3) || (p->getX() == 5))
					aList[0]->exist = destroyMachine(aList[0]);
				if ((p->getX() == 7) || (p->getX() == 9))
					aList[1]->exist = destroyMachine(aList[1]);
				if ((p->getX() == 15) || (p->getX() == 17))
					aList[2]->exist = destroyMachine(aList[2]);
				if ((p->getX() == 19) || (p->getX() == 21))
					aList[3]->exist = destroyMachine(aList[3]);
			}
			else
				std::cout << "   Can't do anything by hand.\n"
					<< "   Maybe there is something \n"
					<< "        we can use...\n" << std::endl;
		// unlock doors if all machines are destroyed
		if (machines == 0)
		{
			dWest.locked = false;
			map[(rows / 2)][0] = 0;
			std::cout << "  An audible clicking is heard \n"
				<< "    in the other room...\n\n";
			dWest.roomPtr->setSpikeLock(false);
		}
	}
}

/*********************************************************************
** ArrowRoom::setComponents
** Function that sets any objects needed to complete room puzzle.
*********************************************************************/
void ArrowRoom::setComponents()
{
	// arrow machine locations
	aList[0]->aY = 1; aList[0]->aX = 4;
	aList[1]->aY = 13; aList[1]->aX = 8;
	aList[2]->aY = 1; aList[2]->aX = 16;
	aList[3]->aY = 13; aList[3]->aX = 20;

	// set block location
	map[0][aList[0]->aX] = aList[0]->block;
	map[14][aList[1]->aX] = aList[1]->block;
	map[0][aList[2]->aX] = aList[2]->block;
	map[14][aList[3]->aX] = aList[3]->block;

	// wrench location
	map[1][28] = wrench->getItem();
}

/*********************************************************************
** ArrowRoom::createDoors
** Function that creates the set of doors for the room.
*********************************************************************/
void ArrowRoom::createDoors()
{
	std::cout << "\nThe door locks behind you.\n";
	map[(rows / 2)][0] = '|';
	map[(rows / 2) + 1][0] = '+';
	map[(rows / 2) - 1][0] = '+';
}

/*********************************************************************
** ArrowRoom::setConnectedRooms
** Function that sets the connecting rooms to this room.
*********************************************************************/
void ArrowRoom::setConnectedRooms(Room *n, Room *e, Room *s, Room *w)
{
	dNorth.roomPtr = 0;
	dEast.roomPtr = 0;
	dSouth.roomPtr = 0;
	dWest.roomPtr = w;
}

/*********************************************************************
** ArrowRoom::action
** Function that calls any actions that the room has.
*********************************************************************/
void ArrowRoom::action()
{
	// first row of arrows
	if (aList[0]->exist == true)
		shootArrowsDown(aList[0]->aX, aList[0]->aY, 1);
	takeDamage(aList[0]->aX, aList[0]->aY, 1);

	// second row of arrows
	if (aList[1]->exist == true)
		shootArrowsUp(aList[1]->aX, aList[1]->aY, 13);
	takeDamage(aList[1]->aX, aList[1]->aY, 13);

	// third row of arrows
	if (aList[2]->exist == true)
		shootArrowsDown(aList[2]->aX, aList[2]->aY, 1);
	takeDamage(aList[2]->aX, aList[2]->aY, 1);

	// fourth row of arrows
	if (aList[3]->exist == true)
		shootArrowsUp(aList[3]->aX, aList[3]->aY, 13);
	takeDamage(aList[3]->aX, aList[3]->aY, 13);
}

/*********************************************************************
** ArrowRoom::destroyMachine
** Function that destroys the arrow machines if user interacts.
*********************************************************************/
bool ArrowRoom::destroyMachine(Arrow *a)
{
	// destroy machine
	if (pEast == a->block)
	{
		map[p->getY()][p->getX() + 1] = 0;
		for (int i = 0; i < 15; i++)
			map[i][a->aX] = 0;
		a->exist = false;
		return false;
	}
	else if (pWest == a->block)
	{
		map[p->getY()][p->getX() - 1] = 0;
		for (int i = 0; i < 15; i++)
			map[i][a->aX] = 0;
		a->exist = false;
		return false;
	}
	else
		return true;
}

/*********************************************************************
** ArrowRoom::shootArrowsDown
** Function handles arrows that shoot down.
*********************************************************************/
void ArrowRoom::shootArrowsDown(int x, int &y, int reset)
{
	// create arrows in linear direction
	if (y < rows - 1)
	{
		if (map[y + 1][x] == 0)
		{
			map[y + 1][x] = '|';
			map[y][x] = 0;
			y += 1;
		}
	}
	else
	{
		map[y][x] = 0;
		y = reset;
	}
}

/*********************************************************************
** ArrowRoom::shootArrowsUp
** Function handles arrows that shoot up.
*********************************************************************/
void ArrowRoom::shootArrowsUp(int x, int &y, int reset)
{
	// create arrows in linear direction
	if (y > 0)
	{
		if (map[y - 1][x] == 0)
		{
			map[y - 1][x] = '|';
			map[y][x] = 0;
			y -= 1;
		}
	}
	else
	{
		map[y][x] = 0;
		y = reset;
	}
}

/*********************************************************************
** ArrowRoom::takeDamage
** Function that reduces user energy if an arrow strikes them.
*********************************************************************/
void ArrowRoom::takeDamage(int x, int &y, int reset)
{
	// checks arrow location to user
	if (((p->getY() - 1 == y) && (p->getX() == x)) ||
		((p->getY() + 1 == y) && (p->getX() == x)))
	{
		std::cout << "You've been hit by an arrow...\n"
			<< "Your energy has been reduced.\n" << std::endl;

		// reduce energy
		p->setStepCount((p->getStepCount() / 3) * 2);

		// shoot new arrow if user is hit
		map[y][x] = 0;
		y = reset;
	}
}