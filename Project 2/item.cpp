/*********************************************************************
** Program name: item.cpp for Project 2
** Author: Khoa Phan
** Date: April 28, 2017
** Description: This is the item class, used to hold the variables of
** the items that will be access through the List class.
*********************************************************************/

#include <iostream>
#include <iomanip>
#include "item.hpp"
#include "validation.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::fixed;
using std::setprecision;

Item::Item()
{
	itemName = " ";
	unitAmount = 0.0;
	unitType = " ";
	quantity = 0;
	price = 0.0;
}

/*********************************************************************
** Item::setName
** Function that sets the name as the input parameter.
*********************************************************************/
void Item::setName(string name)
{
	itemName = name;
}


/*********************************************************************
** Item::setUnit
** Function that sets the unit amount and type as the input parameters.
*********************************************************************/
void Item::setUnit(double uAmount, string unit_type)
{
	unitAmount = uAmount;
	unitType = unit_type;
}


/*********************************************************************
** Item::setQuantity
** Function that sets the quantity as the input parameter.
*********************************************************************/
void Item::setQuantity(int qAmount)
{
	quantity = qAmount; 
}


/*********************************************************************
** Item::setPrice
** Function that sets the price as the input parameter.
*********************************************************************/
void Item::setPrice(double p)
{
	price = p;
}


/*********************************************************************
** Item::getName
** Function that retrieves the name variable.
*********************************************************************/
string Item::getName() const
{
	return itemName;
}

/*********************************************************************
** Item::getUnitAmount
** Function that retrieves the unit amount variable.
*********************************************************************/
double Item::getUnitAmount() const
{
	return unitAmount;
}

/*********************************************************************
** Item::getUnitType
** Function that retrieves the unit type variable.
*********************************************************************/
string Item::getUnitType() const
{
	return unitType;
}

/*********************************************************************
** Item::getQuantity
** Function that retrieves the quantity variable.
*********************************************************************/
int Item::getQuantity() const
{
	return quantity;
}

/*********************************************************************
** Item::getPrice
** Function that retrieves the price variable.
*********************************************************************/
double Item::getPrice() const
{
	return price;
}

/*********************************************************************
** Item::getUnitAmount
** Function that prints out all the information of the item.
*********************************************************************/
void Item::printItem()
{
	cout << "\nName:		" << getName() << endl;
	cout << "Unit:		" << getUnitAmount() 
		<< " " << getUnitType() << endl; //display type of units it is
	cout << "Quantity:	" << getQuantity() << endl;
	cout << "Price Per Unit:	" << getPrice() << endl;
	cout << "Price Total:	" << setprecision(2) << fixed 
		<< price*quantity << endl;
}

/*********************************************************************
** Item::operator==
** Function that overrides == operator to allow it to compare
** the names of two items.
*********************************************************************/
bool Item::operator==(const Item &a) const
{
	return (this->getName() == a.getName());
}