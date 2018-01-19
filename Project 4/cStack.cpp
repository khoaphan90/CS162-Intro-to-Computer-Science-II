/*********************************************************************
** Program name: cStack.cpp for Lab6
** Author: Khoa Phan
** Date: May 14, 2017
** Description: This file contains the functions for the cStack
** class that manipulate the linked list through adding, removing
** or traversing the list.
*********************************************************************/

#include <iostream>
#include "cStack.hpp"
#include "validation.hpp"

using namespace std;

/*********************************************************************
** cStack::~cStack
** Destructor function that deallocates the entire list.
*********************************************************************/
cStack::~cStack()
{

	ListNode *nodePtr = top;
	while (nodePtr != nullptr)
	{
		// takes all nodes and deletes that node
		ListNode *garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}

/*********************************************************************
** cStack::addTop
** Function that adds an creature to the head of the linked list.
*********************************************************************/
void cStack::addTop(string d)
{
	string name = d;
	// add to empty list
	if (top == nullptr)
		top = new ListNode(d);

	// add to list with existing information at head
	else
	{
		ListNode *nodePtr = new ListNode(d);
		nodePtr->next = nullptr;
		if (top == nullptr)
			top = nodePtr;
		else
		{
			nodePtr->next = top;
			top = nodePtr;
		}
	}
}

/*********************************************************************
** cStack::displayList
** Function that displays the linked list.
*********************************************************************/
void cStack::displayList() const
{
	ListNode *nodePtr = top;
	while (nodePtr)
	{
		cout << nodePtr->c << endl;
		nodePtr = nodePtr->next;
	}
	cout << endl << endl;
}
