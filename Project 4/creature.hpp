/*********************************************************************
** Program name: creature.hpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Header file for abstract Creature class
*********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include "die.hpp"

using std::string;

enum TYPE { VAMPIRE, BARBARIAN, BLUE_MEN, MEDUSA, HARRY_POTTER, EMPTY };
enum POSITION { ATTACK, DEFEND };

class Creature
{
private:
public:
	virtual ~Creature();
	int getSP();
	void setName();
	string getName() const;
	virtual int fight(int, int);
	virtual int attack() = 0;
	virtual void defend(int) = 0;
	virtual void restore() = 0;
protected:
	string cType;
	string name;
	int cPos;
	int armor;
	int strPt;
	Creature *ptr;
};

#endif // CREATURE_HPP
