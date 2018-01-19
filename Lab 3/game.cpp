/*********************************************************************
** Program name: game.cpp for Lab 3
** Author: Khoa Phan
** Date: April 18, 2017
** Description: Program written for the game functions for the dice
** game.
*********************************************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "validation.hpp"
#include "die.hpp"
#include "loadedDie.hpp"
#include "game.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

/*********************************************************************
** Game:Game
** Function that triggers other functions for the game.
*********************************************************************/
Game::Game()
{
	//sets random time used for die roll
	srand(time(NULL));
	setRounds();
	setDie();
	start();
}

/*********************************************************************
** Game:setDie
** Function that sets unique dies for the players.
*********************************************************************/
void Game::setDie() 
{

	for (int i = 0; i < nPlay; i++)
	{
		clearScreen();
		int input, side;

		// prompts user to select die type and # of sides
		cout << "Player " << i + 1 << " choose die type." << endl;
		cout << "1. Regular" << endl;
		cout << "2. Loaded" << endl;

		input = checkRange();
		player[i] = input;

		cout << "How many sides?";

		side = checkInput();
		sizeDie[i] = side;
	}
}

/*********************************************************************
** Game:setRounds
** Function that sets the number of rounds for the game.
*********************************************************************/
void Game::setRounds()
{
	int rNum;
	clearScreen();
	cout << "Enter the number of rounds you would like to play." << endl;
	cout << "Please choose an odd number." << endl;
	rNum = checkOdd();
	rounds = rNum;
}

/*********************************************************************
** Game:start
** Function that plays the sequence of the Dice game.
*********************************************************************/
void Game::start() 
{
	int roll;
	int rCount = 0;

	// loop to play rounds
	while (rCount < rounds)
	{
		clearScreen();
		displayScore();
		cout << endl;
		
		//display round count
		cout << "Round: " << rCount + 1;
		cin.ignore(20, '\n');

		//plays game based on dice type
		for (int i = 0; i < nPlay; i++)
		{
			// normal die
			if (player[i] == 1)
			{
				//c reate die
				Die* dice1 = NULL;
				dice1 = new Die(sizeDie[i]);
				dice[i] = dice1;

				roll = dice[i]->roll();
				rollResult[i] = roll;

				// delete die
				delete dice1;
				dice1 = NULL;

				cin.get();
			}

			// loaded die
			else if (player[i] == 2)
			{
				// create die
				Die* dice2 = NULL;
				dice2 = new LoadedDie(sizeDie[i]);
				dice[i] = dice2;

				roll = dice[i]->roll();
				rollResult[i] = roll;

				// delete die
				delete dice2;
				dice2 = NULL;

				cin.get();
			}
			cout << "Player " << i + 1 << " roll: " << roll << endl;
		}

		// checks for tie rounds
		if (rollResult[0] == rollResult[1])
		{
			cout << "Tie. Replaying round." << endl;
			cin.get();
		}

		// checks to see if player 1 has higher roll
		else if (rollResult[0] > rollResult[1])
		{
			score[0]++;
			cout << "Winner of round " << rCount + 1 << " is Player 1." << endl;
			rCount++;
			cin.get();
		}

		// checks to see if player 2 has higehr roll
		else if (rollResult[0] < rollResult[1])
		{
			cin.get();
			score[1]++;
			cout << "Winner of round " << rCount + 1 << " is Player 2." << endl;
			rCount++;
			cin.get();
		}
		
		// checks for winner
		for (int i = 0; i < nPlay; i++)
			if (score[i] == ((rounds / 2) + 1))
			{
				clearScreen();
				displayScore();
				cout << endl;
				cout << "Winner of this game is Player " << i + 1 << " !!!" << endl;
				rCount = rounds;
			}
		cin.get();
	}
}

/*********************************************************************
** Game:getScore
** Function that retrieves score for each player.
*********************************************************************/
int Game::getScore(int p)
{
	return score[p];
}

/*********************************************************************
** Game:displayScore
** Function that displays score on screen above the game field.
*********************************************************************/
void Game::displayScore()
{
	for (int i = 0; i < nPlay; i++)
		cout << "Player " << i + 1 << " score : " << score[i] << endl;
	for (int i = 0; i < 28; i++)
		cout << "-";
	cout << endl;
	cout << "(press ENTER between turns)" << endl;
}

/*********************************************************************
** Game:clearScreen
** Function that clears the screen
*********************************************************************/
void Game::clearScreen()
{
	cout << string(100, '\n');
}