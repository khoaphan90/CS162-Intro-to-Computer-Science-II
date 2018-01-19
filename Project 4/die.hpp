/*********************************************************************
** Program name: die.hpp for Project3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: Header file for Die class.
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
