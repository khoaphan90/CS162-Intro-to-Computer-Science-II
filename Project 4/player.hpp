/*********************************************************************
** Program name: player.hpp for Project3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Header file for Player class
*********************************************************************/

#include <vector>
#include "creature.hpp"

using namespace std;

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
private:
	vector<Creature*> c;
public:
	void setCreature(Creature*);
protected:
};
#endif