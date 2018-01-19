/*********************************************************************
** Program name: game.hpp for Project3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Header file for Game class
*********************************************************************/

#include <vector>
#include "creature.hpp"

using namespace std;

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
private:
	vector<Creature*> c;
	bool win = false;
	int pWin;
	int round = 1;
	bool normalFight;

public:
	void setPlayer();
	bool playGame();
	void displayUI();
	void playRound();
	bool gameStatus();
	void winner();

protected:
};
#endif