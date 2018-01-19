/*********************************************************************
** Program name: zombie.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the zombie class.
*********************************************************************/
#include <iostream>
#include "zombie.hpp"

void Zombie::setZX(int x) { zX = x; }
void Zombie::setZY(int y) { zY = y; }
int Zombie::getZX() const { return zX; }
int Zombie::getZY() const { return zY; }
void Zombie::setArmor() { hasArmor = true; }
bool Zombie::getArmor() { return false; }
char Zombie::getZombie() { return icon; }

bool Zombie::zombieExist() { return isAlive; }