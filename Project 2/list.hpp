/*********************************************************************
** Program name: list.hpp for Project 2
** Author: Khoa Phan
** Date: April 28, 2017
** Description: This is the header file for the list class.
*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include "item.hpp"

class List
{
private:
	int listSize = 4;
	int inList = 0;
	Item *itemList;
	bool hasItem = false;
public:
	List();
	~List();
	void addItem();
	void removeItem(int);
	void removeDup(int);
	bool dupItem(Item&);
	void displayList();
	bool itemListMenu();
	void displayItem(int);
	Item* increaseList(Item*);
	void displayTotal();
protected:
};
#endif // !LIST_HPP
