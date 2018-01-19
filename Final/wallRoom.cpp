/*********************************************************************
** Program name: wallRoom.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the derived
** class wallRoom.
*********************************************************************/
#include <iostream>
#include "wallRoom.hpp"

/*********************************************************************
** WallRoom::WallRoom
** Default constructor class that generates walls and creates items.
*********************************************************************/
WallRoom::WallRoom(Player *player)
{
	p = player;
	setComponents();
}

/*********************************************************************
** WallRoom::~WallRoom
** Destructor for created items, maps
*********************************************************************/
WallRoom::~WallRoom()
{
	for (int i = 0; i < rows; i++)
		delete[] map[i];
	delete[] map;
	map = NULL;
}

/*********************************************************************
** WallRoom::printMessage
** Function that prints out information for user about the room.
*********************************************************************/
void WallRoom::printMessage()
{
	std::cout << "The doors slam shut behind you!"
		<< "\nThese walls are a bit different."
		<< "\nSomething doesn't feel right...\n\n";
}

/*********************************************************************
** WallRoom::interact
** Function that allows user to interact with objects
*********************************************************************/
void WallRoom::interact() { }

/*********************************************************************
** ArrowRoom::setComponents
** Function that sets any objects needed to complete room puzzle.
*********************************************************************/
void WallRoom::setComponents()
{
	// draw left wall
	for (int i = 0; i < 15; i++) 
		map[i][0] = wall;

	// draw right wall
	for (int i = 0; i < 15; i++)
		map[i][29] = wall;
}

/*********************************************************************
** WallRoom::createDoors
** Function that creates the set of doors for the room.
*********************************************************************/
void WallRoom::createDoors()
{
	// north doors
	map[0][(cols / 2) + 1] = '+';
	map[0][(cols / 2) - 2] = '+';

	// south doors
	map[rows - 1][(cols / 2) + 1] = '+';
	map[rows - 1][(cols / 2) - 2] = '+';
	map[14][14] = '-';
	map[14][15] = '-';
}

/*********************************************************************
** WallRoom::setConnectedRooms
** Function that sets the connecting rooms to this room.
*********************************************************************/
void WallRoom::setConnectedRooms(Room *n, Room *e, Room *s, Room *w)
{
	dNorth.roomPtr = 0;
	dEast.roomPtr = 0;
	dSouth.roomPtr = s;
	dWest.roomPtr = 0;
}

/*********************************************************************
** WallRoom::action
** Function that calls any actions that the room has.
*********************************************************************/
void WallRoom::action()
{
	std::cout << "The walls are closing in!! RUN!!\n\n";
	// move walls
	for (int i = 0; i < 15; i++)
	{
		map[i][moveRight] = wall;
		map[i][moveLeft] = wall;
	}

	moveRight++;
	moveLeft--;

	// see if walls closed in on user
	if ((map[p->getY()][p->getX() + 1] == wall) &&
		(map[p->getY()][p->getX() - 1] == wall))
	{
		std::cout << "You have been crushed...\n";
		p->setStepCount(0);
	}
	if ((map[p->getY()][p->getX()] == map[0][14]) ||
		(map[p->getY()][p->getX()] == map[0][15]))
	{
		p->setEscape(true);
		escape = true;
	}
}
