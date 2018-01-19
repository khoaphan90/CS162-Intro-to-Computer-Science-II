/*********************************************************************
** Program name: loadedDie.hpp for Lab 3
** Author: Khoa Phan
** Date: April 18, 2017
** Description: Header file for loadedDie.cpp
*********************************************************************/

#include "die.hpp"
#include <iostream>

using namespace std;

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

class LoadedDie : public Die {
public:
	LoadedDie(int);
};
#endif // LOADEDDIE_HPP