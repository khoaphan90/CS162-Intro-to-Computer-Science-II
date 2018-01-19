/*********************************************************************
** Program name: room.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the base class room.
*********************************************************************/
#include <iostream>
#include "room.hpp"
#include "validation.hpp"

/*********************************************************************
** Room::Room
** Default constructor intializes map size and map border.
*********************************************************************/
Room::Room()
{
	rows = 15;
	cols = 30;

	map = new char*[rows];
	for (int i = 0; i < rows; i++)
		map[i] = new char[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			map[i][j] = 0;
}

Room::~Room()
{
}

Room::Room(Player* player)
{
	for (int i = 0; i < rows; i++)
		delete[] map[i];
	delete[] map;
	map = NULL;
}

void Room::setPlayer(Player *player) { p = player; }
Player* Room::getPlayer() { return p; }
int Room::getRows() { return rows; }
int Room::getCols() { return cols; }
Room* Room::getRoom() const { return currentRoom; }
void Room::setPowerStatus(bool a) { powerStatus = a; }
void Room::setSpikeLock(bool a) { spikeLock = a; }
void Room::setZombieLock(bool a) { zombieLock = a; }
void Room::printMessage() {}
void Room::interact() {}

/*********************************************************************
** Room::setPNorth
** Function that sets the user's north space
*********************************************************************/
void Room::setPNorth()
{
	// check to see if out of bounds, set surrounding
	if (p->getY() - 1 >= 0)
		pNorth = map[p->getY() - 1][p->getX()];
}

/*********************************************************************
** Room::setPEast
** Function that sets the user's east space
*********************************************************************/
void Room::setPEast()
{
	// check to see if out of bounds, set surrounding
	if (p->getX() + 1 <= (cols - 1))
		pEast = map[p->getY()][p->getX() + 1];
}

/*********************************************************************
** Room::setPSouth
** Function that sets the user's south space
*********************************************************************/
void Room::setPSouth()
{
	// check to see if out of bounds, set surrounding
	if (p->getY() + 1 <= (rows - 1))
		pSouth = map[p->getY() + 1][p->getX()];
}

/*********************************************************************
** Room::setPWest
** Function that sets the user's west space
*********************************************************************/
void Room::setPWest()
{
	// check to see if out of bounds, set surrounding
	if (p->getX() - 1 >= 0)
		pWest = map[p->getY()][p->getX() - 1];
}

/*********************************************************************
** Room::printRoom
** Function that prints out the game map
*********************************************************************/
void Room::printRoom()
{
	map[p->getY()][p->getX()] = p->getIcon();

	//creates top and bottom border
	std::cout << "#";
	for (int i = 0; i < rows; i++)
		std::cout << "##";
	std::cout << "#" << std::endl;

	for (int i = 0; i < rows; i++)
	{
		std::cout << "#";
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] == 0)
				std::cout << ' ';
			else
				std::cout << map[i][j];
		}
		std::cout << "#\n";
	}

	std::cout << "#";
	for (int i = 0; i < rows; i++)
		std::cout << "##";
	std::cout << "#" << std::endl;
	std::cout << "--------------------------------\n";
	printMessage();
	std::cout << "--------------------------------\n";
}

/*********************************************************************
** Room::setRoom
** Function that sets the current room that the user is in
*********************************************************************/
void Room::setRoom(Room *r) 
{ 
	createDoors(); 
	currentRoom = r; 
}

