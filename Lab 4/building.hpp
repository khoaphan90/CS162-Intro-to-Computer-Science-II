/*********************************************************************
** Program name: building.hpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Header file for the Building class.
*********************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>

using namespace std;

class Building
{
private:
	string name;
	double bSize;
	string address;
public:
	Building();
	Building(string, double, string);
	void setName();
	void setSize();
	void setAddress();
	string getName() const;
	double getSize() const;
	string getAddress()	const;

protected:
};

#endif // ! BUILDING_HPP
