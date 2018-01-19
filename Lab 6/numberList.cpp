/*********************************************************************
** Program name: numberList.cpp for Lab6
** Author: Khoa Phan
** Date: May 14, 2017
** Description: This file contains the functions for the numberList
** class that manipulate the linked list through adding, removing
** or traversing the list.
*********************************************************************/

#include "numberList.hpp"
#include "validation.hpp"

using namespace std;

/*********************************************************************
** NumberList::~NumberList
** Destructor function that deallocates the entire list.
*********************************************************************/
NumberList::~NumberList()
{
	ListNode *nodePtr = head;
	while (nodePtr != nullptr)
	{
		// takes all nodes and deletes that node
		ListNode *garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}

/*********************************************************************
** NumberList::addHead
** Function that adds an integer to the head of the linked list.
*********************************************************************/
void NumberList::addHead()
{
	// prompt user enter info
	int number;
	cout << "Please enter a positive integer." << endl;
	number = checkInt();

	// add to empty list
	if (head == nullptr)
	{
		head = new ListNode(number);
		tail = head;
	}

	// add to list with existing information at head
	else
	{
		ListNode *nodePtr = new ListNode(number);
		nodePtr->next = nullptr;
		if (head == nullptr)
			head = nodePtr;
		else
		{
			nodePtr->next = head;
			head = nodePtr;
		}
	}
	displayList();
}

/*********************************************************************
** NumberList::addTail
** Function that adds an integer to the tail of the linked list.
*********************************************************************/
void NumberList::addTail()
{
	// prompt user enter info
	int number;
	cout << "Please enter a positive integer." << endl;
	number = checkInt();

	// add to empty list
	if (head == nullptr)
	{
		head = new ListNode(number);
		tail = head;
	}

	// add to list with existing information at tail
	else
	{
		ListNode *nodePtr = head;
		while (nodePtr->next != nullptr)
			nodePtr = nodePtr->next;

		nodePtr->next = new ListNode(number);
		tail = nodePtr->next;
	}

	displayList();
}

/*********************************************************************
** NumberList::removeHead
** Function that removes the integer at the head of the linked list.
*********************************************************************/
void NumberList::removeHead()
{
	ListNode *nodePtr;

	// move head to next and delete old head
	if (head)
	{
		nodePtr = head;
		head = head->next;
		delete nodePtr;
	}

	displayList();
}

/*********************************************************************
** NumberList::removeTail
** Function that removes the integer at the tail of the linked list.
*********************************************************************/
void NumberList::removeTail()
{
	ListNode *nodePtr;

	// if head is only value, delete head
	if (head->next == nullptr)
	{
		nodePtr = head;
		head = head->next;
		delete nodePtr;
	}

	// traverse list until last, then delete tail
	else
	{
		nodePtr = head;

		while (nodePtr->next != nullptr)
		{
			tail = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			tail->next = nullptr;
			delete nodePtr;
		}
	}

	displayList();
}

/*********************************************************************
** NumberList::displayList
** Function that displays the linked list.
*********************************************************************/
void NumberList::displayList() const
{

	if (head == nullptr)
		cout << "The list is empty." << endl;

	ListNode *nodePtr = head;
	cout << "\nYour linked list is: ";
	while (nodePtr)
	{
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	cout << endl << endl;
}

/*********************************************************************
** NumberList::reverseList
** Function that traverses the list in reverse.
*********************************************************************/
void NumberList::reverseList()
{
	ListNode *nodePtr = head;
	ListNode *prevNode = nullptr;
	ListNode *nextPtr = nullptr;

	// if there are no values
	if (head == nullptr || tail == nullptr)
		cout << "The list is empty." << endl;


	cout << "Your linked list is: ";

	// traverse list in reverse and set new head
	while (nodePtr != nullptr)
	{
		nextPtr = nodePtr->next;
		nodePtr->next = prevNode;
		prevNode = nodePtr;
		nodePtr = nextPtr;
	}
	head = prevNode;

	nodePtr = head;
	while (nodePtr)
	{
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}

	cout << endl << endl;
}

/*********************************************************************
** NumberList::dispHead
** Function that displays the head value
*********************************************************************/
void NumberList::dispHead()
{
	if (head == nullptr)
		cout << "There is no head value.\n" << endl;

	else
		cout << "Head value is: " << head->value << endl << endl;
}


/*********************************************************************
** NumberList::dispTail
** Function that displays the tail value
*********************************************************************/
void NumberList::dispTail()
{
	if (tail == nullptr)
		cout << "There is no tail value.\n" << endl;

	else
		cout << "Tail value is: " << tail->value << endl << endl;
}