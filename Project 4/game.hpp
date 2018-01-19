/*********************************************************************
** Program name: game.hpp for Project3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Header file for Game class
*********************************************************************/

#include <vector>
#include "creature.hpp"
#include "cQueue.hpp"
#include "cStack.hpp"

using namespace std;

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
private:
	struct Player {
		int position;
		int score = 0;
		cQueue a;

		void setPosition(POSITION p)
		{ position = p; }

		int getPosition() const
		{ return position; }
	};
	vector<Player*> p;
	cStack defeated;
	bool winRnd;
	bool win;
	int pWin;
	int numCreatures;
	int round = 1;
	bool normalFight;

public:
	~Game();
	void setPlayer();
	bool playGame();
	void displayUI();
	void displayRound();
	void playRound();
	bool gameStatus();
	void sendDefeated(string);
	bool winner();
protected:
};
#endif