/*********************************************************************
** Program name: queue.cpp for Lab6
** Author: Khoa Phan
** Date: May 14, 2017
** Description: This file contains the functions that manipulate and 
** manage the queue for the Queue class.
*********************************************************************/

#include <iostream>
#include "queue.hpp"
#include "validation.hpp"

using std::cout;
using std::endl;

/*********************************************************************
** Queue::Queue
** Default constructor that sets the front and back nodes to nullptr
*********************************************************************/

Queue::Queue()
{
	front = nullptr;
	back = nullptr;
}

/*********************************************************************
** Queue::~Queue
** Destructor function that deallocates the entire list.
*********************************************************************/
Queue::~Queue()
{
	QueueNode *nodePtr = front;
	while (nodePtr != nullptr)
	{
		// takes all nodes and deletes that node
		QueueNode *garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}

/*********************************************************************
** Queue::addBack
** Function that adds integer to the back of the queue.
*********************************************************************/
void Queue::addBack(int n)
{
	QueueNode *node, *temp;
	if (isEmpty())
	{
		temp = new QueueNode(n);
		temp->prev = nullptr;
		front = temp;
		
		cout << "Added " << n << " to the list." << endl;
	}

	// adds value to the back of the queue
	else
	{
		node = new QueueNode(n);
		temp = front;
		// go to last in queue and set new node as back
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = node;
		node->prev = temp;
		back = node;
	
		cout << "Added " << n << " to the list." << endl;
	}
}

/*********************************************************************
** Queue::getFront
** Function that returns value of integer at the front of the queue.
*********************************************************************/
void Queue::getFront() const
{
	if (isEmpty())
		cout << "Queue is empty." << endl;

	// print out front of the queue
	else
	{
		QueueNode *node = front;
		cout << "Front of queue: " << node->value << endl;
	}
}

/*********************************************************************
** Queue::removeFront
** Function that removes the front value from the queue and moves
** the node to the new front.
*********************************************************************/
void Queue::removeFront()
{
	QueueNode *node;

	if (isEmpty())
		cout << "Queue is empty." << endl;
	
	// remove front value and reassign front to the next value
	else
	{
		if (front->next != nullptr);
		{
			node = front;
			front = front->next;
			cout << "Removed " << node->value 
				<< " to the list." << endl;
			delete node;
		}
	}
}

/*********************************************************************
** Queue::displayContents
** Function that displays contents of the queue.
*********************************************************************/
void Queue::displayContents() const
{
	// Check to see if empty
	if (isEmpty())
		cout << "The list is empty." << endl;

	// If contents are there, display the queue
	QueueNode *node = front;
	cout << "\nQueue: ";
	while (node)
	{
		cout << node->value << " ";
		node = node->next;
	}
	cout << endl << endl;
}

/*********************************************************************
** Queue::isEmpty
** Function that checks if queue is empty
*********************************************************************/
bool Queue::isEmpty() const
{
	// check to see if front value exist
	if (front == nullptr)
		return true;
	else
		return false;
}