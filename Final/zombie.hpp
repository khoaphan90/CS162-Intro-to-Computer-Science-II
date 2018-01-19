/********************************************************************
** Program name : zombie.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for zombie.cpp
*********************************************************************/
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie
{
protected:
	bool isAlive = true;
	bool hasArmor;
	char icon = 'Z';
	int zX;
	int zY;

public:
	Zombie();
	void setZX(int);
	void setZY(int);
	int getZX() const;
	int getZY() const;
	char getIcon() { return icon; }
	void setArmor();
	bool getArmor();
	char getZombie();
	bool zombieExist();
	void attack();
	void wander();
	void run();
};
#endif
