/*********************************************************************
** Program name: player.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the player class.
*********************************************************************/
#include <iostream>
#include "player.hpp"
#include "validation.hpp"

/*********************************************************************
** ArrowRoom::addInventory
** Default constructor that pushes item into inventory.
*********************************************************************/
void Player::addInventory(Items *i)
{
	inv.setItem(i);
}

/*********************************************************************
** ArrowRoom::fatigue
** Function that reduces energy for every move.
*********************************************************************/
void Player::fatigue() 
{ 
	energy--; 
}

Inventory Player::getInventory() const { return inv; }
void Player::setEscape(bool e) { hasEscaped = e; }
bool Player::getEscape() const { return hasEscaped; }
void Player::setY(int ycoord) { y = ycoord; }
void Player::setX(int xcoord) { x = xcoord; }
int Player::getY() const { return y; }
int Player::getX() const { return x; }
char Player::getIcon() { return icon; }
void Player::setStepCount(int c) { energy = c; }
int Player::getStepCount() const { return energy; }
