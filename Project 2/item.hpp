/*********************************************************************
** Program name: item.hpp for Project 2
** Author: Khoa Phan
** Date: April 28, 2017
** Description: This is the header file for the item class.
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using std::string;

class Item
{
private:
	string itemName;
	double unitAmount; //can, box, lb, oz, etc, make menu to ask which
	string unitType;
	int quantity;
	double price; //validate float number
public:
	Item();
	void setName(string);
	void setUnit(double, string);
	void setQuantity(int);
	void setPrice(double);
	string getName() const;
	double getUnitAmount() const;
	string getUnitType() const;
	int getQuantity() const;
	double getPrice() const;
	void printItem();
	bool operator==(const Item &a) const;
protected:
};
#endif // !ITEM_HPP


