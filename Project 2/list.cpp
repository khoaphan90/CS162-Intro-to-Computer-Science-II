/*********************************************************************
** Program name: list.cpp for Project 2
** Author: Khoa Phan
** Date: April 28, 2017
** Description: This is the list class that holds all the working 
** functions that create and modify the items located within the list.
*********************************************************************/

#include <iostream>
#include <iomanip>
#include "validation.hpp"
#include "list.hpp"
#include "item.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setprecision;
using std::fixed;
using std::operator==;

/*********************************************************************
** List::List
** Default constructor that creates the list of items.
*********************************************************************/
List::List()
{
	itemList = new Item[listSize]; 
	for (int i = 0; i < listSize; i++)
		itemList[i] = Item();
}


/*********************************************************************
** List::~List
** Destructor that deallocates the memory created from the list of
** items.
*********************************************************************/
List::~List()
{
	delete[] itemList;
}

/*********************************************************************
** List::List
** Function that adds a new item to the list of items. Will check for 
** duplicates and call the appropriate functions if needed.
*********************************************************************/
void List::addItem()
{
	// input variables
	string name, unit_type;
	double uAmount, p;
	int qAmount;

	bool duplicate = false;

	// checks if list size exceeds 4
	if (inList >= 4)
	{
		itemList = increaseList(itemList);
		inList++;
	}
	cout << "\nNew item. Please enter the following information\n\n";
	Item a;

	cout << "Enter the product name: ";
	getline(cin, name); //no need for validation type?
	a.setName(name);

	// checks new item names for duplicates
		duplicate = dupItem(a);

	if (duplicate == false)
	{
		cout << "Enter the unit amount: ";
		uAmount = checkDouble();

		cout << "Enter the unit type: ";
		getline(cin, unit_type);
		a.setUnit(uAmount, unit_type);

		cout << "Enter the amount of items: ";
		qAmount = checkInt();
		a.setQuantity(qAmount);

		cout << "Enter the price: ";
		p = checkDouble();
		a.setPrice(p);
	}

	// sets item to empty spot in list
	for (int i = 0; i < listSize;i++)
		if (itemList[i].getName() == " ")
		{
			itemList[i] = a;
			break;
		}
	inList++;
	hasItem = true;
}

/*********************************************************************
** List::dupItem
** Function that checks for duplicate items and as for update or 
** cancel.
*********************************************************************/
bool List::dupItem(Item &a)
{
	string name, unit_type;
	double uAmount, p;
	int qAmount, input;

	for (int i = 0; i < listSize; i++)
	{
		// Ask if item is to be updated or not
		if (itemList[i] == a)
		{
			cout << "This is am existing item on the list."
				<< " Would you like to update it?"
				<< "\n\n1. Update"
				<< "\n2. Cancel" << endl;
			input = checkInt();

			switch (input)
			{
			case 1:		//updates item
			removeItem(i);

				cout << "Enter the unit amount: ";
				uAmount = checkDouble();
				cout << "Enter the unit type: ";
				getline(cin, unit_type);
				a.setUnit(uAmount, unit_type);

				cout << "Enter the amount of items: ";
				qAmount = checkInt();
				a.setQuantity(qAmount);

				cout << "Enter the price: ";
				p = checkDouble();
				a.setPrice(p);
				removeDup(i);
				return true;
				break;
			case 2:		//cancels add item
				a.setUnit(itemList[i].getUnitAmount(),
					itemList[i].getUnitType());
				a.setQuantity(itemList[i].getQuantity());
				a.setPrice(itemList[i].getPrice());
				removeDup(i);
				return true;
				break;
			default:
				cout << "Invalid option." << endl;
				break;
			}
		}
	}
	return false;
}

/*********************************************************************
** List::removeItem
** Function that removes item from the list.
*********************************************************************/
void List::removeItem(int s)
{
	cout << inList << endl;
	int remove = 0;
	for (int i = 0; i < listSize; i++)
		if (i == (s - 1))
			remove = i;

	Item *newList = new Item[listSize];
	for (int j = 0; j < remove; j++)
		newList[j] = itemList[j];
	for (int k = remove + 1; k < listSize; k++)
		newList[k - 1] = itemList[k];

	delete[] itemList;
	itemList = newList;
	if (listSize > 4)
		listSize--;
}

/*********************************************************************
** List::removeDup
** Function that removes duplicate entries.
*********************************************************************/
void List::removeDup(int s)
{
	Item *newList = new Item[listSize];
	for (int j = 0; j < s; j++)
		newList[j] = itemList[j];
	for (int k = s + 1; k < listSize; k++)
		newList[k - 1] = itemList[k];

	delete[] itemList;
	itemList = newList;
}

/*********************************************************************
** List::displayList
** Function that displays all items in the list.
*********************************************************************/
void List::displayList()
{
	for (int i = 0; i < listSize; i++)
	{
		if (itemList[i].getName() != " ")
			itemList[i].printItem();
		cout << endl;
	}
	displayTotal();
}

/*********************************************************************
** List::itemListMenu
** Function that displays a list of items to be chosen from.
*********************************************************************/
bool List::itemListMenu()
{
	if (hasItem == true)
	{
		for (int i = 0; i < listSize; i++)
			if (itemList[i].getName() != " ")
				cout << i + 1 << ". " << itemList[i].getName() << endl;
		return true;
	}
	else
	{
		cout << "\nThere are no items.\n" << endl;
		return false;
	}
}

/*********************************************************************
** List::displayItem
** Function that displays the item's information.
*********************************************************************/
void List::displayItem(int item)
{
	itemList[item-1].printItem();
}

/*********************************************************************
** List::increaseList
** Function that increases array size of the itemList
*********************************************************************/
Item* List::increaseList(Item *iList)
{
	Item *newList = new Item[listSize + 1];
	for (int i = 0; i < listSize; i++)
		newList[i] = iList[i];
	delete[] iList;
	listSize++;
	return newList;
}

/*********************************************************************
** List::displayTotal
** Function that displays the total price of items in the list.
*********************************************************************/
void List::displayTotal()
{
	double total = 0.0;
	for (int i = 0; i < listSize; i++)
		total += itemList[i].getPrice() * itemList[i].getQuantity();
	cout << "List Total: $" << setprecision(2) << fixed << total << endl << endl;
}