/*********************************************************************
** Room::control
** Function that controls the users movement and actions.
*********************************************************************/
void Room::control()
{
	map[p->getY()][p->getX()] = p->getIcon();

	setPNorth();
	setPEast();
	setPSouth();
	setPWest();

	char input;
	//input = checkChar();
	std::cin >> input;

	// "clear" screen
	for (int j = 0; j < 500; j++)
		std::cout << std::endl;

	switch (toupper(input))
	{
	case 'W':
		// check out of bounds
		if (p->getY() > 0)
		{
			// check if next UP is 0, if not, do nothing
			if (map[p->getY() - 1][p->getX()] == 0)
			{
				map[p->getY() -1][p->getX()] = p->getIcon();
				map[p->getY()][p->getX()] = 0;
				p->setY(p->getY() - 1);
			}
		}
		if ((p->getY() == 1 && p->getX() == (cols / 2)) ||
			(p->getY() == 1 && p->getX() == ((cols / 2) - 1)))
			if (map[p->getY()-1][p->getX()] == '.')
				if (dNorth.locked == true)
					std::cout << "This door is locked!" << std::endl;
		break;
	case 'D':
		// check out of bounds
		if (p->getX() < cols - 1)
		{
			// check if next UP is 0, if not, do nothing
			if (map[p->getY()][p->getX() + 1] == 0)
			{
				map[p->getY()][p->getX() + 1] = p->getIcon();
				map[p->getY()][p->getX()] = 0;
				p->setX(p->getX() + 1);
			}
		}
		if ((p->getY() == (rows / 2)) && (p->getX() == (cols - 2)))
			if (map[p->getY()][p->getX() + 1] == '.')
				if (dEast.locked == true)
					std::cout << "This door is locked!" << std::endl;
		break;
	case 'A':
		// check out of bounds
		if (p->getX() > 0)
		{
			// check if next UP is 0, if not, do nothing
			if (map[p->getY()][p->getX() - 1] == 0)
			{
				map[p->getY()][p->getX() - 1] = p->getIcon();
				map[p->getY()][p->getX()] = 0;
				p->setX(p->getX() - 1);
			}
		}
		if ((p->getY() == (rows / 2)) && (p->getX() == 1))
			if (map[p->getY()][p->getX() - 1] == '.')	
				if (dWest.locked == true)
					std::cout << "This door is locked!" << std::endl;
		break;

	case 'S':
		// check out of bounds
		if (p->getY() < rows-1)
		{
			// check if next UP is 0, if not, do nothing
			if (map[p->getY() + 1][p->getX()] == 0)
			{
				map[p->getY() + 1][p->getX()] = p->getIcon();
				map[p->getY()][p->getX()] = 0;
				p->setY(p->getY() + 1);
			}
		}
		break;
	case 'E':
		// user interact with object
		interact();
		break;
	case 'I':
		// display inventory
		p->getInventory().displayInv();
		p->setStepCount(p->getStepCount() + 1);
		break;
	default:
		std::cout << "Invalid option." << std::endl;
	}
}

/*********************************************************************
** Room::traverseRoom
** Function that allows users to go to the next room when going
** through a door.
*********************************************************************/
int Room::traverseRoom()
{
	// go north room
	if (
		((p->getX() == ((cols / 2) - 1)) &&
		(p->getY() == 0)) ||
		((p->getX() == (cols / 2)) &&
		(p->getY() == 0))
		)
	{
		if (escape == true)
			return NA;
		if (dNorth.roomPtr != NULL)
		{
			map[p->getY()][p->getX()] = 0;
			p->setX(14);
			p->setY(14);
			currentRoom = dNorth.roomPtr;
			return NORTH;
		}
	}

	// go east room
	else if (
		(p->getX() == (cols - 1)) &&
		(p->getY() == (rows / 2))
		)
	{
		if (dEast.roomPtr != NULL)
		{
			map[p->getY()][p->getX()] = 0;
			p->setX(1);
			p->setY(7);
			currentRoom = dEast.roomPtr;
			return EAST;
		}
	}

	// go south room
	else if (
		((p->getX() == ((cols / 2) - 1)) && 
		(p->getY() == (rows - 1))) ||
		((p->getX() == (cols / 2)) && 
		(p->getY() == (rows - 1)))
			)
	{
		if (dSouth.roomPtr != NULL)
		{
			map[p->getY()][p->getX()] = 0;
			p->setX(14);
			p->setY(0);
			currentRoom = dSouth.roomPtr;
			return SOUTH;
		}
	}

	// go west room
	else if (
		(p->getX() == 0) && 
		(p->getY() == (rows / 2))
			)
	{
		if (dWest.roomPtr != NULL)
		{
			map[p->getY()][p->getX()] = 0;
			p->setX(28);
			p->setY(7);
			currentRoom = dWest.roomPtr;
			return WEST;
		}
	}

	else
		return NA;
	return 0;
}