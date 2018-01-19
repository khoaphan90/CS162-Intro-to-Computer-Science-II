#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "validation.hpp"
#include "room.hpp"
#include "player.hpp"
#include "powerRoom.hpp"
#include "startRoom.hpp"
#include "arrowRoom.hpp"
#include "spikeRoom.hpp"
#include "zombieRoom.hpp"
#include "wallRoom.hpp"

void clear();

int main()
{	
	srand(time(NULL));
	bool start = false;
	bool game = true;
	int selection;

	clear();
	std::cout << "Welcome to the Mysterious House!\n\n";
	std::cin.ignore();
	clear();
	while (start == false)
	{
		std::cout << "Please enter an option:\n";
		std::cout << "1. Read rules and manual\n";
		std::cout << "2. Start game\n\n";
		std::cout << "Choice: ";
		selection = checkInt();

		switch (selection)
		{
		case 1:
			std::cout << "The goal of this game is escape the rooms.\n"
				<< "Every room has something that must be solved,\n"
				<< "whether it's collecting an item or using \n"
				<< "those items. Be aware, you can take damage\n"
				<< "from running into traps or getting hit by\n"
				<< "the enemy. For every move, you lose 1 energy.\n"
				<< "This includes interaction. You may also input\n"
				<< "multiple commands in sequence, ie: dddd will\n"
				<< "will move you 4 spaces.\n\n\n";
			break;
		case 2: 
			start = true;
			break;
		default:
			std::cout << "Enter a valid option.\n\n";
		}
	}
	clear();


	std::cout << "You have woken up in a mysteriously dim room...\n";
	std::cout << "Now you must find your way out.\n";
	std::cin.ignore();
	clear();

	Player* player = new Player;
	Room *currentR;
	Room *startRoom = new StartRoom(player);
	Room *powerRoom = new PowerRoom(player);
	Room *arrowRoom = new ArrowRoom(player);
	Room *spikeRoom = new SpikeRoom(player);
	Room *zombieRoom = new ZombieRoom(player);
	Room *wallRoom = new WallRoom(player);
	startRoom->setConnectedRooms(zombieRoom, arrowRoom, powerRoom, spikeRoom);
	powerRoom->setConnectedRooms(startRoom, NULL, NULL, NULL);
	arrowRoom->setConnectedRooms(NULL, NULL, NULL, startRoom);
	spikeRoom->setConnectedRooms(NULL, startRoom, NULL, NULL);
	zombieRoom->setConnectedRooms(wallRoom, NULL, startRoom, NULL);
	
	currentR = startRoom;
	currentR->setRoom(startRoom);

	while (game == true)
	{
		std::cout << "	 Energy: [" << player->getStepCount() << "]" << std::endl;
		currentR->printRoom();
		std::cout << "         --Controls--" << std::endl;
		std::cout << "\nMove:\n	  [w]=Up\n [a]=Left [s]=Down [d]=Right\n";
		std::cout << " [e]=Interact  [i]=Inventory\n\n";
		std::cout << "Choice: ";
		currentR->control();
		currentR->action();
		player->fatigue();

		// get directional room
		int doorEntry = currentR->traverseRoom();
		if (doorEntry == NORTH || doorEntry == EAST ||
			doorEntry == SOUTH || doorEntry == WEST)
		{
			currentR = currentR->getRoom();
			currentR->setRoom(currentR);
		}

		/*std::cout << "CurrentRoom: " << currentR->getRoom() << std::endl;
		std::cout << "StartRoom: " << startRoom << std::endl;
		std::cout << "ArrowRoom: " << arrowRoom << std::endl;
		std::cout << "PowerRoom: " << powerRoom << std::endl;
		std::cout << "SpikeRoom: " << spikeRoom << std::endl;
		std::cout << "ZombieRoom: " << zombieRoom << std::endl;*/

		if (player->getStepCount() <= 0)
		{
			clear();
			std::cout << "You energy has been depleted and are forever stuck "
				<< "in this house...\n" << std::endl;
			break;
		}
		if (player->getEscape() == true)
		{
			clear();
			std::cout << "YOU HAVE SUCESSFULLY ESCAPED!"
				<< "\nKeep running and never look back..." << std::endl;
			break;
		}	
	}
	std::cin.ignore();
	std::cout << "Thank you for playing Mysterious House." << std::endl;

	delete player;
	delete startRoom;
	delete powerRoom;
	delete arrowRoom;
	delete spikeRoom;
	delete zombieRoom;
	delete wallRoom;

	return 0;
}

void clear()
{
	for (int j = 0; j < 500; j++)
		std::cout << std::endl;
}