/*********************************************************************
** Program name: die.hpp for Lab 3
** Author: Khoa Phan
** Date: April 18, 2017
** Description: Header file for die.cpp
*********************************************************************/


#ifndef DIE_HPP
#define DIE_HPP

class Die
{
private:
protected:
	int sides;
	int *value = NULL;
	int result;
public:
	Die(int);
	~Die();
	int roll();
};
#endif // !DIE_HPP
